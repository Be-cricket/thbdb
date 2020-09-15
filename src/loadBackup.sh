#!/bin/bash

CMDNAME=`basename $0`
if [ $# -ne 2 ]; then
  echo "Usage: ./$CMDNAME [backup_file] [db_file]"
  exit 1
fi

db_load $2 < $1
