#!/bin/bash

CMDNAME=`basename $0`
if [ $# -ne 3 ]; then
  echo "Usage: ./$CMDNAME [host] [port] [key]"
  exit 1
fi

HOST=$1
PORT=$2
KEY=$3

python client_get.py $HOST $PORT $KEY
