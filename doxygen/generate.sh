#!/bin/bash
#
# Copyright (C) 1999-2015. Christian Heller.
#
# This shell script runs the "doxygen" tool.
#
# Cybernetics Oriented Programming (CYBOP) <http://www.cybop.org/>
# CYBOP Developers <cybop-developers@nongnu.org>
# 
# @version CYBOP 0.17.0 2015-04-20
# @author Christian Heller <christian.heller@tuxtax.de>
#

#
# CAUTION! This script HAS TO BE started WITHIN
# the directory "doxygen/"!
#

# Run application.
doxygen Doxyfile
