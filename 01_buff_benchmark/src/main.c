#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

static void check_argument(int argc, char **argv)
{
    int i =0;
    if (argc != 3) {
        goto boilout;
    }

    for(i = 0; i < strlen(argv[2]); i++) {
        if (isdigit((int)argv[2][i]) == 0 ) {
            goto boilout;
        }
    }

    return;

boilout:
    printf("usage: %s filename buffer_size(bytes)\n", argv[0]);
    printf("Ex: %s 1024K_file.dat 4096\n", argv[0]);
    exit(-1);
}

static void dump_file(char *name, size_t buffer_size)
{
    int rd_fd = 0;
    int wr_fd = 0;

    int read_bytes = 0;
    int write_bytes = 0;
    char buf[buffer_size];

    /* Open files */
    rd_fd = open(name, O_RDONLY);
    if(rd_fd == -1) {
        printf("open %s failed:%s\n", name, strerror(errno));
        return;
    }

    wr_fd = open("/dev/null", O_WRONLY);
    if(wr_fd == -1) {
        printf("open %s failed:%s\n", name, strerror(errno));
        goto boilout;
    }

    /* Read then write */
    while (1) {
        read_bytes = read(rd_fd, buf, buffer_size);
        if(read_bytes == -1) {
            printf("read failed:%s\n", strerror(errno));
            goto boilout;
        }

        write_bytes = write(wr_fd, buf, read_bytes);
        if(write_bytes == -1 || write_bytes != read_bytes) {
            printf("write failed:%s\n", strerror(errno));
            goto boilout;
        }

        if (read_bytes < buffer_size) {
            break;
        }
    }

boilout:
    if (rd_fd > 0) {
        close(rd_fd);
    }
    if (wr_fd > 0) {
        close(wr_fd);
    }
}

int main(int argc, char **argv)
{
    /* Check argument */
    check_argument(argc, argv);

    /* Read file and dump to /dev/null */
    dump_file(argv[1], (size_t)atoi(argv[2]));

    return 0;
}
