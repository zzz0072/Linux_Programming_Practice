#include "libb.h"
#include <stdio.h>

void test_liba(void)
{
    from_libb();
}

void from_liba()
{
    printf("%s\n", __PRETTY_FUNCTION__);
}
