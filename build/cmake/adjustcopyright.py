#!/usr/bin/python
import sys
import os
import fileinput
import re
import datetime

# argument handling
if len(sys.argv) != 3:
    print "you must set two arguments. [this file] [root dir] [version number]"
    exit

rootdir = sys.argv[1]
version = sys.argv[2]

# filters
fileExtensionFilter = ('.c', '.cybol', '.sh', '.txt')
fileFilter = ('AUTHORS', 'ChangeLog', 'COPYING', 'INSTALL', 'NEWS', 'README')

# today
today = datetime.date.today()

# tab definition
oldTab = "\t"
newTab = "    "
# copyright defintion
oldCopyright = r"Copyright \(C\) 1999-(\d+). Christian Heller."
newCopyright = "Copyright (C) 1999-" + today.strftime("%Y") + ". Christian Heller."
# version defintion
oldVersion = r"@version CYBOP (\d.+)"
newVersion = "@version CYBOP " + version + " " + today.strftime('%Y-%m-%d')

for subdir, dirs, files in os.walk(rootdir):
    for file in files:
        print (file)
        if file.lower().endswith(fileExtensionFilter) or file in fileFilter:
            filepath = subdir + os.sep + file
            for line in fileinput.input(filepath, inplace=True):
                line = line.replace(oldTab, newTab) # replace tab with spaces
                line = re.sub(oldCopyright, newCopyright, line) # replace to year in copyright
                line = re.sub(oldVersion, newVersion, line) # replace version and today date
                sys.stdout.write (line)