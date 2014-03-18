#!/bin/bash
test_prog="build/buf_bench"
if [ ! -f $test_prog ] ; then
    exit 1
fi

file_size="1 500 1024 512000"
buf_size="100 4096 8192 16384"
for i in $buf_size
do
   for j in $file_size 
   do
       echo -e "\ntime $test_prog test_data/${j}K_file.dat $i"
       time $test_prog test_data/${j}K_file.dat $i
   done
done
