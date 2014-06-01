#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <libintl.h>
#define MAX_CHAR (32)

#define QUOTE(x) #x
#define TO_STR(x) QUOTE(x)
#define ERRLINE(x) "Error at line " TO_STR(x)
int main(int argc, char **argv)
{
    char dest[MAX_CHAR];
    char transport[MAX_CHAR];
    char *p = 0;

    /* Init gettext related APIs*/
    p= setlocale(LC_ALL, "");
    if (!p) {
        perror(ERRLINE(__LINE__));
        exit(1);
    }
    printf("%s\n", p);

    p = bindtextdomain(PACKAGE, LOCALEDIR);
    if (!p) {
        perror(ERRLINE(__LINE__));
        exit(1);
    }
    printf("%s\n", p);

    p = textdomain(PACKAGE);
    if (!p) {
        perror(ERRLINE(__LINE__));
        exit(1);
    }
    printf("%s\n", p);

    /*- Set up strings */
    strncpy(dest, gettext("Taipei"), MAX_CHAR);
    strncpy(transport, gettext("bus"), MAX_CHAR);

    /*- Let's print out some message */
    printf(gettext("I will go to %s by %s\n"), dest, transport);

    return 0;
}
