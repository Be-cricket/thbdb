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

