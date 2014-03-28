#!/bin/bash
#
# Copyright (C) 1999-2013. Christian Heller.
#
# This file adjusts the source code as follows:
# - Replace tabulator characters with four spaces each
# - Adapt copyright statement to given year
#
# Cybernetics Oriented Programming (CYBOP) <http://www.cybop.org/>
# CYBOP Developers <cybop-developers@nongnu.org>
#
# @version CYBOP 0.15.0 2013-09-22
# @author Christian Heller <christian.heller@tuxtax.de>
#

# The cybop root directory.
cybop=".."
# The input directories and files.
input="$cybop/examples $cybop/src $cybop/todo $cybop/AUTHORS $cybop/ChangeLog $cybop/COPYING $cybop/INSTALL $cybop/NEWS $cybop/README"
# The filter using wild cards which get
# replaced, what is called "globbing".
# It is NOT using strict regular expressions.
c_filter="*.c"
cybol_filter="*.cybol"
txt_filter="*.txt"
# The tabulator replaced string.
tabulator_replaced="	"
# The tabulator replacement string.
tabulator_replacement="    "
# The year replaced string.
year_replaced="Copyright (C) 1999-????. Christian Heller."
# The year replacement string.
prefix_year_replacement="Copyright (C) 1999-"
number_year_replacement=""
postfix_year_replacement=". Christian Heller."

# Test command line argument.
if [ -n "$1" ]; then
    # Set year.
    number_year_replacement=$1;
else
    echo "Error: A year has to be given as command line argument!";
    echo "Example: ./prepare_release.sh 2014";
    exit 1;
fi

# Determine year replacement.
# CAUTION! Do this only AFTER having read
# the command line argument above.
year_replacement=$prefix_year_replacement$number_year_replacement$postfix_year_replacement

# TEST
echo $year_replaced
echo $year_replacement

# Determine files.
files=$(find $input -type f -name "$c_filter" -or -name "$cybol_filter" -or -name "$txt_filter")

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

    # Replace tabulator characters with four spaces each.
    sed -i "s/$tabulator_replaced/$tabulator_replacement/g" $file

    # Adapt copyright year.
    sed -i "s/$year_replaced/$year_replacement/g" "$file"
done

# Exit normally.
exit 0
