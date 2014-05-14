#include "liba.h"
#include <stdio.h>

void test_libb(void)
{
    from_liba();
}

void from_libb()
{
    printf("%s\n", __PRETTY_FUNCTION__);
}
