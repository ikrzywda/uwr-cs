#include <stdio.h>
#include <string.h>

const char kWinPolChars[18] = {165, 198, 202, 163, 209, 211, 140, 143, 175, 185, 
                        230, 234, 179, 241, 243, 156, 159};

const char kUTF8[18][2] = {{0xC4, 0x84},{0xC4,0x86},{0xC4,0x98},{0xC5,0x81},{0xC5, 0x83},
                            {0xC3,0x93},{ 0xC5,0x9A},{0xC5,0xB9},{0xC5,0xBB},{0xC4,0x85}, 
                            {0xC4,0x87},{ 0xC4,0x99},{0xC5,0x82},{0xC5,0x84},{0xC3,0xB3}, 
                            {0xC5,0x9B},{ 0xC5,0xBA},{0xC5, 0xBC}};                      

int process_char_pol(int c) {
    return 0; 
}

char process_char_utf(char c1, char c2) {
    char out;
    if (c1 == (char)0xC4 || c1 == (char)0xC3 || c1 == (char)0xC5) {
        for (int i = 0; i < 18; ++i) {
            if (kUTF8[i][1] == c2) {
                out = kWinPolChars[i];
                putchar(out);
            } 
        }
    } else {
        putchar(c1);
        putchar(c2);
    }
    return out;
}

int main(int argc, char **argv) {
    if (argc <= 1) {
        printf("No args");
        return 0;
    }
    if (!strcmp(argv[1], "utf2iso")) {
        char c1, c2;
        do {
            c1 = getchar();
            c2 = getchar();
            process_char_utf(c1, c2);
        } while (c1 != EOF);
    }
    return 0;
}
