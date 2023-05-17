
# Release Procedure

## Preparation

*Note: The following steps have to be executed MANUALLY*

1. Pull the latest changes for the python scripts with `cd build/scripts && git pull`
# TEMPORARY: Execute shell script "build/adjust_copyright.sh" until one day python script does only change wanted directories (include not exclude approach)
2. Change project version in `build/CMakeLists.txt` and execute ```make copyright```
3. Adapt directories and files in file `build/cmake/packaging.cmake`
4. Analyse source code by running `valgrind`
5. Change project version in `tools/api-generator/app.cybol` node `title` and `copyright`
6. Update files in directory `todo/`
7. Update ChangeLog
8. Update AUTHORS reading ChangeLog entries
9. Update NEWS subsumpting ChangeLog entries

## Source Code

*The following steps can be executed together at once by running ```make dev```*

1. Configure cmake by running (including the dot at the end) ```cmake .```
2. Delete old compilation files by running ```make clean```
3. Compile cyboi by running ```make cyboi``` which executes gcc
4. Generate api by running ```make api``` which executes the cybol api-generator

## Website

1. Create new file for release in www/website/development/plan/
2. Copy content from NEWS to www/website/development/plan/cybop-x.x.x.html
3. Update www/website/development/plan/index.html
4. Upload website changes

## Release

1. Commit to svn MANUALLY
2. Tag release in svn (see section "5.1 Tagging" in file "INSTALL") MANUALLY

## Distribution

1. Create distributable files by running ```make package``` which executes `CPack`
2. Copy packages to savannah MANUALLY (see section "5.2 Packing" in file "INSTALL")
3. Announce release in mailing list "cybop-developers@nongnu.org" MANUALLY

Desirable formats are:
* tar.gz source tarball file with corresponding GPG binary signature (see section "5.2 Packing" in file "INSTALL")
* deb package (see section "5.3 Debianising" in file "INSTALL")
* rpm package
* msi installer for Windows using NSIS tool
