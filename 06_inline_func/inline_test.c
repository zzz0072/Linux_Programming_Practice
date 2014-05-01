#include <stdio.h>
#ifdef GNU_C_TEST
inline void hello()
{
    int i = 100;
    printf("Hello World: %d\n", i);
}

extern void hello()
{
    printf("Hello World 2\n");
}
#else
inline void hello()
{
    printf("Hello World 2\n");
}
#endif

int main(void)
{
    hello();

    return 0;
}
