/**
 * Autogenerated by Thrift Compiler (0.11.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef THBDB_THBDB_TYPES_H
#define THBDB_THBDB_TYPES_H

/* base includes */
#include <glib-object.h>
#include <thrift/c_glib/thrift_struct.h>
#include <thrift/c_glib/protocol/thrift_protocol.h>

/* custom thrift includes */

/* begin types */

enum _thbdbErrorCode {
  THBDB_ERROR_CODE_INVALID_OPERATION = 1
};
typedef enum _thbdbErrorCode thbdbErrorCode;

/* return the name of the constant */
const char *
toString_ErrorCode(int value); 

/* struct Item */
struct _thbdbItem
{ 
  ThriftStruct parent; 

  /* public */
  gchar * key;
  gboolean __isset_key;
  gchar * value;
  gboolean __isset_value;
};
typedef struct _thbdbItem thbdbItem;

struct _thbdbItemClass
{
  ThriftStructClass parent;
};
typedef struct _thbdbItemClass thbdbItemClass;

GType thbdb_item_get_type (void);
#define THBDB_TYPE_ITEM (thbdb_item_get_type())
#define THBDB_ITEM(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), THBDB_TYPE_ITEM, thbdbItem))
#define THBDB_ITEM_CLASS(c) (G_TYPE_CHECK_CLASS_CAST ((c), THBDB__TYPE_ITEM, thbdbItemClass))
#define THBDB_IS_ITEM(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), THBDB_TYPE_ITEM))
#define THBDB_IS_ITEM_CLASS(c) (G_TYPE_CHECK_CLASS_TYPE ((c), THBDB_TYPE_ITEM))
#define THBDB_ITEM_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), THBDB_TYPE_ITEM, thbdbItemClass))

/* struct ItemList */
struct _thbdbItemList
{ 
  ThriftStruct parent; 

  /* public */
  gint32 numOfItems;
  gboolean __isset_numOfItems;
  GPtrArray * items;
  gboolean __isset_items;
};
typedef struct _thbdbItemList thbdbItemList;

struct _thbdbItemListClass
{
  ThriftStructClass parent;
};
typedef struct _thbdbItemListClass thbdbItemListClass;

GType thbdb_item_list_get_type (void);
#define THBDB_TYPE_ITEM_LIST (thbdb_item_list_get_type())
#define THBDB_ITEM_LIST(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), THBDB_TYPE_ITEM_LIST, thbdbItemList))
#define THBDB_ITEM_LIST_CLASS(c) (G_TYPE_CHECK_CLASS_CAST ((c), THBDB__TYPE_ITEM_LIST, thbdbItemListClass))
#define THBDB_IS_ITEM_LIST(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), THBDB_TYPE_ITEM_LIST))
#define THBDB_IS_ITEM_LIST_CLASS(c) (G_TYPE_CHECK_CLASS_TYPE ((c), THBDB_TYPE_ITEM_LIST))
#define THBDB_ITEM_LIST_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), THBDB_TYPE_ITEM_LIST, thbdbItemListClass))

/* struct Keys */
struct _thbdbKeys
{ 
  ThriftStruct parent; 

  /* public */
  gint32 numOfKeys;
  gboolean __isset_numOfKeys;
  GPtrArray * key;
  gboolean __isset_key;
};
typedef struct _thbdbKeys thbdbKeys;

struct _thbdbKeysClass
{
  ThriftStructClass parent;
};
typedef struct _thbdbKeysClass thbdbKeysClass;

GType thbdb_keys_get_type (void);
#define THBDB_TYPE_KEYS (thbdb_keys_get_type())
#define THBDB_KEYS(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), THBDB_TYPE_KEYS, thbdbKeys))
#define THBDB_KEYS_CLASS(c) (G_TYPE_CHECK_CLASS_CAST ((c), THBDB__TYPE_KEYS, thbdbKeysClass))
#define THBDB_IS_KEYS(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), THBDB_TYPE_KEYS))
#define THBDB_IS_KEYS_CLASS(c) (G_TYPE_CHECK_CLASS_TYPE ((c), THBDB_TYPE_KEYS))
#define THBDB_KEYS_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), THBDB_TYPE_KEYS, thbdbKeysClass))

struct _thbdbInvalidOperation
{ 
  ThriftStruct parent; 

  /* public */
  gint32 errorCode;
  gboolean __isset_errorCode;
  gchar * message;
  gboolean __isset_message;
};
typedef struct _thbdbInvalidOperation thbdbInvalidOperation;

struct _thbdbInvalidOperationClass
{
  ThriftStructClass parent;
};
typedef struct _thbdbInvalidOperationClass thbdbInvalidOperationClass;

GType thbdb_invalid_operation_get_type (void);
#define THBDB_TYPE_INVALID_OPERATION (thbdb_invalid_operation_get_type())
#define THBDB_INVALID_OPERATION(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), THBDB_TYPE_INVALID_OPERATION, thbdbInvalidOperation))
#define THBDB_INVALID_OPERATION_CLASS(c) (G_TYPE_CHECK_CLASS_CAST ((c), THBDB__TYPE_INVALID_OPERATION, thbdbInvalidOperationClass))
#define THBDB_IS_INVALID_OPERATION(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), THBDB_TYPE_INVALID_OPERATION))
#define THBDB_IS_INVALID_OPERATION_CLASS(c) (G_TYPE_CHECK_CLASS_TYPE ((c), THBDB_TYPE_INVALID_OPERATION))
#define THBDB_INVALID_OPERATION_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), THBDB_TYPE_INVALID_OPERATION, thbdbInvalidOperationClass))

/* exception */
typedef enum
{
  THBDB_INVALID_OPERATION_ERROR_CODE
} thbdbInvalidOperationError;

GQuark thbdb_invalid_operation_error_quark (void);
#define THBDB_INVALID_OPERATION_ERROR (thbdb_invalid_operation_error_quark())


/* constants */

/* struct BasicPutArgs */
struct _thbdbBasicPutArgs
{ 
  ThriftStruct parent; 

  /* public */
  gchar * key;
  gboolean __isset_key;
  gchar * value;
  gboolean __isset_value;
};
typedef struct _thbdbBasicPutArgs thbdbBasicPutArgs;

struct _thbdbBasicPutArgsClass
{
  ThriftStructClass parent;
};
typedef struct _thbdbBasicPutArgsClass thbdbBasicPutArgsClass;

GType thbdb_basic_put_args_get_type (void);
#define THBDB_TYPE_BASIC_PUT_ARGS (thbdb_basic_put_args_get_type())
#define THBDB_BASIC_PUT_ARGS(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), THBDB_TYPE_BASIC_PUT_ARGS, thbdbBasicPutArgs))
#define THBDB_BASIC_PUT_ARGS_CLASS(c) (G_TYPE_CHECK_CLASS_CAST ((c), THBDB__TYPE_BASIC_PUT_ARGS, thbdbBasicPutArgsClass))
#define THBDB_IS_BASIC_PUT_ARGS(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), THBDB_TYPE_BASIC_PUT_ARGS))
#define THBDB_IS_BASIC_PUT_ARGS_CLASS(c) (G_TYPE_CHECK_CLASS_TYPE ((c), THBDB_TYPE_BASIC_PUT_ARGS))
#define THBDB_BASIC_PUT_ARGS_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), THBDB_TYPE_BASIC_PUT_ARGS, thbdbBasicPutArgsClass))

/* struct BasicPutResult */
struct _thbdbBasicPutResult
{ 
  ThriftStruct parent; 

  /* public */
  thbdbInvalidOperation * exp;
  gboolean __isset_exp;
};
typedef struct _thbdbBasicPutResult thbdbBasicPutResult;

struct _thbdbBasicPutResultClass
{
  ThriftStructClass parent;
};
typedef struct _thbdbBasicPutResultClass thbdbBasicPutResultClass;

GType thbdb_basic_put_result_get_type (void);
#define THBDB_TYPE_BASIC_PUT_RESULT (thbdb_basic_put_result_get_type())
#define THBDB_BASIC_PUT_RESULT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), THBDB_TYPE_BASIC_PUT_RESULT, thbdbBasicPutResult))
#define THBDB_BASIC_PUT_RESULT_CLASS(c) (G_TYPE_CHECK_CLASS_CAST ((c), THBDB__TYPE_BASIC_PUT_RESULT, thbdbBasicPutResultClass))
#define THBDB_IS_BASIC_PUT_RESULT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), THBDB_TYPE_BASIC_PUT_RESULT))
#define THBDB_IS_BASIC_PUT_RESULT_CLASS(c) (G_TYPE_CHECK_CLASS_TYPE ((c), THBDB_TYPE_BASIC_PUT_RESULT))
#define THBDB_BASIC_PUT_RESULT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), THBDB_TYPE_BASIC_PUT_RESULT, thbdbBasicPutResultClass))

/* struct BasicPutAsyncArgs */
struct _thbdbBasicPutAsyncArgs
{ 
  ThriftStruct parent; 

  /* public */
  gchar * key;
  gboolean __isset_key;
  gchar * value;
  gboolean __isset_value;
};
typedef struct _thbdbBasicPutAsyncArgs thbdbBasicPutAsyncArgs;

struct _thbdbBasicPutAsyncArgsClass
{
  ThriftStructClass parent;
};
typedef struct _thbdbBasicPutAsyncArgsClass thbdbBasicPutAsyncArgsClass;

GType thbdb_basic_put_async_args_get_type (void);
#define THBDB_TYPE_BASIC_PUT_ASYNC_ARGS (thbdb_basic_put_async_args_get_type())
#define THBDB_BASIC_PUT_ASYNC_ARGS(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), THBDB_TYPE_BASIC_PUT_ASYNC_ARGS, thbdbBasicPutAsyncArgs))
#define THBDB_BASIC_PUT_ASYNC_ARGS_CLASS(c) (G_TYPE_CHECK_CLASS_CAST ((c), THBDB__TYPE_BASIC_PUT_ASYNC_ARGS, thbdbBasicPutAsyncArgsClass))
#define THBDB_IS_BASIC_PUT_ASYNC_ARGS(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), THBDB_TYPE_BASIC_PUT_ASYNC_ARGS))
#define THBDB_IS_BASIC_PUT_ASYNC_ARGS_CLASS(c) (G_TYPE_CHECK_CLASS_TYPE ((c), THBDB_TYPE_BASIC_PUT_ASYNC_ARGS))
#define THBDB_BASIC_PUT_ASYNC_ARGS_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), THBDB_TYPE_BASIC_PUT_ASYNC_ARGS, thbdbBasicPutAsyncArgsClass))

/* struct BasicExistsArgs */
struct _thbdbBasicExistsArgs
{ 
  ThriftStruct parent; 

  /* public */
  gchar * key;
  gboolean __isset_key;
};
typedef struct _thbdbBasicExistsArgs thbdbBasicExistsArgs;

struct _thbdbBasicExistsArgsClass
{
  ThriftStructClass parent;
};
typedef struct _thbdbBasicExistsArgsClass thbdbBasicExistsArgsClass;

GType thbdb_basic_exists_args_get_type (void);
#define THBDB_TYPE_BASIC_EXISTS_ARGS (thbdb_basic_exists_args_get_type())
#define THBDB_BASIC_EXISTS_ARGS(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), THBDB_TYPE_BASIC_EXISTS_ARGS, thbdbBasicExistsArgs))
#define THBDB_BASIC_EXISTS_ARGS_CLASS(c) (G_TYPE_CHECK_CLASS_CAST ((c), THBDB__TYPE_BASIC_EXISTS_ARGS, thbdbBasicExistsArgsClass))
#define THBDB_IS_BASIC_EXISTS_ARGS(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), THBDB_TYPE_BASIC_EXISTS_ARGS))
#define THBDB_IS_BASIC_EXISTS_ARGS_CLASS(c) (G_TYPE_CHECK_CLASS_TYPE ((c), THBDB_TYPE_BASIC_EXISTS_ARGS))
#define THBDB_BASIC_EXISTS_ARGS_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), THBDB_TYPE_BASIC_EXISTS_ARGS, thbdbBasicExistsArgsClass))

/* struct BasicExistsResult */
struct _thbdbBasicExistsResult
{ 
  ThriftStruct parent; 

  /* public */
  gboolean success;
  gboolean __isset_success;
  thbdbInvalidOperation * exp;
  gboolean __isset_exp;
};
typedef struct _thbdbBasicExistsResult thbdbBasicExistsResult;

struct _thbdbBasicExistsResultClass
{
  ThriftStructClass parent;
};
typedef struct _thbdbBasicExistsResultClass thbdbBasicExistsResultClass;

GType thbdb_basic_exists_result_get_type (void);
#define THBDB_TYPE_BASIC_EXISTS_RESULT (thbdb_basic_exists_result_get_type())
#define THBDB_BASIC_EXISTS_RESULT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), THBDB_TYPE_BASIC_EXISTS_RESULT, thbdbBasicExistsResult))
#define THBDB_BASIC_EXISTS_RESULT_CLASS(c) (G_TYPE_CHECK_CLASS_CAST ((c), THBDB__TYPE_BASIC_EXISTS_RESULT, thbdbBasicExistsResultClass))
#define THBDB_IS_BASIC_EXISTS_RESULT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), THBDB_TYPE_BASIC_EXISTS_RESULT))
#define THBDB_IS_BASIC_EXISTS_RESULT_CLASS(c) (G_TYPE_CHECK_CLASS_TYPE ((c), THBDB_TYPE_BASIC_EXISTS_RESULT))
#define THBDB_BASIC_EXISTS_RESULT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), THBDB_TYPE_BASIC_EXISTS_RESULT, thbdbBasicExistsResultClass))

/* struct BasicGetArgs */
struct _thbdbBasicGetArgs
{ 
  ThriftStruct parent; 

  /* public */
  gchar * key;
  gboolean __isset_key;
};
typedef struct _thbdbBasicGetArgs thbdbBasicGetArgs;

struct _thbdbBasicGetArgsClass
{
  ThriftStructClass parent;
};
typedef struct _thbdbBasicGetArgsClass thbdbBasicGetArgsClass;

GType thbdb_basic_get_args_get_type (void);
#define THBDB_TYPE_BASIC_GET_ARGS (thbdb_basic_get_args_get_type())
#define THBDB_BASIC_GET_ARGS(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), THBDB_TYPE_BASIC_GET_ARGS, thbdbBasicGetArgs))
#define THBDB_BASIC_GET_ARGS_CLASS(c) (G_TYPE_CHECK_CLASS_CAST ((c), THBDB__TYPE_BASIC_GET_ARGS, thbdbBasicGetArgsClass))
#define THBDB_IS_BASIC_GET_ARGS(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), THBDB_TYPE_BASIC_GET_ARGS))
#define THBDB_IS_BASIC_GET_ARGS_CLASS(c) (G_TYPE_CHECK_CLASS_TYPE ((c), THBDB_TYPE_BASIC_GET_ARGS))
#define THBDB_BASIC_GET_ARGS_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), THBDB_TYPE_BASIC_GET_ARGS, thbdbBasicGetArgsClass))

/* struct BasicGetResult */
struct _thbdbBasicGetResult
{ 
  ThriftStruct parent; 

  /* public */
  gchar * success;
  gboolean __isset_success;
  thbdbInvalidOperation * exp;
  gboolean __isset_exp;
};
typedef struct _thbdbBasicGetResult thbdbBasicGetResult;

struct _thbdbBasicGetResultClass
{
  ThriftStructClass parent;
};
typedef struct _thbdbBasicGetResultClass thbdbBasicGetResultClass;

GType thbdb_basic_get_result_get_type (void);
#define THBDB_TYPE_BASIC_GET_RESULT (thbdb_basic_get_result_get_type())
#define THBDB_BASIC_GET_RESULT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), THBDB_TYPE_BASIC_GET_RESULT, thbdbBasicGetResult))
#define THBDB_BASIC_GET_RESULT_CLASS(c) (G_TYPE_CHECK_CLASS_CAST ((c), THBDB__TYPE_BASIC_GET_RESULT, thbdbBasicGetResultClass))
#define THBDB_IS_BASIC_GET_RESULT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), THBDB_TYPE_BASIC_GET_RESULT))
#define THBDB_IS_BASIC_GET_RESULT_CLASS(c) (G_TYPE_CHECK_CLASS_TYPE ((c), THBDB_TYPE_BASIC_GET_RESULT))
#define THBDB_BASIC_GET_RESULT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), THBDB_TYPE_BASIC_GET_RESULT, thbdbBasicGetResultClass))

/* struct BasicRemoveArgs */
struct _thbdbBasicRemoveArgs
{ 
  ThriftStruct parent; 

  /* public */
  gchar * key;
  gboolean __isset_key;
};
typedef struct _thbdbBasicRemoveArgs thbdbBasicRemoveArgs;

struct _thbdbBasicRemoveArgsClass
{
  ThriftStructClass parent;
};
typedef struct _thbdbBasicRemoveArgsClass thbdbBasicRemoveArgsClass;

GType thbdb_basic_remove_args_get_type (void);
#define THBDB_TYPE_BASIC_REMOVE_ARGS (thbdb_basic_remove_args_get_type())
#define THBDB_BASIC_REMOVE_ARGS(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), THBDB_TYPE_BASIC_REMOVE_ARGS, thbdbBasicRemoveArgs))
#define THBDB_BASIC_REMOVE_ARGS_CLASS(c) (G_TYPE_CHECK_CLASS_CAST ((c), THBDB__TYPE_BASIC_REMOVE_ARGS, thbdbBasicRemoveArgsClass))
#define THBDB_IS_BASIC_REMOVE_ARGS(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), THBDB_TYPE_BASIC_REMOVE_ARGS))
#define THBDB_IS_BASIC_REMOVE_ARGS_CLASS(c) (G_TYPE_CHECK_CLASS_TYPE ((c), THBDB_TYPE_BASIC_REMOVE_ARGS))
#define THBDB_BASIC_REMOVE_ARGS_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), THBDB_TYPE_BASIC_REMOVE_ARGS, thbdbBasicRemoveArgsClass))

/* struct BasicRemoveResult */
struct _thbdbBasicRemoveResult
{ 
  ThriftStruct parent; 

  /* public */
  thbdbInvalidOperation * exp;
  gboolean __isset_exp;
};
typedef struct _thbdbBasicRemoveResult thbdbBasicRemoveResult;

struct _thbdbBasicRemoveResultClass
{
  ThriftStructClass parent;
};
typedef struct _thbdbBasicRemoveResultClass thbdbBasicRemoveResultClass;

GType thbdb_basic_remove_result_get_type (void);
#define THBDB_TYPE_BASIC_REMOVE_RESULT (thbdb_basic_remove_result_get_type())
#define THBDB_BASIC_REMOVE_RESULT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), THBDB_TYPE_BASIC_REMOVE_RESULT, thbdbBasicRemoveResult))
#define THBDB_BASIC_REMOVE_RESULT_CLASS(c) (G_TYPE_CHECK_CLASS_CAST ((c), THBDB__TYPE_BASIC_REMOVE_RESULT, thbdbBasicRemoveResultClass))
#define THBDB_IS_BASIC_REMOVE_RESULT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), THBDB_TYPE_BASIC_REMOVE_RESULT))
#define THBDB_IS_BASIC_REMOVE_RESULT_CLASS(c) (G_TYPE_CHECK_CLASS_TYPE ((c), THBDB_TYPE_BASIC_REMOVE_RESULT))
#define THBDB_BASIC_REMOVE_RESULT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), THBDB_TYPE_BASIC_REMOVE_RESULT, thbdbBasicRemoveResultClass))

/* struct BasicGetKeysArgs */
struct _thbdbBasicGetKeysArgs
{ 
  ThriftStruct parent; 

  /* public */
};
typedef struct _thbdbBasicGetKeysArgs thbdbBasicGetKeysArgs;

struct _thbdbBasicGetKeysArgsClass
{
  ThriftStructClass parent;
};
typedef struct _thbdbBasicGetKeysArgsClass thbdbBasicGetKeysArgsClass;

GType thbdb_basic_get_keys_args_get_type (void);
#define THBDB_TYPE_BASIC_GET_KEYS_ARGS (thbdb_basic_get_keys_args_get_type())
#define THBDB_BASIC_GET_KEYS_ARGS(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), THBDB_TYPE_BASIC_GET_KEYS_ARGS, thbdbBasicGetKeysArgs))
#define THBDB_BASIC_GET_KEYS_ARGS_CLASS(c) (G_TYPE_CHECK_CLASS_CAST ((c), THBDB__TYPE_BASIC_GET_KEYS_ARGS, thbdbBasicGetKeysArgsClass))
#define THBDB_IS_BASIC_GET_KEYS_ARGS(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), THBDB_TYPE_BASIC_GET_KEYS_ARGS))
#define THBDB_IS_BASIC_GET_KEYS_ARGS_CLASS(c) (G_TYPE_CHECK_CLASS_TYPE ((c), THBDB_TYPE_BASIC_GET_KEYS_ARGS))
#define THBDB_BASIC_GET_KEYS_ARGS_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), THBDB_TYPE_BASIC_GET_KEYS_ARGS, thbdbBasicGetKeysArgsClass))

/* struct BasicGetKeysResult */
struct _thbdbBasicGetKeysResult
{ 
  ThriftStruct parent; 

  /* public */
  thbdbKeys * success;
  gboolean __isset_success;
  thbdbInvalidOperation * exp;
  gboolean __isset_exp;
};
typedef struct _thbdbBasicGetKeysResult thbdbBasicGetKeysResult;

struct _thbdbBasicGetKeysResultClass
{
  ThriftStructClass parent;
};
typedef struct _thbdbBasicGetKeysResultClass thbdbBasicGetKeysResultClass;

GType thbdb_basic_get_keys_result_get_type (void);
#define THBDB_TYPE_BASIC_GET_KEYS_RESULT (thbdb_basic_get_keys_result_get_type())
#define THBDB_BASIC_GET_KEYS_RESULT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), THBDB_TYPE_BASIC_GET_KEYS_RESULT, thbdbBasicGetKeysResult))
#define THBDB_BASIC_GET_KEYS_RESULT_CLASS(c) (G_TYPE_CHECK_CLASS_CAST ((c), THBDB__TYPE_BASIC_GET_KEYS_RESULT, thbdbBasicGetKeysResultClass))
#define THBDB_IS_BASIC_GET_KEYS_RESULT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), THBDB_TYPE_BASIC_GET_KEYS_RESULT))
#define THBDB_IS_BASIC_GET_KEYS_RESULT_CLASS(c) (G_TYPE_CHECK_CLASS_TYPE ((c), THBDB_TYPE_BASIC_GET_KEYS_RESULT))
#define THBDB_BASIC_GET_KEYS_RESULT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), THBDB_TYPE_BASIC_GET_KEYS_RESULT, thbdbBasicGetKeysResultClass))

/* struct BasicGetKeysByPositionArgs */
struct _thbdbBasicGetKeysByPositionArgs
{ 
  ThriftStruct parent; 

  /* public */
  gint32 position;
  gboolean __isset_position;
  gint32 size;
  gboolean __isset_size;
};
typedef struct _thbdbBasicGetKeysByPositionArgs thbdbBasicGetKeysByPositionArgs;

struct _thbdbBasicGetKeysByPositionArgsClass
{
  ThriftStructClass parent;
};
typedef struct _thbdbBasicGetKeysByPositionArgsClass thbdbBasicGetKeysByPositionArgsClass;

GType thbdb_basic_get_keys_by_position_args_get_type (void);
#define THBDB_TYPE_BASIC_GET_KEYS_BY_POSITION_ARGS (thbdb_basic_get_keys_by_position_args_get_type())
#define THBDB_BASIC_GET_KEYS_BY_POSITION_ARGS(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), THBDB_TYPE_BASIC_GET_KEYS_BY_POSITION_ARGS, thbdbBasicGetKeysByPositionArgs))
#define THBDB_BASIC_GET_KEYS_BY_POSITION_ARGS_CLASS(c) (G_TYPE_CHECK_CLASS_CAST ((c), THBDB__TYPE_BASIC_GET_KEYS_BY_POSITION_ARGS, thbdbBasicGetKeysByPositionArgsClass))
#define THBDB_IS_BASIC_GET_KEYS_BY_POSITION_ARGS(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), THBDB_TYPE_BASIC_GET_KEYS_BY_POSITION_ARGS))
#define THBDB_IS_BASIC_GET_KEYS_BY_POSITION_ARGS_CLASS(c) (G_TYPE_CHECK_CLASS_TYPE ((c), THBDB_TYPE_BASIC_GET_KEYS_BY_POSITION_ARGS))
#define THBDB_BASIC_GET_KEYS_BY_POSITION_ARGS_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), THBDB_TYPE_BASIC_GET_KEYS_BY_POSITION_ARGS, thbdbBasicGetKeysByPositionArgsClass))

/* struct BasicGetKeysByPositionResult */
struct _thbdbBasicGetKeysByPositionResult
{ 
  ThriftStruct parent; 

  /* public */
  thbdbKeys * success;
  gboolean __isset_success;
  thbdbInvalidOperation * exp;
  gboolean __isset_exp;
};
typedef struct _thbdbBasicGetKeysByPositionResult thbdbBasicGetKeysByPositionResult;

struct _thbdbBasicGetKeysByPositionResultClass
{
  ThriftStructClass parent;
};
typedef struct _thbdbBasicGetKeysByPositionResultClass thbdbBasicGetKeysByPositionResultClass;

GType thbdb_basic_get_keys_by_position_result_get_type (void);
#define THBDB_TYPE_BASIC_GET_KEYS_BY_POSITION_RESULT (thbdb_basic_get_keys_by_position_result_get_type())
#define THBDB_BASIC_GET_KEYS_BY_POSITION_RESULT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), THBDB_TYPE_BASIC_GET_KEYS_BY_POSITION_RESULT, thbdbBasicGetKeysByPositionResult))
#define THBDB_BASIC_GET_KEYS_BY_POSITION_RESULT_CLASS(c) (G_TYPE_CHECK_CLASS_CAST ((c), THBDB__TYPE_BASIC_GET_KEYS_BY_POSITION_RESULT, thbdbBasicGetKeysByPositionResultClass))
#define THBDB_IS_BASIC_GET_KEYS_BY_POSITION_RESULT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), THBDB_TYPE_BASIC_GET_KEYS_BY_POSITION_RESULT))
#define THBDB_IS_BASIC_GET_KEYS_BY_POSITION_RESULT_CLASS(c) (G_TYPE_CHECK_CLASS_TYPE ((c), THBDB_TYPE_BASIC_GET_KEYS_BY_POSITION_RESULT))
#define THBDB_BASIC_GET_KEYS_BY_POSITION_RESULT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), THBDB_TYPE_BASIC_GET_KEYS_BY_POSITION_RESULT, thbdbBasicGetKeysByPositionResultClass))

/* struct BasicPingArgs */
struct _thbdbBasicPingArgs
{ 
  ThriftStruct parent; 

  /* public */
};
typedef struct _thbdbBasicPingArgs thbdbBasicPingArgs;

struct _thbdbBasicPingArgsClass
{
  ThriftStructClass parent;
};
typedef struct _thbdbBasicPingArgsClass thbdbBasicPingArgsClass;

GType thbdb_basic_ping_args_get_type (void);
#define THBDB_TYPE_BASIC_PING_ARGS (thbdb_basic_ping_args_get_type())
#define THBDB_BASIC_PING_ARGS(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), THBDB_TYPE_BASIC_PING_ARGS, thbdbBasicPingArgs))
#define THBDB_BASIC_PING_ARGS_CLASS(c) (G_TYPE_CHECK_CLASS_CAST ((c), THBDB__TYPE_BASIC_PING_ARGS, thbdbBasicPingArgsClass))
#define THBDB_IS_BASIC_PING_ARGS(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), THBDB_TYPE_BASIC_PING_ARGS))
#define THBDB_IS_BASIC_PING_ARGS_CLASS(c) (G_TYPE_CHECK_CLASS_TYPE ((c), THBDB_TYPE_BASIC_PING_ARGS))
#define THBDB_BASIC_PING_ARGS_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), THBDB_TYPE_BASIC_PING_ARGS, thbdbBasicPingArgsClass))

/* struct BasicPingResult */
struct _thbdbBasicPingResult
{ 
  ThriftStruct parent; 

  /* public */
};
typedef struct _thbdbBasicPingResult thbdbBasicPingResult;

struct _thbdbBasicPingResultClass
{
  ThriftStructClass parent;
};
typedef struct _thbdbBasicPingResultClass thbdbBasicPingResultClass;

GType thbdb_basic_ping_result_get_type (void);
#define THBDB_TYPE_BASIC_PING_RESULT (thbdb_basic_ping_result_get_type())
#define THBDB_BASIC_PING_RESULT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), THBDB_TYPE_BASIC_PING_RESULT, thbdbBasicPingResult))
#define THBDB_BASIC_PING_RESULT_CLASS(c) (G_TYPE_CHECK_CLASS_CAST ((c), THBDB__TYPE_BASIC_PING_RESULT, thbdbBasicPingResultClass))
#define THBDB_IS_BASIC_PING_RESULT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), THBDB_TYPE_BASIC_PING_RESULT))
#define THBDB_IS_BASIC_PING_RESULT_CLASS(c) (G_TYPE_CHECK_CLASS_TYPE ((c), THBDB_TYPE_BASIC_PING_RESULT))
#define THBDB_BASIC_PING_RESULT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), THBDB_TYPE_BASIC_PING_RESULT, thbdbBasicPingResultClass))

/* struct BasicHelloArgs */
struct _thbdbBasicHelloArgs
{ 
  ThriftStruct parent; 

  /* public */
  gchar * arg;
  gboolean __isset_arg;
};
typedef struct _thbdbBasicHelloArgs thbdbBasicHelloArgs;

struct _thbdbBasicHelloArgsClass
{
  ThriftStructClass parent;
};
typedef struct _thbdbBasicHelloArgsClass thbdbBasicHelloArgsClass;

GType thbdb_basic_hello_args_get_type (void);
#define THBDB_TYPE_BASIC_HELLO_ARGS (thbdb_basic_hello_args_get_type())
#define THBDB_BASIC_HELLO_ARGS(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), THBDB_TYPE_BASIC_HELLO_ARGS, thbdbBasicHelloArgs))
#define THBDB_BASIC_HELLO_ARGS_CLASS(c) (G_TYPE_CHECK_CLASS_CAST ((c), THBDB__TYPE_BASIC_HELLO_ARGS, thbdbBasicHelloArgsClass))
#define THBDB_IS_BASIC_HELLO_ARGS(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), THBDB_TYPE_BASIC_HELLO_ARGS))
#define THBDB_IS_BASIC_HELLO_ARGS_CLASS(c) (G_TYPE_CHECK_CLASS_TYPE ((c), THBDB_TYPE_BASIC_HELLO_ARGS))
#define THBDB_BASIC_HELLO_ARGS_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), THBDB_TYPE_BASIC_HELLO_ARGS, thbdbBasicHelloArgsClass))

/* struct BasicHelloResult */
struct _thbdbBasicHelloResult
{ 
  ThriftStruct parent; 

  /* public */
  gchar * success;
  gboolean __isset_success;
};
typedef struct _thbdbBasicHelloResult thbdbBasicHelloResult;

struct _thbdbBasicHelloResultClass
{
  ThriftStructClass parent;
};
typedef struct _thbdbBasicHelloResultClass thbdbBasicHelloResultClass;

GType thbdb_basic_hello_result_get_type (void);
#define THBDB_TYPE_BASIC_HELLO_RESULT (thbdb_basic_hello_result_get_type())
#define THBDB_BASIC_HELLO_RESULT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), THBDB_TYPE_BASIC_HELLO_RESULT, thbdbBasicHelloResult))
#define THBDB_BASIC_HELLO_RESULT_CLASS(c) (G_TYPE_CHECK_CLASS_CAST ((c), THBDB__TYPE_BASIC_HELLO_RESULT, thbdbBasicHelloResultClass))
#define THBDB_IS_BASIC_HELLO_RESULT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), THBDB_TYPE_BASIC_HELLO_RESULT))
#define THBDB_IS_BASIC_HELLO_RESULT_CLASS(c) (G_TYPE_CHECK_CLASS_TYPE ((c), THBDB_TYPE_BASIC_HELLO_RESULT))
#define THBDB_BASIC_HELLO_RESULT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), THBDB_TYPE_BASIC_HELLO_RESULT, thbdbBasicHelloResultClass))

/* struct BasicGetStatusArgs */
struct _thbdbBasicGetStatusArgs
{ 
  ThriftStruct parent; 

  /* public */
};
typedef struct _thbdbBasicGetStatusArgs thbdbBasicGetStatusArgs;

struct _thbdbBasicGetStatusArgsClass
{
  ThriftStructClass parent;
};
typedef struct _thbdbBasicGetStatusArgsClass thbdbBasicGetStatusArgsClass;

GType thbdb_basic_get_status_args_get_type (void);
#define THBDB_TYPE_BASIC_GET_STATUS_ARGS (thbdb_basic_get_status_args_get_type())
#define THBDB_BASIC_GET_STATUS_ARGS(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), THBDB_TYPE_BASIC_GET_STATUS_ARGS, thbdbBasicGetStatusArgs))
#define THBDB_BASIC_GET_STATUS_ARGS_CLASS(c) (G_TYPE_CHECK_CLASS_CAST ((c), THBDB__TYPE_BASIC_GET_STATUS_ARGS, thbdbBasicGetStatusArgsClass))
#define THBDB_IS_BASIC_GET_STATUS_ARGS(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), THBDB_TYPE_BASIC_GET_STATUS_ARGS))
#define THBDB_IS_BASIC_GET_STATUS_ARGS_CLASS(c) (G_TYPE_CHECK_CLASS_TYPE ((c), THBDB_TYPE_BASIC_GET_STATUS_ARGS))
#define THBDB_BASIC_GET_STATUS_ARGS_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), THBDB_TYPE_BASIC_GET_STATUS_ARGS, thbdbBasicGetStatusArgsClass))

/* struct BasicGetStatusResult */
struct _thbdbBasicGetStatusResult
{ 
  ThriftStruct parent; 

  /* public */
  gint32 success;
  gboolean __isset_success;
};
typedef struct _thbdbBasicGetStatusResult thbdbBasicGetStatusResult;

struct _thbdbBasicGetStatusResultClass
{
  ThriftStructClass parent;
};
typedef struct _thbdbBasicGetStatusResultClass thbdbBasicGetStatusResultClass;

GType thbdb_basic_get_status_result_get_type (void);
#define THBDB_TYPE_BASIC_GET_STATUS_RESULT (thbdb_basic_get_status_result_get_type())
#define THBDB_BASIC_GET_STATUS_RESULT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), THBDB_TYPE_BASIC_GET_STATUS_RESULT, thbdbBasicGetStatusResult))
#define THBDB_BASIC_GET_STATUS_RESULT_CLASS(c) (G_TYPE_CHECK_CLASS_CAST ((c), THBDB__TYPE_BASIC_GET_STATUS_RESULT, thbdbBasicGetStatusResultClass))
#define THBDB_IS_BASIC_GET_STATUS_RESULT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), THBDB_TYPE_BASIC_GET_STATUS_RESULT))
#define THBDB_IS_BASIC_GET_STATUS_RESULT_CLASS(c) (G_TYPE_CHECK_CLASS_TYPE ((c), THBDB_TYPE_BASIC_GET_STATUS_RESULT))
#define THBDB_BASIC_GET_STATUS_RESULT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), THBDB_TYPE_BASIC_GET_STATUS_RESULT, thbdbBasicGetStatusResultClass))

#endif /* THBDB_THBDB_TYPES_H */
