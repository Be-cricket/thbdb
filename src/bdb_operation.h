/*
 * This file is a sample program.
 * Written by M.Yasaka on 6/17/2018
 *
 * bdb_operation.h
 * This file contains the bdb's initializing and finalizing operations for the bdb.
 */
#ifndef BDB_OPERATION_H
#define BDB_OPERATION_H

/* for glib gerror */
GQuark
g_thbdb_error_quark (void);

/** for glib error proc */
#define G_THBDB_ERROR g_thbdb_error_quark() 

/** Following : Basic operations **/

int put_on_bdb( char* key, int key_len, char* value, int value_len);

char* get_from_bdb();

int remove_from_bdb( char* key );


/** Following : Control operations **/

int init_bdb();

int close_bdb();

int unlink_bdb();

#define PROGRAM_NAME   "ThBDB"       /* The programe name used for error messages and ...  */
#define BDB_FILENAME   "thbdb.db"    /* Default database filename */
#define BDB_PAGESIZE   1024          /* A database page size of 1024 bytes. It could be at most 64KB.*/
#define BDB_CACHESIZE_GB   0         /* A database cache size (GBs) in a single region. */
#define BDB_CACHESIZE_BYTE 32*1024   /* A database cache size (Bytes) in a single region. */




#endif /* BDB_OPERATION_H */
