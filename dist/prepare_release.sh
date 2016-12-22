#!/bin/bash
#
# Copyright (C) 1999-2016. Christian Heller.
#
# This file adjusts the source code as follows:
# - replace tabulator characters with four spaces each
# - adapt year in copyright statement
# - adapt number and date in version
#
# Cybernetics Oriented Programming (CYBOP) <http://www.cybop.org/>
# CYBOP Developers <cybop-developers@nongnu.org>
#
# @version CYBOP 0.18.0 2016-12-21
# @author Christian Heller <christian.heller@tuxtax.de>
#

# The cybop root directory.
cybop=".."
# The input directories and files.
# CAUTION! Do NOT replace this file "dist/prepare_release.sh"
# itself since otherwise, the tabulation character below
# will get replaced by spaces.
input="$cybop/dist/release.txt $cybop/examples $cybop/src $cybop/todo $cybop/AUTHORS $cybop/autogen.sh $cybop/ChangeLog $cybop/configure.ac $cybop/COPYING $cybop/INSTALL $cybop/Makefile.am $cybop/NEWS $cybop/README"
# The filter using wild cards which get
# replaced, what is called "globbing".
# It is NOT using strict regular expressions.
ac_filter="*.ac"
am_filter="*.am"
c_filter="*.c"
cybol_filter="*.cybol"
sh_filter="*.sh"
txt_filter="*.txt"
authors_filter=AUTHORS
changelog_filter=ChangeLog
copying_filter=COPYING
install_filter=INSTALL
news_filter=NEWS
readme_filter=README
# The old and new tabulator string.
old_tabulator="	"
new_tabulator="    "
# The old and new copyright.
old_copyright="Copyright (C) 1999-2015. Christian Heller."
new_copyright="Copyright (C) 1999-2016. Christian Heller."
# The old and new version.
old_version="CYBOP 0.17.0 2015-04-20"
new_version="CYBOP 0.18.0 2016-12-21"

# Determine files.
# CAUTION! The files without suffix HAVE TO BE
# mentioned here since otherwise, they will not
# be processed.
files=$(find $input -type f -name "$ac_filter" -or -name "$am_filter" -or -name "$c_filter" -or -name "$cybol_filter" -or -name "$sh_filter" -or -name "$txt_filter" -or -name "$authors_filter" -or -name "$changelog_filter" -or -name "$copying_filter" -or -name "$install_filter" -or -name "$news_filter" -or -name "$readme_filter")

# Loop through files.
for file in $files
do

    # TEST
#    echo "$file"

    #
    # Use the "sed" stream editor tool.
    #
    # Editing commands are embraced by quotation marks or apostrophes.
    # Options are prefixed with a hyphen.
    #
    # Remarks:
    # - option -i causes files to be edited in place
    #   without it, the replacement will not work
    # - editing command s searches and replaces a string
    # - editing command g indicates that the entire line should be
    #   inspected instead of stopping at the first occurence
    #

    # Replace tabulator string.
    sed -i "s/$old_tabulator/$new_tabulator/g" $file

    # Replace copyright.
    sed -i "s/$old_copyright/$new_copyright/g" "$file"

    # Replace version.
    sed -i "s/$old_version/$new_version/g" "$file"
done

# Exit normally.
exit 0
