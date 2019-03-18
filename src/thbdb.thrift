#!/usr/local/bin/thrift --java --c_glib --py

#namespace java jp.co.softbank.thbdb.thrift
namespace java ml.masahi.thbdb.gen_java
namespace c_glib  thbdb
namespace py thbdb

/**
 * A pair of Key and Value which is held on the BDB.
 * !!This is not used currently!!
 * !!For future use!!
 */
struct Item{
  1: string key,
  2: string value
}

/**
 * The struct definition :
 *     The return value of list() method.
 * !!This is not used currently!!
 * !!For future use!!
 */
struct ItemList{
  1: i32 numOfItems ,
  2: list<Item> items
}

/**
 * Struct definition:
 * The return value of getKeys() method.
 */
struct Keys{
  1: i32 numOfKeys,
  2: list<string> key
}

/**
 * Structs can be exceptions, if they are nasty.
 */
exception InvalidOperation {
  1: i32 errorCode ,
  2: string message
}

/**
 * Definition of error code.
 */
enum ErrorCode {
  INVALID_OPERATION = 1
}

#
# ThBDB I/F list
#
# put               :Puts an item on the KVS
# putAsync          :Puts an item on the KVS ( Non-blocking mode )
# get               :Gets an item on the KVS
# remove            :Removes an item from the KVS
# getKeys           :List keys from the KVS
# getKeysByPosition :List range keys from the KVS
# ping              :Checks the KVS if it is alive
# hello              :Sample implementation
# getStatus :Returns the KVS status code
# compact   :Returns Compact status code 
service Basic
{
     void put( 1:string key, 2:string value ) throws (1:InvalidOperation exp ) ,
     oneway void putAsync( 1:string key, 2:string value )  ,
     bool exists( 1:string key ) throws (1:InvalidOperation exp ),
     string  get( 1:string key ) throws (1:InvalidOperation exp ),
     void remove( 1:string key ) throws (1:InvalidOperation exp ),
     Keys getKeys() throws (1:InvalidOperation exp ),
     Keys getKeysByPosition( 1:i32 position, 2:i32 size ) throws (1:InvalidOperation exp ),
     void ping(),
     string hello(1:string arg),
     i32 getStatus(),
     i32 compact() throws (1:InvalidOperation exp )
}