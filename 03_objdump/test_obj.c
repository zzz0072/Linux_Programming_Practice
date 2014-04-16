#include <stdio.h>
#include <string.h>

#define MAX_CHARS (32)

extern char _binary_my_data_txt_start;
extern char _binary_my_data_txt_end;
extern int _binary_my_data_txt_size;

int main(int argc, char **argv)
{
    char line[MAX_CHARS] = {0};
    char *my_data_start_addr = (char *) &_binary_my_data_txt_start;
    int str_len = (char) *my_data_start_addr - 0x30; /* 0x30 => '0' */

    if (str_len > MAX_CHARS) {
        str_len = MAX_CHARS;
    }

    strncpy(line, my_data_start_addr + 1, str_len);

    printf("_binary_my_data_txt_start: %c\n", _binary_my_data_txt_start);
    printf("_binary_my_data_txt_end: %c\n", _binary_my_data_txt_end);
    printf("_binary_my_data_txt_size: %p\n", &_binary_my_data_txt_size);
    printf("Read string is %s\n", line);

    return 0;
}
