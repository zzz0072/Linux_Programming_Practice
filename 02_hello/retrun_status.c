/* This demos return status */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int rval = 0;

    if (argc != 2) {
        printf("usage: %s return_status_number(0~255)\n", argv[0]);
        printf("Then observe return status in $?\n");
        printf("ex: $ %s 121; echo $?\n", argv[0]);

        return 2;
    }

    /* Convert return status to 0~255*/
    rval = atoi(argv[1]);
    rval = rval % 255;

    return rval;
}
