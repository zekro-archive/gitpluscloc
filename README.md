 <div align="center">
     <h1>~ gitpluscloc ~</h1>
     <strong>A rework of the original zekroBot in node.js</strong><br><br>
 </div>

---


If you want to reuse the code of this project, please read **[this](http://s.zekro.de/codepolicy)** before doing so!

Have some questions or want to join my developer community discord? Take a look! :^)
<br/><a href="http://discord.zekro.de"><img src="https://discordapp.com/api/guilds/307084334198816769/embed.png"/></a>

----

# First things First

**ATTENTION**  
This tool does not contain git or cloc. It just combines them! So you need to install both first before you can use this tool correctly!

👉 [**Git**](https://git-scm.com/downloads)  
> `$ sudo apt install git-all`

👉 [**Cloc**](https://github.com/AlDanial/cloc)  
> `$ sudo apt install cloc`

----

# Installation

If you are using linux, it's recommendet to clone the repository with
```
$ git clone https://github.com/zekroTJA/gitpluscloc
```
and then execute the `build.bash` script with
```
$ bash build.bash
```

On Windows, just compile the `gitpluscloc.cpp` with your favorite C++ compiller, put it somewhere you want and the set the PATH variable to use it globally.

----

# Usage

You can use every git command also with 'cgit', because the tool just passes the arguments directly to git. If you commit with 'cgit', it will automatically cloc in the current directory, creating a cloc file and adding it to the current branch. After, it will commit like git with the given arguments.

Example working path:
```
$ git add .
$ cgit commit -m "Added some stuff and fixed some bugs"
$ git push origin dev
```

# Preferences

In the `preferences.h` file, you can set the location and name of the cloc generated file and some arguments which will be executed with cloc.

> preferences.h
```cpp
// This will be the location and the file name of the generated file
#define CLOC_LOG_FILE "./CLOC_LOG.md"

// Here you can define some cloc command arguments
// Defaultly, the cloc output will be saved as markdown
// excluding Markdown, JSON and XML.
// For more info about arguments, use 'cloc --help'
#define CLOC_ARGUMENTS "--md --exclude-lang=md,json,xml"
```

----

© 2018 Ringo Hoffmann (zekro Development)  
Contact: contact[at]zekro.de
