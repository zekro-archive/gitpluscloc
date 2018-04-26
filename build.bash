#!/bin/bash

if ! type g++ >/dev/null 2>&1
then
    echo "g++ is not installed or can not be accessed as command."
    exit -1
fi

echo "Building cgit..."
g++ gitpluscloc.cpp preferences.h -o cgit

echo "Installing cgit to '/usr/bin/cgit'..."
mv cgit /usr/bin/cgit

echo "Build and installation finished."
echo "You can now access gitpluscloc with 'cgit'."
echo "Every git command you can also use with 'cgit'."
echo "When you commit with 'cgit', it will automatically create a cloc file and pushing it into current branch."