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
#include <glib.h>
#include <glib-object.h>
#include <db.h>
#include "bdb_operation.h"
#include "thbdb_errno.h"

GQuark
g_thbdb_error_quark (void)
{
  return g_quark_from_static_string ("g-thbdb-error-quark");
}



/**
 * A handle of the BDB.
 */
DB *dbp = NULL;

/**
 * Initializes the bdb that ThBDB contains.
 * This function is a sample implementation.
 */
u_int32_t init_bdb(){

  u_int32_t ret;   /* Return code from the BDB */
  
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

/**
 * Puts a pair of key/value on the BDB.
 */
u_int32_t put_on_bdb( char* key,int key_len, char* value, int value_len){

  u_int32_t ret = THBDB_NORMAL;
  DBT key_buf;        /* The key to dbp->put(). */
  DBT value_buf;      /* The data to dbp->put(). */

  /** Check the bdb handle */
  if (!dbp ) {
    return THBDB_DB_NOT_OPENED_ERROR;
  }

  /*           
   * Insert records into the database, where the key is the user input 
   * and the data is the user input in reverse order.
   * Zeroing the DBTs prepares them for the dbp->put() calls below. 
   */
  memset(&key_buf, 0, sizeof(DBT));
  memset(&value_buf, 0, sizeof(DBT));                                                                         
  key_buf.data = key;
  key_buf.size = (u_int32_t)key_len;
  value_buf.data = value;
  value_buf.size = (u_int32_t)value_len;

  /*     
   * Add the record to the database. The DB_NOOVERWRITE flag  
   * causes DB_KEYEXIST to be returned if the key had already
   * been put, either by a previous dbp->put() of this process,          
   * or because a prior execution of this program had inserted     
   * that key. Without DB_NOOVERWRITE, a dbp->put() of an already
   * existing key replaces the old record with the new one.
   */
  ret = dbp->put(dbp, NULL, &key_buf, &value_buf, DB_NOOVERWRITE); 
  if (ret != 0) {
    /*
     * Some kind of error was detected during the attempt to
     * insert the record. The err() function is printf-like.
     */
    dbp->err(dbp, ret, "DB(%s)->put(%s, %s)",
             PROGRAM_NAME, key, value);

    ret = THBDB_DB_KEYEXIST_ERROR;
  }

  return ret;

}

/**
 * Returns(status) TRUE if the specified key exists on BDB, False if it doesn't exists.
 */
u_int32_t exists_on_bdb( char* key,int key_len , int* status){

  u_int32_t ret;
  DBT key_buf;        /* The key to dbp->get(). */
  DBT value_buf;      /* The data to dbp->get(). */
  char* dummy = NULL;          /* dummy buffer for using get() function */
  
  /** Check the bdb handle */
  if (!dbp ) {
    return THBDB_DB_NOT_OPENED_ERROR;
  }

  /*           
   * Insert records into the database, where the key is the user input 
   * and the data is the user input in reverse order.
   * Zeroing the DBTs prepares them for the dbp->put() calls below. 
   */
  memset(&key_buf, 0, sizeof(DBT));
  memset(&value_buf, 0, sizeof(DBT));                                                                         
  key_buf.data = key;
  key_buf.size = (u_int32_t)key_len;
  value_buf.data = dummy;
  value_buf.size = (u_int32_t)sizeof(dummy);
  value_buf.flags = DB_DBT_MALLOC;

  /** Initializes status */
  *status = FALSE;

  /*     
   * Try to get a key/value item from the BDB. 
   */
  ret = dbp->get(dbp, NULL, &key_buf, &value_buf, 0);
  if ( ret == 0 ){
    *status = TRUE;
  }else if ( ret == DB_NOTFOUND ){
     /** Key/Value pair is not found in the BDB */
     /*  The DB_NOTFOUND is normal. */
    ret = 0;
  }else{
    /*
     * Some kind of error was detected during the attempt to
     * insert the record. The err() function is printf-like.
     */
    dbp->err(dbp, ret, "exists(%s)",
             PROGRAM_NAME, key);
  }

  /* Free the allocated dummy buffer. */
  if( value_buf.data != NULL )
    free( value_buf.data );
  
  return ret;

}

/**
 * Returns( value ) if  the specified key exists on BDB.
 */
u_int32_t get_from_bdb( char* key,int key_len , char** value){

  u_int32_t ret;
  DBT key_buf;        /* The key to dbp->get(). */
  DBT value_buf;      /* The data to dbp->get(). */
  char* dummy = NULL;          /* dummy buffer for using get() function */
  
  /** Check the bdb handle */
  if (!dbp ) {
    return THBDB_DB_NOT_OPENED_ERROR;
  }

  /*           
   * Insert records into the database, where the key is the user input 
   * and the data is the user input in reverse order.
   * Zeroing the DBTs prepares them for the dbp->put() calls below. 
   */
  memset(&key_buf, 0, sizeof(DBT));
  memset(&value_buf, 0, sizeof(DBT));                                                                         
  key_buf.data = key;
  key_buf.size = (u_int32_t)key_len;
  value_buf.data = dummy;
  value_buf.size = (u_int32_t)sizeof(dummy);
  value_buf.flags = DB_DBT_MALLOC;

  
  /*     
   * Try to get a key/value item from the BDB. 
   */
  ret = dbp->get(dbp, NULL, &key_buf, &value_buf, 0);
  if ( ret == 0 || ret == DB_NOTFOUND ){
     /** Key/Value pair is not found in the BDB */
     /*  The DB_NOTFOUND is normal. */
    ret = 0;
  }else{
    /*
     * Some kind of error was detected during the attempt to
     * insert the record. The err() function is printf-like.
     */
    dbp->err(dbp, ret, "get(%s)",
             PROGRAM_NAME, key);
  }

  if( value_buf.data != NULL ){
    *value = value_buf.data;
  }
  
  return ret;

}


/**
 * Closes internal bdb.
 *
 */
u_int32_t close_bdb(){

  if( !dbp )
    return THBDB_DB_NOT_OPENED_ERROR;
  
  /*
   * Close pthe database. Inside the close() call Berkeley DB flushes the
   * database cache out to the filesystem. The DB_NOSYNC option is ignored
   * in cases such as this one, which do not use an explicitly created       
   * environment (DB_ENV).                                                      
   */
  (void)dbp->close(dbp, 0);

  return THBDB_NORMAL;
}

