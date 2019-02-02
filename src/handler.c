/*
 * handler.c
 * Handling the basic operation for the bdb.
 *
 * Written by M.Yasaka on 6/17/2018
 */

#include <signal.h>
#include <stdio.h>
#include <string.h>

#include <glib-object.h>

#include <thrift/c_glib/thrift.h>
#include <thrift/c_glib/protocol/thrift_binary_protocol_factory.h>
#include <thrift/c_glib/protocol/thrift_protocol_factory.h>
#include <thrift/c_glib/server/thrift_server.h>
#include <thrift/c_glib/server/thrift_simple_server.h>
#include <thrift/c_glib/transport/thrift_buffered_transport_factory.h>
#include <thrift/c_glib/transport/thrift_server_socket.h>
#include <thrift/c_glib/transport/thrift_server_transport.h>

#include "gen-c_glib/thbdb_basic.h"
#include "gen-c_glib/thbdb_thbdb_types.h"
#include "thbdb_errno.h"
#include "bdb_operation.h"
#include "handler.h"


/* ------------------------------------------------------------------------------------- */
/*                 The implementation of ThbdbBasicimplHandler follows.                  */
/* -----------------------------  API Handlers (START)---------------------------------- */

G_DEFINE_TYPE (ThbdbBasicimplHandler,
               thbdb_basicimpl_handler,
               THBDB_TYPE_BASIC_HANDLER)

/* Each of a handler's methods accepts at least two parameters: A
   pointer to the service-interface implementation (the handler object
   itself) and a handle to a GError structure to receive information
   about any error that occurs.

   On success, a handler method returns TRUE. A return value of FALSE
   indicates an error occurred and the error parameter has been
   set. (Methods should not return FALSE without first setting the
   error parameter.) */

/**
 *
 * A sample implementation.
 * "Hello" api.
 * 
 */
static gboolean
thbdb_basicimpl_handler_hello(thbdbBasicIf * iface, gchar ** _return, const gchar * arg, GError ** error)
{
  THRIFT_UNUSED_VAR (iface);
  THRIFT_UNUSED_VAR (error);

  //@@@
  puts (" ^^ hello() ^^");
   
  GString *retValue;
  retValue = g_string_new( "" );
  g_string_printf( retValue ,"Server received: %s \n" , arg );
  puts( retValue->str );
  
  *_return = retValue->str;
  
  return TRUE;
}


/**
 * Puts on the internal BDB.
 * NOOVERWRITE mode:
 * An error will be occered if the specified key is already existing.
 */
static gboolean
thbdb_basicimpl_handler_put (thbdbBasicIf * iface, const gchar * key, const gchar * value, thbdbInvalidOperation ** exp, GError ** error)
{

  int ret = THBDB_NORMAL;
  GString* gkey;
  GString* gvalue;
  int returnValue = TRUE;
  
  THRIFT_UNUSED_VAR (iface);
  THRIFT_UNUSED_VAR (error);
  g_return_val_if_fail (THBDB_IS_BASIC_HANDLER (iface), FALSE);

  //@@@
  puts (" ^^ put() ^^");
  gkey = g_string_new( key ); 
  gvalue = g_string_new( value ); 

  ret = put_on_bdb( 
                   gkey->str,
                   gkey->len,
                   gvalue->str,
                   gvalue->len);
  if( ret ){
    g_set_error(
                error,
                G_THBDB_ERROR,
                ret,
                "An error is occered under putting on the BDB. CODE=(%d)",
                ret
                );
    
    returnValue = FALSE;
  }

  /* Free memory(gstring)  */
  if( gkey )
    g_string_free( gkey,FALSE );
  if( gvalue )
    g_string_free( gvalue,FALSE );
  
  return returnValue;
  
}

/**
 * Check if the specified key exists 
 *
 */
gboolean thbdb_basicimpl_handler_exists (thbdbBasicIf * iface, gboolean* _return, const gchar * key, thbdbInvalidOperation ** exp, GError ** error)
{
  THRIFT_UNUSED_VAR (iface);
  THRIFT_UNUSED_VAR (error);
  g_return_val_if_fail (THBDB_IS_BASIC_HANDLER (iface), FALSE);

  //@@@
  puts (" ^^ exists() ^^ ");

  
  int ret = THBDB_NORMAL;
  GString* gkey;
  int status; /* exists or not */
  int returnValue = TRUE;
  
  gkey = g_string_new( key ); 
  ret = exists_on_bdb( 
                      gkey->str,
                      gkey->len,
                      &status
                       );
  if( ret != 0 ){
    g_set_error(
                error,
                G_THBDB_ERROR,
                ret,
                "An error is occered under executing exists() CODE=(%d)",
                ret
                );
    
    returnValue = FALSE;
  }else{
    *_return = status;
  }

  /* Free memory(gstring)  */
  if( gkey )
    g_string_free( gkey,FALSE );

  return returnValue;
}


/**
 * Put a key/value pair (async-mode).
 * Under construction.
 */
gboolean thbdb_basicimpl_handler_put_async (thbdbBasicIf * iface, const gchar * key, const gchar * value, GError ** error)
{

  return FALSE;
}

/**
 *  Return(_return) value from the internal bdb.
 *
 */
gboolean thbdb_basicimpl_handler_get (thbdbBasicIf * iface, gchar ** _return, const gchar * key, thbdbInvalidOperation ** exp, GError ** error)
{
  THRIFT_UNUSED_VAR (iface);
  THRIFT_UNUSED_VAR (error);
  g_return_val_if_fail (THBDB_IS_BASIC_HANDLER (iface), FALSE);

  //@@@
  puts (" ^^ get() ^^ ");

  
  int ret = THBDB_NORMAL;
  GString* gkey;
  GString* gvalue;

  gchar* value;
  int value_len;
  int returnValue = TRUE;

  //gvalue = g_string_new( NULL );
  gvalue = NULL;
  gkey = g_string_new( key ); 

  /*
  ret = get_from_bdb( 
                      gkey->str,
                      gkey->len,
                      &value
                       );
  */
  ret = get_from_bdb_unicode( 
                      gkey->str,
                      gkey->len,
                      &value,
                      &value_len
                       );

  if( ret != 0 ){
    g_set_error(
                error,
                G_THBDB_ERROR,
                ret,
                "An error is occered under executing exists() CODE=(%d)",
                ret
                );
    
    returnValue = FALSE;
  }else{
    gvalue = g_string_new_len( value, value_len );

    if( value ){
      free( value );
    }
    *_return = gvalue->str;
  }

  /* Free memory(gstring)  */
  if( gkey )
    g_string_free( gkey,FALSE );

  if( gvalue )
    g_string_free( gvalue,FALSE );

  return returnValue;

}

/**
 *
 * Removes data that the key specified  from the internal bdb.
 *
 */
gboolean thbdb_basicimpl_handler_remove (thbdbBasicIf * iface, const gchar * key, thbdbInvalidOperation ** exp, GError ** error)
{
  THRIFT_UNUSED_VAR (iface);
  THRIFT_UNUSED_VAR (error);
  g_return_val_if_fail (THBDB_IS_BASIC_HANDLER (iface), FALSE);

  //@@@
  puts (" ^^ remove() ^^ ");
  
  int ret = THBDB_NORMAL;
  GString* gkey;
  int returnValue = TRUE;
  
  gkey = g_string_new( key ); 
  ret = remove_from_bdb( 
                      gkey->str,
                      gkey->len
                       );
  if( ret != 0 ){
    g_set_error(
                error,
                G_THBDB_ERROR,
                ret,
                "An error is occered under executing exists() CODE=(%d)",
                ret
                );
    
    returnValue = FALSE;
  }

  /* Free memory(gstring)  */
  if( gkey )
    g_string_free( gkey,FALSE );

  return returnValue;
}

/**
 * Returns ( _return ) a key list that the internal bdb has .
 * Under construction.
 */
gboolean thbdb_basicimpl_handler_get_keys (thbdbBasicIf * iface, thbdbKeys ** _return, thbdbInvalidOperation ** exp, GError ** error)
{
  g_return_val_if_fail (THBDB_IS_BASIC_HANDLER (iface), FALSE);

  return FALSE;
}

/**
 *
 * Confirm reachability.
 *
 */
static gboolean 
thbdb_basicimpl_handler_ping (thbdbBasicIf * iface, GError ** error)
{
  THRIFT_UNUSED_VAR (iface);
  THRIFT_UNUSED_VAR (error);
  g_return_val_if_fail (THBDB_IS_BASIC_HANDLER (iface), FALSE);

  //@@@
  puts (" ^^ ping() ^^ ");
  return TRUE;

}

/**
 *
 * Returns a status that the internal bdb's status.
 * Returns(_return) THBDB_STATUS_DB_RUNNING if BDB isn't null, THBDB_STATUS_DB_NOT_OPEND if BDB is null.
 */
gboolean thbdb_basicimpl_handler_get_status (thbdbBasicIf * iface, gint32* _return, GError ** error)
{ 
  THRIFT_UNUSED_VAR (iface);
  THRIFT_UNUSED_VAR (error);
  g_return_val_if_fail (THBDB_IS_BASIC_HANDLER (iface), FALSE);

  //@@@
  puts (" ^^ get_status() ^^ ");
      
  int ret ;
  int status; /* handled or not */
  int returnValue = FALSE;

   /** Initializes _return */
  *_return = THBDB_STATUS_DB_NOT_OPEND;

  /** Check the bdb is null */
  ret = is_null_bdb( 
                    &status
                     );
                       
  if( ret == THBDB_NORMAL ){
    if (status == TRUE ){
      *_return = THBDB_STATUS_DB_NOT_OPEND;
    } else {
      *_return = THBDB_STATUS_DB_RUNNING;
    }
    returnValue = TRUE;
  }

  return returnValue;  
}

/**
 *
 * Returns(_return) a non-zero error code on DB->compact error code and 0 on success.
 */
gboolean thbdb_basicimpl_handler_compact (thbdbBasicIf *iface, gint32* _return, thbdbInvalidOperation ** exp, GError **error)
{ 
  THRIFT_UNUSED_VAR (iface);
  THRIFT_UNUSED_VAR (error);
  g_return_val_if_fail (THBDB_IS_BASIC_HANDLER (iface), FALSE);

  //@@@
  puts (" ^^ compact() ^^ ");
  
  int ret = THBDB_NORMAL;
  int returnValue = FALSE;

   /** Initializes _return */
  *_return = 0;

  /** Try to compact the bdb */
  ret = compact_bdb( &_return );

  if ( ret != THBDB_NORMAL ){

      if (ret == THBDB_DB_NOT_OPENED_ERROR){
        g_set_error(
                error,
                G_THBDB_ERROR,
                THBDB_DB_NOT_OPENED_ERROR,
                "An error is occered under executing compact(). A BDB contained in the ThBDB haven't been opened yet."
                ); 
      } else {

        returnValue = TRUE;

/*         // エラー発生時、エラー出力し処理を止める場合、g_set_errorを有効にする
        g_set_error(
                error,
                G_THBDB_ERROR,
                _return,
                "An error is occered under executing compact() CODE=(%d)",
                _return
                ); 
 */
      } 
    
  } else {
    returnValue = TRUE;
  }
 
  return returnValue;  
}


/**
 * Returns ( _return ) a key list that the internal bdb has .
 * Under construction.
 */
gboolean thbdb_basicimpl_handler_get_keys_by_position (thbdbBasicIf * iface, thbdbKeys ** _return, const gint32 position, const gint32 size, thbdbInvalidOperation ** exp, GError ** error)
{
  THRIFT_UNUSED_VAR (iface);
  THRIFT_UNUSED_VAR (error);
  g_return_val_if_fail (THBDB_IS_BASIC_HANDLER (iface), FALSE);

  g_return_val_if_fail(*_return != NULL, FALSE);
  g_return_val_if_fail(position >= 0, FALSE);
  g_return_val_if_fail(size >= 0, FALSE);

  //@@@
  puts (" ^^ get_keys_by_position() ^^ ");

  int ret = THBDB_NORMAL;
  int returnValue = FALSE;

  /* getKeys*/
  ret = get_keys_from_bdb( position, size, *_return );

  if( ret != THBDB_NORMAL ){
    g_set_error(
                error,
                G_THBDB_ERROR,
                ret,
                "An error is occered under executing get_keys_by_position() CODE=(%d)",
                ret
                );
  }else{
    returnValue = TRUE;
  }
  return returnValue;
}

/*------------------------------  API Handlers (END)-----------------------------------*/


/* THBDB basicimpl Handler's instance finalizer (destructor) */
static void
thbdb_basicimpl_handler_finalize (GObject *object)
{
  ThbdbBasicimplHandler *self =
    THBDB_BASICIMPL_HANDLER (object);

  /* Free our calculation-log hash table */
  g_hash_table_unref (self->log);
  self->log = NULL;

  /* Chain up to the parent class */
  G_OBJECT_CLASS (thbdb_basicimpl_handler_parent_class)->
    finalize (object);
}

/* ThbdbBasicimplHandler's instance initializer (constructor) */
static void
thbdb_basicimpl_handler_init (ThbdbBasicimplHandler *self)
{
  //@@@
    /* Create our calculation-log hash table */
  self->log = g_hash_table_new_full (g_int_hash,
                                     g_int_equal,
                                     g_free,
                                     g_object_unref);
}

/* ThbdbBasicimplHandler's class initializer */
static void
thbdb_basicimpl_handler_class_init (ThbdbBasicimplHandlerClass *klass)
{
  //@@@
  puts( "Initializing a handler class.... " );
  
  GObjectClass *gobject_class = G_OBJECT_CLASS (klass);
  thbdbBasicHandlerClass *thbdb_basic_handler_class =
    THBDB_BASIC_HANDLER_CLASS (klass);

  /* Register our destructor */
  gobject_class->finalize = thbdb_basicimpl_handler_finalize;

  /* Register our implementations of CalculatorHandler's methods */
  thbdb_basic_handler_class->hello =
    thbdb_basicimpl_handler_hello;
  thbdb_basic_handler_class->put =
    thbdb_basicimpl_handler_put;
  thbdb_basic_handler_class->exists =
    thbdb_basicimpl_handler_exists;
  thbdb_basic_handler_class->get =
    thbdb_basicimpl_handler_get;
  thbdb_basic_handler_class->remove =
    thbdb_basicimpl_handler_remove;
  thbdb_basic_handler_class->ping = 
    thbdb_basicimpl_handler_ping;
  thbdb_basic_handler_class->get_status = 
    thbdb_basicimpl_handler_get_status;
  thbdb_basic_handler_class->get_keys_by_position =
    thbdb_basicimpl_handler_get_keys_by_position;
  thbdb_basic_handler_class->compact =
    thbdb_basicimpl_handler_compact;
}


/* That ends the implementation of ThbdbBasicimplHandler.
   Everything below is fairly generic code that sets up a minimal
   Thrift server for Thbdb clients. */
