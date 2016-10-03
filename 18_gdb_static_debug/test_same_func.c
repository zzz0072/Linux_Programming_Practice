#include <stdio.h>
extern void func1(void);
extern void func2(void);

int main()
{
    printf("Hello World\n");
    func1();

    return 0;
}
