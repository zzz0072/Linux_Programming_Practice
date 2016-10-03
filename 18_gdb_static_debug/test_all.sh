#!/bin/sh
echo "default settings: OP1 disable and use same_func1.c"
make clean && make && ./test_same_func
echo "======================================================="
echo "Build with EN_OP1=1"
make clean && make EN_OP1=1 && ./test_same_func
echo "======================================================="
echo "Build with USE_FILE=1"
make clean && make USE_FILE=1 && ./test_same_func
echo "======================================================="
echo "Build with EN_OP1=1 USE_FILE=1"
make clean && make EN_OP1=1 USE_FILE=1 && ./test_same_func
