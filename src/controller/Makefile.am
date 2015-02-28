#
# Copyright (C) 1999-2014. Christian Heller.
#
# This file specifies directories and files to be considered in the build process.
#
# Cybernetics Oriented Programming (CYBOP) <http://www.cybop.org/>
# CYBOP Developers <cybop-developers@nongnu.org>
#
# @version CYBOP 0.16.0 2014-03-31
# @author Didier Link <didier@famille-link.fr>
# @author Christian Heller <christian.heller@tuxtax.de>
#

# CAUTION! Do NOT write directory names with a slash "/" at the end.
# If doing so, the directory names would be added twice,
# e.g. "cybop/examples/examples/" which is NOT wanted.
EXTRA_DIST = checker deoptionaliser globaliser handler manager optionaliser unglobaliser checker.c deoptionaliser.c globaliser.c handler.c helper.c informant.c initialiser.c Makefile.am manager.c optionaliser.c orienter.c tester.c unglobaliser.c

bin_PROGRAMS = cyboi

cyboi_SOURCES = cyboi.c

if LINUX_OPERATING_SYSTEM
    OS = -DGNU_LINUX_OPERATING_SYSTEM
endif

if WIN32_OPERATING_SYSTEM
    OS = -DWIN32_OPERATING_SYSTEM
endif

if DARWIN_OPERATING_SYSTEM
    OS = -DDARWIN_OPERATING_SYSTEM
endif

AM_CFLAGS = -I/usr/include $(OS)
