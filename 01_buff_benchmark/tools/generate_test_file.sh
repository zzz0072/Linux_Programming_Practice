#!/bin/sh

read -p "Warning: This script will generate 500MB for testing: Continue(Y/n): " ans

if [ "$ans" != 'Y' ] ; then
    exit 2
fi

file_size="1 500 1024 512000"

# base data
for i in $file_size 
do
    echo Generating $i to test_data/${i}K_file.dat
    dd if=/dev/urandom of=test_data/${i}K_file.dat bs=1024 count=$i
done
