PROGRAM = server
IDL_FILE = thbdb.thrift
IDL_OUT = gen-c_glib

SRCS = server.c handler.c gen-c_glib/thbdb_basic.c gen-c_glib/thbdb_thbdb_types.c
OBJS = $(SRCS:.c=.o)

THRIFT = thrift
THRIFT_FLAGS = --gen c_glib
CC = gcc
CFLAGS = -g -Wall -O2 -I/usr/local/Cellar/glib/2.56.1/include/glib-2.0/ -I/usr/local/Cellar/glib/2.56.1/lib/glib-2.0/include/ -I/usr/local/include
LDFLAGS = -L/usr/local/lib -lglib-2.0 -lgio-2.0 -lgmodule-2.0 -lgobject-2.0 -ldb -lthrift -lthrift_c_glib

.SUFFIXES: .c .o


# target
$(PROGRAM): $(OBJS)
	echo "link"
	$(CC) $(LDFLAGS) -o $(PROGRAM) $^

#IDL -> SRC
$(IDL_OUT): $(IDL_FILE)
	$(THRIFT) $(THRIFT_FLAGS) $<

# Suffixes Rule
%o:%c
	@echo "Compiling .c files."
	echo $<
	$(CC) $(CFLAGS) -c $< -o $@


# clean
.PHONY: clean idl
clean:
	$(RM) $(PROGRAM) $(OBJS)
	$(RM) *.o
#	$(RM) -R $(IDL_OUT)

# make test
maketest:
	@echo $(OBJS)

idl:
	$(RM) -R $(IDL_OUT)
	$(THRIFT) $(THRIFT_FLAGS) $(IDL_FILE)
