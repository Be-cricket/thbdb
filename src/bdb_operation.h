/*
 * This file is a sample program.
 * Written by M.Yasaka on 6/17/2018
 *
 * bdb_operation.h
 * This file contains the bdb's initializing and finalizing operations for the bdb.
 */
#ifndef BDB_OPERATION_H
#define BDB_OPERATION_H

int initialize();

int bdb_open();

int bdb_close();

int bdb_unlink();


#define BDB_FILENAME "thbdb.db"  /* Default database filename */
#define PROGRAM_NAME "ThBDB"     /* The programe name used for error messages and ...  */

#endif /* BDB_OPERATION_H */
