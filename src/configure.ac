#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT(ThBDB, 0.1, , , 'https://github.com/tange0327/thbdb')
AM_INIT_AUTOMAKE
AC_CONFIG_SRCDIR([server.c])
AC_CONFIG_HEADERS([config.h])
LT_INIT()


# Checks for programs.
AC_PROG_CC

# Checks for libraries.
# FIXME: Replace `main' with a function in `-ldb':
AC_CHECK_LIB([db], [main], , [AC_MSG_ERROR(['db' is not found.])])
AC_CHECK_LIB([glib-2.0], [main], , [AC_MSG_ERROR(['glib-2.0' is not found.])])
AC_CHECK_LIB([gobject-2.0], [main], , [AC_MSG_ERROR(['gobject-2.0' is not found.])])
AC_CHECK_LIB([gmodule-2.0], [main], , [AC_MSG_ERROR(['gmodule-2.0' is not found.])])
AC_CHECK_LIB([gio-2.0], [main], , [AC_MSG_ERROR(['gio-2.0' is not found.])])
AC_CHECK_LIB([thrift_c_glib], [main], , [AC_MSG_ERROR(['thrift_c_glib' is not found.])])

# Checks for header files.
# AC_CHECK_HEADERS([stdlib.h string.h unistd.h], , [AC_MSG_ERROR([Sorry, can't do anything for you.])])
AC_CHECK_HEADERS([stdlib.h],[AC_DEFINE(HAVE_STDLIB_H)],[AC_MSG_ERROR(['stdlib.h' is not found.])])
AC_CHECK_HEADERS([string.h],[AC_DEFINE(HAVE_STRING_H)],[AC_MSG_ERROR(['string.h' is not found.])])
AC_CHECK_HEADERS([unistd.h],[AC_DEFINE(HAVE_UNISTD_H)],[AC_MSG_ERROR(['unistd.h' is not found.])])
AC_CHECK_HEADERS([stdio.h],[AC_DEFINE(HAVE_STDIO_H)],[AC_MSG_ERROR(['stdio.h' is not found.])])

PKG_PROG_PKG_CONFIG
PKG_CHECK_MODULES([GLIB], [glib-2.0])

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL

# Checks for library functions.
AC_CHECK_FUNCS([memset])

AC_CONFIG_MACRO_DIRS([m4])

AC_CONFIG_FILES([Makefile gen_c_glib/Makefile])
AC_OUTPUT
