#include <stdio.h>

int main(void)
{
    int a = __INT_MAX__;
    int b = 3;
    size_t sum = a + b;

    /* It is overflow */
    if (a + b < 0) {
        printf("oops.. %d + %d = %d\n", a, b, a + b);
        printf("oops.. %d + %d = %zu\n", a, b, sum);
    }

    /* Check overflow
     * idea: a + b > __INT_MAX__ => a > __INT_MAX__ - b */

    if ( a > __INT_MAX__ - b) {
        printf("There are integer overflow\n");
    }

    return 0;
}
