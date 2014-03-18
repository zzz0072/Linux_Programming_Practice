#!/bin/sh
size="1 500 1024 512000"

for i in $size 
do
    echo Generating $i to 1kb_file_for_size${i}K.dat
    dd if=/dev/urandom of=test_data/1kb_file_for_size${i}K.dat bs=1024 count=$i
done

