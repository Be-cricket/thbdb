#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT(gen_c_glib, 0.1, , , 'https://github.com/tange0327/thbdb')
AM_INIT_AUTOMAKE
AC_CONFIG_SRCDIR([thbdb_basic.c])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC

# Checks for libraries.
AC_CHECK_LIB([glib-2.0], [main])
AC_CHECK_LIB([gobject-2.0], [main])
AC_CHECK_LIB([gmodule-2.0], [main])
AC_CHECK_LIB([gio-2.0], [main])
AC_CHECK_LIB([db], [main])

# Checks for header files.
AC_CHECK_HEADERS([string.h])
AC_CHECK_HEADERS([stdio.h],[AC_DEFINE(HAVE_STDIO_H)],[AC_MSG_ERROR([Sorry, can't do anything for you])])
AC_CHECK_HEADERS([string.h],[AC_DEFINE(HAVE_STRING_H)],[AC_MSG_ERROR([Sorry, can't do anything for you])])

PKG_PROG_PKG_CONFIG
PKG_CHECK_MODULES(GLIB, [glib-2.0])
AC_SUBST(GLIB_LIBS)

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
AC_CONFIG_MACRO_DIRS([m4])

LT_INIT()
AC_CONFIG_FILES([Makefile])
AC_OUTPUT
