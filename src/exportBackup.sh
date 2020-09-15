#!/bin/bash

CMDNAME=`basename $0`
if [ $# -ne 2 ]; then
  echo "Usage: ./$CMDNAME [db_file] [backup_file]"
  exit 1
fi

db_dump -r $1 > $2
