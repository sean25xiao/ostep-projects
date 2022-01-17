#include <stdio.h>
#include <stdlib.h>

#define DEBUG_MODE 0

int main(int argc, char **argv) {

    for (int i = 1; i < argc; i++) {  // argv[0] is the name of this file itself

        char *in_file_name = argv[i];

#if DEBUG_MODE == 1
        printf("The file name is %s \n", in_file_name);
#endif

        FILE *fp = fopen(in_file_name, "r");
        if (fp == NULL) {
            printf("wcat: cannot open file\n");
            exit(1);
        }

        int c = fgetc(fp);   // read first char
        while (c != EOF) {   // then keep reading next if not EOF
            putchar(c);
            c = fgetc(fp);
        }

        fclose(fp);
    }

    return 0;
}