#!/bin/bash
set STAGE0="$1"
set STAGE1="pre$1"
set TESTINP="$2"
echo $STAGE0
echo $STAGE1
./preproc.exe "$STAGE0 $STAGE1" 
./Dict.exe $STAGE1 $TESTINP
