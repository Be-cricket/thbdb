/*
 * ThBDB : The Berkeley DB with Thrift.
 * Written by masahi on 7/8/2018
 *
 * bdb_operation.c
 * This file contains the bdb's basic operations for the Berkeley DB (Hash mode KVS).
 */

#include <sys/types.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
//#include <glib.h>
//#include <glib-object.h>
#include <db.h>
#include "common.h"
#include "bdb_operation.h"
#include "thbdb_errno.h"

/**
 * A handle of the BDB. Caution !!! not MTS.
 */
DB *dbp = NULL;

/**
 * A handle of the BDB for cursor. Caution!!! not MTS.
 */
DBC *dbcp = NULL;


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
  *status = false;

  /*     
   * Try to get a key/value item from the BDB. 
   */
  ret = dbp->get(dbp, NULL, &key_buf, &value_buf, 0);
  if ( ret == 0 ){
    *status = true;
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
 * Returns the value to which the specified key is mapped  on BDB.
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
  if ( ret == 0 ){
    /* Nothing to do */
  }else if ( ret == DB_NOTFOUND ){
     /** Key/Value pair is not found in the BDB */
     /*  The DB_NOTFOUND is not error. */
    ret = THBDB_DB_NOTFOUND_ERROR;
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
 * Returns the value to which the specified key is mapped on BDB.
 * For unicode.
 */
u_int32_t get_from_bdb_unicode( char* key,int key_len , char** value, int *value_len ){

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
  if ( ret == 0 ){
    /* Nothing to do */
  }else if ( ret == DB_NOTFOUND ){
     /** Key/Value pair is not found in the BDB */
     /*  The DB_NOTFOUND is not error. */
    ret = THBDB_DB_NOTFOUND_ERROR;
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
    *value_len = (int) (value_buf.size);
  }
  
  return ret;
}


/**
 *
 * Remove a key/value pair from the internal bdb.
 *
 */
u_int32_t remove_from_bdb( char* key,int key_len ){

  u_int32_t ret;
  DBT key_buf;        /* The key to dbp->get(). */
  
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

  key_buf.data = key;
  key_buf.size = (u_int32_t)key_len;
    
  /*     
   * Try to delete a key/value item from the BDB. 
   */
  ret = dbp->del(dbp, NULL, &key_buf, 0);
  if ( ret == 0 ){
    /* Nothing to do */
  }else if ( ret == DB_NOTFOUND ){
     /** Key/Value pair is not found in the BDB */
     /*  The DB_NOTFOUND is not error. */
    ret = THBDB_DB_NOTFOUND_ERROR;
  }else{
    /*
     * Some kind of error was detected during the attempt to
     * insert the record. The err() function is printf-like.
     */
    dbp->err(dbp, ret, "del(%s)",
             PROGRAM_NAME, key);
  }

  return ret;

}



/**
 *
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

/**
 * Returns(status) TRUE if BDB is null, False if BDB isn't null.
 */
u_int32_t is_null_bdb( int* status ){

  u_int32_t ret = THBDB_NORMAL;  
  
  /** Initializes status */
  *status = true;

  /** Check the bdb is null */
  if ( !dbp ) {
    *status = true;
  } else {
    *status = false;
  }
  return ret;

}

/**
 * Returns TRUE if compact on success, False if compact on failure.
 * Returns(status) a non-zero error code on failure and 0 on success .
 */
u_int32_t compact_bdb( int* status ){

  /** Initializes status */
  *status = 0;

  /** Check the bdb handle */
  if (!dbp ) {
    return THBDB_DB_NOT_OPENED_ERROR;
  }
  /*     
   * Try to commact the BDB. 
   */
  *status = dbp->compact(dbp, NULL, NULL, NULL, NULL, DB_FREE_SPACE, NULL);

  if ( *status != 0 ){
    /*
     * Some kind of error was detected during the attempt to
     * compact the BDB. The err() function is printf-like.
     */
    dbp->err(dbp, *status, "compact" );
    return THBDB_DB_COMPACT_ERROR;
  }

  return THBDB_NORMAL;

}


/**
 * Open cursor.
 */
u_int32_t open_cursor(){
  u_int32_t ret;  

  /** Check the bdb cusor handle */
  if (!dbp ) {
    return THBDB_DB_NOT_OPENED_ERROR;
  }

  /*
   * Create the cursor to use to iterate over the records.
   */
  if ((ret = dbp->cursor(dbp, NULL, &dbcp, 0)) != 0) {
    dbp->err(dbp, ret, "%s: get_keys_from_bdb->DB->cursor", PROGRAM_NAME);
    return THBDB_DB_CURSOR_OPEN_ERROR;
  }

  return THBDB_NORMAL;
}


/**
 *
 * Closes internal bdb cursor.
 *
 */
u_int32_t close_cursor(){

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



/*----
  Add cursor controlling methods at 2/10/2019
  ----*/

/**
 * Open cursor for sequencial read on bdb. 
 */
u_int32_t init_bdb_cursor(){

  u_int32_t ret;  

  /** Check the bdb handle */
  if (!dbp ) {
    return THBDB_DB_NOT_OPENED_ERROR;
  }

  /** Check the bdb cursor handle */
  if ( dbcp ){
    return THBDB_DB_CURSOR_ALREADY_OPENED_ERROR;
  }
  
  /*
   * Create the cursor to use to iterate over the records.
   */
  if ((ret = dbp->cursor(dbp, NULL, &dbcp, 0)) != 0) {
    dbp->err(dbp, ret, "%s: init_bdb_cursor() ", PROGRAM_NAME);
    return THBDB_DB_CURSOR_OPEN_ERROR;
  }

  return ret;
  
}  

/**
 * Close the bdb cursor.
 * 
 */
u_int32_t close_bdb_cursor(){

  u_int32_t ret = 0;

  /** Check the bdb handle */
  if (!dbp ) {
    return THBDB_DB_NOT_OPENED_ERROR;
  }

  /* close cursor */
  if ( dbcp ){
    ret = dbcp->close(dbcp);
    dbcp = NULL;
  }
  return ret;
}

  

/**
 * Returns the key on BDB to which the cursor position is mapped.
 */
u_int32_t get_key_from_cursor(  char** key, int* key_len ){

  u_int32_t ret;
  DBT key_buf;        /* The key to dbcp->get(). */
  DBT value_buf;      /* The data to dbcp->get(). */
  //char* dummy = NULL;          /* dummy buffer for using get() function */
  
  /** Check the bdb handle */
  if (!dbp ) {
    return THBDB_DB_NOT_OPENED_ERROR;
  }
  if ( !dbcp ){
    return THBDB_DB_CURSOR_NOT_OPENED_ERROR;
  }

  memset(&key_buf, 0, sizeof(key_buf));
  memset(&value_buf, 0, sizeof(value_buf));                                                                         
  key_buf.flags = DB_DBT_MALLOC;
  value_buf.flags = DB_DBT_MALLOC;
  

  /*     
   * Try to get a key/value item from the BDB. 
   */
  ret = dbcp->get(dbcp, &key_buf, &value_buf, DB_NEXT);  
  if ( ret == 0 ){

    if( value_buf.data ){
      free( value_buf.data );
    }
    *key = key_buf.data;
    *key_len = key_buf.size;

  }else if ( ret == DB_NOTFOUND ){
     /** Key/Value pair is not found in the BDB */
     /*  The DB_NOTFOUND is not error. */
    ret = THBDB_DB_NOTFOUND_ERROR;
  }else{
    /*
     * Some kind of error was detected during the attempt to
     * insert the record. The err() function is printf-like.
     */
    dbp->err(dbp, ret, "get(%s)",
             PROGRAM_NAME, key);
  }

  return ret;

}
