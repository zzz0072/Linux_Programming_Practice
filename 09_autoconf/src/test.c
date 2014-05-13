#include "libb.h"
#include "liba.h"
#include <stdlib.h>
int main(void)
{
    int *p = 0;
    test_liba();
    test_libb();

    p = (int*) malloc(100);
    return 0;
}
