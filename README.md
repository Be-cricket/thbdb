# ThBDB
Berkeley db with thrift 

## Create the development environment
- Install docker 
- Change direcotry to /docker
- Execute the following command
    
    "docker run -it -v xxxx/:/root --cap-add=SYS_PTRACE --security-opt="seccomp=unconfined" Be-cricket/cont_for_thbdb"

    xxxx/: Your local working directory that has your source codes is mounted to /root on the docker.

    You can execute any development commands including make, gcc, and gdb.

## API Specifications
[ThBDB server APIs](doc/API_spec.md)

## Required libraries
- glib2.0 (recomended version, 2.64.3)
- berkeleydb (recommended version, 18.1.40)
- thrift_c_glib (recommended version, 0.13.0)

## Compile sources
- Change directory to /src
- Execute the following command
    
    "./configure"

    "make"

## Run thbdb server
- Change directory to /src
- Execute the following command
    
    "./server"

- If you would like to use particular db file, execute the following command

    "./server -d [db_file]"

## Get value of particular key from thbdb
- Run thbdb server
- Change directory to /test
- Execute the following command
    
    "./idl.sh"

    "./thbdbCat.sh <host> <port> <key>"

    Needs python2 environment to run this command.

## Create backup of db file
- Change directory to /src
- Execute the following command

    "./exportBackup.sh <db_file> <backup_file>"

## Load from backup
- Change directory to /src
- execute the following command
    
    "./loadBackup.sh <backup_file> <db_file>"
