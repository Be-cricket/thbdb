# ThBDB Server API specification

ThBDB server communicates with the ThBDB clients.

This document indicates APIs the ThBDB server has.

Following: API specification.


## BASIC:
### put( k:string, v:string )  
  Puts on the BDB that ThBDB contains.
  Associates the specified key(k:string) with the specified value(v:string) int the ThBDB.
  
### putAsync( k:string, v:string )
  Puts on the BDB asynchronusly
  
### v:string get( k:string )
  Returns the value(v:string) with which the specified key(k:string) associates.
  
### remove
  
### getKeys
  
### exist


## OPERATION:

  initialize
  
  open
  
  close
  
  unlink
