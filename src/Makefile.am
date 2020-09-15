SUBDIRS = gen_c_glib
bin_PROGRAMS = server
AUTOMAKE_OPTIONS = subdir-objects
AM_LDFLAGS = -L/usr/local/lib
server_SOURCES = server.c handler.c bdb_operation.c gen_c_glib/thbdb_basic.c gen_c_glib/thbdb_thbdb_types.c
server_OBJS = $(server_SOURCES:.c=.o)
ACLOCAL_AMFLAGS = -I m4
AM_CPPFLAGS = $(GLIB_CFLAGS)
