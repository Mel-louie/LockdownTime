#!/bin/sh

GBDK_DIR="$( cd "$( dirname "$0" )" && pwd )/.."

#set -x # print in the stdout the command execution

sdcc -mgbz80 --no-std-crt0 -I "$GBDK_DIR/include" -I "$GBDK_DIR/include/asm" -c "$@"
