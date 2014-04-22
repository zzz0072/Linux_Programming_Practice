#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Test offset and arrays of length zero */
struct s_offset_t
{
    int   first;
    char  second;
    float third;
    char  *ptr;
    char  z_arr[]; /* C99 style */
};

void show_offset(struct s_offset_t *s_offset)
{
    printf("Struct start addr: %p\n", s_offset);
    printf("first(int): %p \n", &(s_offset->first));
    printf("second(char): %p \n", &(s_offset->second));
    printf("third(float): %p \n", &(s_offset->third));
    printf("ptr(char *): %p \n", &(s_offset->ptr));
    printf("z_arr(char []): %p \n", &(s_offset->z_arr));
}

#define STR "Hello World"
int main(void)
{
    /* Let's see offset */
    struct s_offset_t *s_offset = 0;

    show_offset(s_offset);

    /* Now let's allocate data for zero */
    s_offset = (struct s_offset_t *) malloc(sizeof(struct s_offset_t) +
                                                    strlen(STR));
    if (s_offset == 0) {
        printf("Oops, malloc failed\n");
        exit(1);
    }

    strcpy(s_offset->z_arr, STR);
    show_offset(s_offset);
    printf("%s\n", s_offset->z_arr);

    if (s_offset) {
        free(s_offset);
        s_offset = 0;
    }
    return 0;
}
