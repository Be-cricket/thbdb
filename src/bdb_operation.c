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

/**
 * Initializes the bdb that ThBDB contains.
 * This function is a sample implementation.
 */
int init(){

  DB *dbp;   /* Handle of the database */
  int ret;   /* Return code from the BDB */

  
  /* Create a database handle, to be configured, then opened. */
  if ((ret = db_create(&dbp, NULL, 0)) != 0) {
    fprintf(stderr,
            "%s: db_create: %s\n", PROGRAM_NAME, db_strerror(ret));
    return (EXIT_FAILURE);
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

  
  return 0;
}
