#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>
#include <stdlib.h>

#define BUF_SIZE (32)
void readBuf(char *file_name)
{
    char buf[BUF_SIZE] = {0};
    char tmp_buf[3] = {0};
    int rval = 0;
    int i = 0;
    int j = 0;


    int fd = open(file_name, O_RDONLY);
    if (fd == -1) {
        printf("%s\n", strerror(errno));
        goto boil_out;
    }

    /* Read buf until EOF */
    while (1) {

        /* Let's read */
        rval = read(fd, tmp_buf, 2);
        if (rval <= 0) {
            printf("%s\n", rval == 0 ? "End of file" : strerror(errno));
            if (rval == 0) {
                break;
            }
            goto boil_out;
        }

        /* Validate chars and convert */
        if (tmp_buf[0] != '\n' && !(isxdigit(tmp_buf[0]) && isxdigit(tmp_buf[1]))) {
            printf("only hex character are allowed:%c, %c\n", tmp_buf[0], tmp_buf[1]);
            goto boil_out;
        }

        buf[i++] = (char) strtol(tmp_buf, NULL, 16);

    }

    /* Dump buffer */
    for (i = 0; i < BUF_SIZE/8; i++) {
        for (j = 0; j < 8; j++) {
            printf("%c", isxdigit(buf[i * 8 + j])? buf[i * 8 + j]: '.');
        }

        for (j = 0; j < 8; j++) {
            printf(" %.2x", buf[i * 8 + j]);
        }

        printf("\n");
    }

boil_out:
    if (fd) {
        close(fd);
    }
}

void hello()
{
    printf("Hello world\n");
}

int main(int argc, char **argv)
{
    /* Check argument */
    if (argc != 2) {
        printf("%s input_file_name\n", argv[0]);
        printf("input file name contains 32 2-digit hex chars. ex:\n");
        printf("0102030405060708091011121314151617181920212223242526272829303132\n");
        return 2;
    }

    /* Read data */
    readBuf(argv[1]);

    return 0;
}
