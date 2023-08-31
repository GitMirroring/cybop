
# Release Procedure

## Preparation

*Note: The following steps have to be executed MANUALLY*

1. Pull the latest changes for the python scripts with `cd build/scripts && git pull`
2. Change project version in `build/CMakeLists.txt` and execute ```make copyright``` which calls ```scripts/adjustCopyright.py```
# ALTERNATIVE: Execute shell script "build/adjust_copyright.sh" until one day python script does only change wanted directories (include not exclude approach)
3. Adapt directories and files in file `build/cmake/packaging.cmake`
4. Analyse source code by running `valgrind`
5. Change project version in `tools/api-generator/app.cybol` node `title` and `copyright`
6. Update files in directory `todo/`
7. Update ChangeLog
8. Update AUTHORS reading ChangeLog entries
9. Update NEWS subsumpting ChangeLog entries

## Source Code CYBOI Monolithic

1. Change into directory `buildx/`
2. Configure cmake by running (including the dot at the end) ```cmake .```
3. Delete old compilation files by running ```make clean```
4. Compile cyboix by running ```make cyboix``` which executes gcc

## Source Code CYBOI with Libraries

*The following steps can be executed together at once by running ```make dev```*

1. Change into directory `build/`
2. Configure cmake by running (including the dot at the end) ```cmake .```
3. Delete old compilation files by running ```make clean```
4. Compile cyboi by running ```make cyboi``` which executes gcc
5. Generate api by running ```make api``` which calls `tools/api-generator/run.cybol`

## Website

1. Create new file for release in www/website/development/plan/
2. Copy content from NEWS to www/website/development/plan/cybop-x.x.x.html
3. Update www/website/development/plan/index.html
4. Upload website changes to cybop.org

## Release

1. Commit to git MANUALLY
2. Tag release in git MANUALLY (see section "5.1 Tagging" in file "INSTALL")

## Distribution

1. Create distributable files by running ```make package``` which executes `CPack`
2. Copy packages to savannah MANUALLY (see section "5.2 Packing" in file "INSTALL")
3. Announce release in mailing list "cybop-developers@nongnu.org" MANUALLY

Desirable formats are:
* tar.gz source tarball file with corresponding GPG binary signature (see section "5.2 Packing" in file "INSTALL")
* deb package (see section "5.3 Debianising" in file "INSTALL")
* rpm package
* msi installer for Windows using NSIS tool
