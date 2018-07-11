/*
 * This file is a sample program.
 * Written by M.Yasaka on 7/8/2018
 *
 * bdb_operation.c
 * This file contains the bdb's initializing and finalizing operations for the bdb.
 */

#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <db.h>
#include "bdb_operation.h"
#include "thbdb_errno.h"


/**
 * A handle of the BDB.
 */
DB *dbp;

/**
 * Initializes the bdb that ThBDB contains.
 * This function is a sample implementation.
 */
int initializeBDB(){

  int ret;   /* Return code from the BDB */

  
  /* Create a database handle, to be configured, then opened. */
  if ((ret = db_create(&dbp, NULL, 0)) != 0) {
    fprintf(stderr,
            "%s: db_create: %s\n", PROGRAM_NAME, db_strerror(ret));
    return (THBDB_DB_OPEN_ERROR);
  }

  /*                           
   * Prefix any error messages with the name of this program and a ':'.
   * It's PROGRAM_NAME "ThBDB" as defined in bdb_operation.h file. 
   * Setting the errfile to stderr is not necessary, since that is 
   * default; it is provided here as a placeholder showing where one
   * could direct error messages to an application-specific log file. 
   */
  dbp->set_errpfx(dbp, PROGRAM_NAME);
  dbp->set_errfile(dbp, stderr);

  /*
   * Configure the database to use:
   *  A database page size of 1024 bytes. It could be at most 64KB.   
   *  A database cache size of 0 GB and 32KB, in a single region.
   */
  if ((ret = dbp->set_pagesize(dbp, BDB_PAGESIZE)) != 0) {
    dbp->err(dbp, ret, "set_pagesize");
    goto err_close_db;
  }
  if ((ret = dbp->set_cachesize(dbp, BDB_CACHESIZE_GB, BDB_CACHESIZE_BYTE, 1)) != 0) {
    dbp->err(dbp, ret, "set_cachesize");
    goto err_close_db;
  }

   /* 
    * Now open the configured handle. The DB_HASH specifies that it
    * it will be a hash_index mode. You could experiment by changing that to DB_BTREE 
    * in order to see how the behavior changes.
    */
    if ((ret = dbp->open(dbp,
        NULL, PROGRAM_NAME
                         , NULL, DB_HASH, DB_CREATE, 0664)) != 0) {
        dbp->err(dbp, ret, "%s: open",PROGRAM_NAME );
        goto err_close_db;
    }

  
  return THBDB_NORMAL;
       
 err_close_db:
  /*
   * Close the database. Inside the close() call Berkeley DB flushes the
   * database cache out to the filesystem. The DB_NOSYNC option is ignored
   * in cases such as this one, which do not use an explicitly created       
   * environment (DB_ENV).                                                      
   */
  (void)dbp->close(dbp, 0);
  return (THBDB_DB_OPEN_ERROR);
}
