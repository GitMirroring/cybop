#
# Copyright (C) 1999-2013. Christian Heller.
#
# This file specifies configuration settings.
# It has to be processed with autoconf to produce a configure script.
#
# Cybernetics Oriented Programming (CYBOP) <http://www.cybop.org/>
# CYBOP Developers <cybop-developers@nongnu.org>
#
# @version CYBOP 0.15.0 2013-09-22
# @author Didier Link <didier@famille-link.fr>
# @author Christian Heller <christian.heller@tuxtax.de>
# @author Tobias Köhler <tk@snake-universe.tk>
#

AC_PREREQ(2.61)
AC_INIT([cybop], [0.15.0], [christian.heller@tuxtax.de])
AC_CONFIG_SRCDIR([src/controller/cyboi.c])
AC_CONFIG_AUX_DIR([build-aux])
AM_INIT_AUTOMAKE([gnu dist-bzip2 tar-ustar])
#AC_CONFIG_HEADER([config.h])

AC_CANONICAL_HOST

AC_MSG_CHECKING([Host cpu])
AC_MSG_RESULT([$host_cpu])

AC_MSG_CHECKING([For operating system])
case $host_os in
    linux*)
	cybop_os_linux=yes
	AC_MSG_RESULT([Linux])
    ;;
    mingw*)
	cybop_os_win32=yes
	AC_MSG_RESULT([Win32])
    ;;
    darwin*)
	cybop_os_darwin=yes
	AC_MSG_RESULT([Darwin])
    ;;
esac

AM_CONDITIONAL(LINUX_OPERATING_SYSTEM, [test "$cybop_os_linux" = "yes"])
AM_CONDITIONAL(WIN32_OPERATING_SYSTEM, [test "$cybop_os_win32" = "yes"])
AM_CONDITIONAL(DARWIN_OPERATING_SYSTEM, [test "$cybop_os_darwin" = "yes"])

# Checks for programs.
AC_PROG_CC
AC_PROG_CPP
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_MAKE_SET

AC_PROG_LIBTOOL

#AC_PKG_PROG_PKG_CONFIG

# Checks for libraries.
AC_CHECK_LIB([GL], [glClear])
AC_CHECK_LIB([GLU], [main])
AC_CHECK_LIB([X11], [XOpenDisplay])
AC_CHECK_LIB([glut], [glutInit])
AC_CHECK_LIB([pthread], [pthread_exit])
AC_CHECK_LIB([xcb], [xcb_connect])

# Checks for header files.
AC_PATH_X
AC_HEADER_STDC
AC_HEADER_SYS_WAIT
AC_CHECK_HEADERS([arpa/inet.h fcntl.h locale.h netinet/in.h stddef.h stdlib.h string.h sys/socket.h termios.h unistd.h wchar.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_STDBOOL
AC_TYPE_SIZE_T
AC_STRUCT_TM
AC_TYPE_UINT16_T
AC_C_VOLATILE

# Checks for library functions.
AC_FUNC_CHOWN
AC_FUNC_MALLOC
AC_FUNC_REALLOC
AC_FUNC_STRTOD
AC_CHECK_FUNCS([memset setlocale socket strtol])

AC_CONFIG_FILES([Makefile
		 src/Makefile
		 src/controller/Makefile])
AC_OUTPUT
