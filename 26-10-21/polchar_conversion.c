#include <stdio.h>
#include <string.h>




int main(int argc, char **argv) {
    if (argc <= 1) {
        printf("No args");
        return 0;
    }
    if (!strcmp(argv[1], "utf2win")) {
        char c1, c2;
        do {
            c1 = getchar();
            c2 = getchar();
            putchar(c1);
            putchar(c2);
        } while (c1 != EOF);
    }
    return 0;
}
