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
  
### string get( k:string )
  Returns the value(v:string) with which the specified key(k:string) associates.
  
### remove( k:string )
  Removes the specified key(k:string) and value(v:string) pair associated with it from the ThBDB.
  
### Keys getKeys()
  Returns key list from the ThBDB.
  Key list contains all of keys in the ThBDB.
  
### boolean exist( k:string )
  Returns true if the specified key(k:string) exsists in the TbBDB.

## OPERATION:

  initialize
  
  open
  
  close
  
  unlink
