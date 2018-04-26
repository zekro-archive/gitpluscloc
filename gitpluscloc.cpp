#include <iostream>
#include <fstream>
#include <stdexcept>
#include <stdio.h>
#include <string>
#include <algorithm>

using namespace std;

/*########### PREFERENCES ###########*/
#define CLOC_LOG_FILE "./CLOC_LOG.md"
#define CLOC_ARGUMENTS "--md"
/*###################################*/


#define VERSION "1.0"



void pause() {
    cin.clear();
    cin.get();
}


string exec(const char* cmd) {
    cout << "$ " << cmd << endl;
    char buffer[1024];
    string result = "";
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
    FILE* pipe = _popen(cmd, "r");
#else
    FILE* pipe = popen(cmd, "r");
#endif
    if (!pipe)
        throw runtime_error("_popen() failed");
    try {
        while (!feof(pipe)) {
            if (fgets(buffer, 1024, pipe) != NULL)
                result += buffer;
        }
    }
    catch (...) {
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
        _pclose(pipe);
#else
        pclose();
#endif
        throw;
    }
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
    _pclose(pipe);
#else
    pclose();
#endif
    return result;
}


bool cmd_option_exists(char** begin, char** end, const std::string& option) {
    return std::find(begin, end, option) != end;
}


void create_cloc() {
    cout << "Creating '" << CLOC_LOG_FILE << "' file...\n";
    string cloccmd = "cloc ./ ";
    cloccmd += CLOC_ARGUMENTS;
    string execout = exec(cloccmd.c_str());
    ofstream fw(CLOC_LOG_FILE);
    fw << execout;
    fw.close();
}


int main(int argc, char** argv) {

    if (cmd_option_exists(argv, argv + argc, "--help")) {
        cout << endl
             << "gitpluscloc (cgit) v." << VERSION << endl
             << "(c) 2018 Ringo Hoffmann (zekro Development)\n\n"
             << "This tool does just pass all arguments given through to git\n" 
             << "and extending commit with adding cloc document.\n";
        return 0;
    }

    string git_cmd = "git ";
    for (int i = 1; i < argc; i++) {
        string tmp = argv[i];
        if (tmp.find(" ", 0) < 4294967295) {
            git_cmd += "\"";
            git_cmd += argv[i];
            git_cmd += "\"";
        }
        else
            git_cmd += argv[i];
        git_cmd += " ";
    }
    
    if (cmd_option_exists(argv, argv + argc, "commit")) {
        create_cloc();
        string _cmd = "git add ";
        _cmd += CLOC_LOG_FILE;
        cout << exec(_cmd.c_str());
    }
    cout << exec(git_cmd.c_str());
}