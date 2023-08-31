#!/bin/bash
#
# Copyright (C) 1999-2023. Christian Heller.
#
# This script adjusts the source code as follows:
# - replace tabulator characters with four spaces each
# - adapt year in copyright statement
# - adapt number and date in version
#
# Cybernetics Oriented Programming (CYBOP) <http://www.cybop.org/>
# CYBOP Developers <cybop-developers@nongnu.org>
#
# @version CYBOP 0.27.0 2023-08-31
# @author Christian Heller <christian.heller@cybop.org>
#

#
# The cybop root directory.
#
# CAUTION! This script is expected to be run from WITHIN the "build/" directory.
#
# Example:
#
# cd /home/xy/cybop/build
# scripts/adjust_copyright.sh
#
cybop=".."

#
# The input directories and files.
#
# CAUTION! Do NOT mention this file "adjust_copyright.sh" itself since
# otherwise, the tabulation character below will get replaced by spaces.
#
input="$cybop/build $cybop/include $cybop/src $cybop/todo $cybop/AUTHORS $cybop/ChangeLog $cybop/COPYING $cybop/INSTALL $cybop/NEWS $cybop/README"

#
# The filter using wild cards which get
# replaced, what is called "globbing".
# It is NOT using strict regular expressions.
#
c_filter="*.c"
h_filter="*.h"
cybol_filter="*.cybol"
authors_filter=AUTHORS
changelog_filter=ChangeLog
copying_filter=COPYING
install_filter=INSTALL
news_filter=NEWS
readme_filter=README

#
# The old and new tabulator string.
#
old_tabulator="	"
new_tabulator="    "

#
# The old and new copyright.
#
old_copyright="Copyright (C) 1999-2023. Christian Heller."
new_copyright="Copyright (C) 1999-2023. Christian Heller."

#
# The old and new version.
#
old_version="@version CYBOP 0.27.0 2023-08-31"
new_version="@version CYBOP 0.27.0 2023-08-31"

#
# Determine files.
#
# CAUTION! The files without suffix HAVE TO BE mentioned
# here since otherwise, they will not be processed.
#
files=$(find $input -type f -name "$c_filter" -or -name "$h_filter" -or -name "$cybol_filter" -or -name "$authors_filter" -or -name "$changelog_filter" -or -name "$copying_filter" -or -name "$install_filter" -or -name "$news_filter" -or -name "$readme_filter")

#
# Loop through files.
#
for file in $files
do

    #
    # TEST
    #
    # echo "$file"

    #
    # Use the "sed" stream editor tool.
    #
    # Editing commands are embraced by quotation marks or apostrophes.
    # Options are prefixed with a hyphen.
    #
    # Remarks:
    # - option -i causes files to be edited IN PLACE;
    #   without it, the replacement will NOT work
    # - editing command s searches AND replaces a string
    # - editing command g indicates that the ENTIRE LINE should
    #   be inspected instead of stopping at the first occurence
    #

    #
    # Replace tabulator string.
    #
    sed -i "s/$old_tabulator/$new_tabulator/g" $file

    #
    # Replace copyright.
    #
    sed -i "s/$old_copyright/$new_copyright/g" "$file"

    #
    # Replace version.
    #
    sed -i "s/$old_version/$new_version/g" "$file"
done

#
# Exit normally.
#
exit 0

