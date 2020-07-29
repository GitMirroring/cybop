#!/bin/sh
#
# This shell script adjusts the version information of cybop files.
# It is run just before releasing a new version.
# To the replaced information belong:
# - copyright year
# - version and date
#
# CAUTION! Execute this script from within the dist/ directory,
# since the path settings rely on it.
#
# @author Christian Heller <christian.heller@tuxtax.de>
#

#
# Tool:
#
# - the "KFileReplace" tool does not exist in KDE anymore
# - using the text editor "Kate" menu entry "-> Edit -> Search in Files" (Hotkey: <ctrl> + <alt> + <f>) crashes Kate when hundreds of files are affected
# - the script "build/cmake/adjustcopyright.py" is called automatically within "make", but currently does NOT work
# - therefore, this new shell script "dist/adjust_version.sh" has been written and should be used from now on
#
# Options:
#
# find options:
# -type f - search for file, not directory
# -maxdepth level - process level subdirectories, e.g. -maxdepth 1 to disable recursion
# -o - means boolean OR
# -print0 - ensure the spaces in file and directory names are correctly handled; useful when input items might contain white space, quote marks, backslashes
#
# grep options:
# -R, -r, --recursive - recursive search
# -I - skip binary files, so that only text files are considered
# -l - --print-with-matches, prints the name of each file that has a match, instead of printing matching lines, needed for the other commands to follow
# -H - ensure that the filename is printed in all situations; by default, grep prints the filename only when multiple arguments are passed in
# CAUTION! If using shell variables, then set quotation marks
# not only in global variable, but ALSO around the grep variable
# containing the searched string.
#
# xargs options: (xargs transforms output to arguments for the following command)
# -0 - ensure the spaces in file and directory names are correctly handled; useful when input items might contain white space, quote marks, backslashes
#
# sed options:
# -i - alter the file directly "in place", without backup, remove this option for a kind of "dry run" mode without effect
# s - string type
# search - regular expression or search string
# replace - replacement string
# g - global, make the substitution for each match instead of only the first match
#
# Reference:
#
# https://www.tecmint.com/35-practical-examples-of-linux-find-command/
# https://www.tecmint.com/12-practical-examples-of-linux-grep-command/
# https://stackoverflow.com/questions/11392478/how-to-replace-a-string-in-multiple-files-in-linux-command-line/20721292
#

echo "Adjust version";

#
# Define global variables.
#

YEAR_OLD="Copyright (C) 1999-2018. Christian Heller.";
YEAR_NEW="Copyright (C) 1999-2020. Christian Heller.";
VERSION_OLD="CYBOP 0.20.0 2018-06-30";
VERSION_NEW="CYBOP 0.21.0 2020-07-29";

#
# CAUTION! Do NOT process directory "dist/",
# since it contains this shell script and the
# variables above would get changed erroneously.
#

#
# CAUTION! Do NOT process directory "examples/",
# since the contained cybol files do not have
# a comment with version information any longer.
#

#
# src/
#

find "../src" -type f \( -name "*.c" -o -name "*.txt" \) -print0 | xargs -0 grep -IlH "$YEAR_OLD" | xargs sed -i "s/$YEAR_OLD/$YEAR_NEW/g"
find "../src" -type f \( -name "*.c" -o -name "*.txt" \) -print0 | xargs -0 grep -IlH "$VERSION_OLD" | xargs sed -i "s/$VERSION_OLD/$VERSION_NEW/g"

#
# test/*.c
#

find "../test" -type f \( -name "*.c" \) -print0 | xargs -0 grep -IlH "$YEAR_OLD" | xargs sed -i "s/$YEAR_OLD/$YEAR_NEW/g"
find "../test" -type f \( -name "*.c" \) -print0 | xargs -0 grep -IlH "$VERSION_OLD" | xargs sed -i "s/$VERSION_OLD/$VERSION_NEW/g"

#
# todo/*.txt
#

find "../todo" -type f \( -name "*.txt" \) -print0 | xargs -0 grep -IlH "$YEAR_OLD" | xargs sed -i "s/$YEAR_OLD/$YEAR_NEW/g"
find "../todo" -type f \( -name "*.txt" \) -print0 | xargs -0 grep -IlH "$VERSION_OLD" | xargs sed -i "s/$VERSION_OLD/$VERSION_NEW/g"

#
# AUTHORS,ChangeLog,COPYING,INSTALL,NEWS,README
#
# CAUTION! Do NOT use recursive search here,
# since the files lie in the root directory and
# not all subdirectories are to be processed.
# Limit level of subdirectories to just 1 using option -maxdepth.
#

find ".." -maxdepth 1 -type f -print0 | xargs -0 grep -IlH "$YEAR_OLD" | xargs sed -i "s/$YEAR_OLD/$YEAR_NEW/g"
find ".." -maxdepth 1 -type f -print0 | xargs -0 grep -IlH "$VERSION_OLD" | xargs sed -i "s/$VERSION_OLD/$VERSION_NEW/g"

echo "Exit programme";
exit 0;

