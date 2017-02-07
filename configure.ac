AC_INIT([page-simulator], [0.1.0])
AM_INIT_AUTOMAKE([-Wall -Werror foreign subdir-objects])

AC_PROG_CC
AC_PROG_CXX
AM_PROG_AR

LT_INIT

AC_CONFIG_HEADERS([config.h])
AC_CONFIG_MACRO_DIR([m4])

AC_CONFIG_FILES([
    Makefile
    src/Makefile
    tests/Makefile
])

AX_CXX_COMPILE_STDCXX([11], [noext])
AX_BOOST_BASE([1.50.0])
AX_BOOST_UNIT_TEST_FRAMEWORK

AC_OUTPUT
