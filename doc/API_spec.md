# ThBDB Server API specification

ThBDB server communicates with the ThBDB clients.  
This document indicates APIs the ThBDB server has.  

Following: API specification.


## BASIC:
### put( k:string, v:string )  
  Puts on the BDB that ThBDB contains.
  Associates the specified key(k:string) with the specified value(v:string) int the ThBDB.

### putAsync( k:string, v:string )
  Puts on the BDB asynchronusly.

### string get( k:string )
  Returns the value(v:string) with which the specified key(k:string) associates.

### remove( k:string )
  Removes the specified key(k:string) and value(v:string) pair associated with it from the ThBDB.

### Keys getKeys()
  Returns key list from the ThBDB.
  Key list contains all of keys in the ThBDB.

  
### Keys getKeysByPosition(position:i32, size:i32)
  Returns key list from the ThBDB.
  Key list contains keys in the ThBDB between position to positon + size .
  
### boolean exists( k:string )
  Returns true if the specified key(k:string) exsists in the TbBDB.


## OPERATION:


### initialize
  UNDER CONSTRUCTION
  
### open
  UNDER CONSTRUCTION
  
### close
  UNDER CONSTRUCTION
  
### void ping()
  To check this thbdb is alive.

### i32 getStatus()
  Returns a status that the internal bdb's status.

  + THBDB_STATUS_DB_RUNNING
    - if BDB isn't null
  + THBDB_STATUS_DB_NOT_OPEND
    - if BDB is null.

### i32 compact()
  Compact to the internal bdb.
  
  + 0
    - success
  + non-zero error code
    - refer [DB->compact error code](https://docs.oracle.com/cd/E17276_01/html/api_reference/C/dbcompact.html)
