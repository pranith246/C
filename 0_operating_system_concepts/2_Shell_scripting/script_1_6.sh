#!/bin/bash
# Author	:	kirito_ys
	
file=$1

cat $1
set `wc -lwc $file`
echo "lines: " $1 " words: " $2 "characters: " $3
