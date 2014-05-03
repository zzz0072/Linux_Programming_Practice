#include <stdio.h>
#include <stdlib.h> /* stdlib */
#include <unistd.h> /* unlink */
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
    /* Create a temp file */
    char tmp_file[] = "XXXXXX";
    char buf[8 * 1024] = {0};
    int fd = 0;
    int rval = 0;

    printf("This program demostrates system removes file as soon as" \
            "close() was call atfer unlink()\n");
    printf("We do not have new file: XXXXXX at beginning\n");
    fd = open(tmp_file, O_CREAT| O_WRONLY);
    if (fd == -1) {
        perror("open: ");
    }

    printf("\nCreate new file: XXXXXX\n");
    system("ls");
    printf("File space in K\n");
    system("df `pwd`");
    rval = unlink(tmp_file);
    if (rval == -1) {
        perror("unlink: ");
    }

    printf("\nAfter unlink, we can still manage file: XXXXXX\n");
    system("ls");
    rval = write(fd, buf, 8 * 1024);
    if (rval == -1) {
        perror("write: ");
    }

    printf("\nWrite 8k, disk space in K now increased\n");
    system("df `pwd`");
    rval = close(fd);
    if (rval == -1) {
        perror("close: ");
    }

    printf("\nAfter close() file: XXXXXX is removed\n");
    system("ls");
    printf("File space in K now\n");
    system("df `pwd`");

    return 0;
}
