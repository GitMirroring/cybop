EXTRA_DIST = checker deoptionaliser globaliser handler manager optionaliser unglobaliser checker.c deoptionaliser.c globaliser.c handler.c helper.c informant.c initialiser.c manager.c optionaliser.c orienter.c tester.c unglobaliser.c

bin_PROGRAMS = cyboi

cyboi_SOURCES = cyboi.c

if LINUX_OPERATING_SYSTEM
    OS = -DGNU_LINUX_OPERATING_SYSTEM
endif

if WIN32_OPERATING_SYSTEM
    OS = -DWIN32_OPERATING_SYSTEM
endif

AM_CFLAGS = -I/usr/include $(OS)
