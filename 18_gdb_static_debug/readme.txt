Use the following option to switch function

Default: Build without OP1 disable and same_func2.c

Make options
1. EN_OP1=1
    * Enable macro OP1
2. USE_FILE=1
    * Compile same_func1.c intead of same_func2.c

Examples:
1. make
    *  Build without OP1 disable and same_func2.c
2. make USE_FILE=1
    *  Build without OP1 disable and same_func1.c
3. make EN_OP1=1
    *  Build with OP1 disable and same_func2.c
4. make EN_OP1=1 USE_FILE=1
    *  Build with OP1 disable and same_func1.c
