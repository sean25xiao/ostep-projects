#include <stdio.h>
#include <stdlib.h>

#define DEBUG_MODE 0

int main(int argc, char **argv) {

    if (argc == 1) {
        printf("wgrep: searchterm [file ...]\n");
        exit(1);
    }

        char *in_file_name = argv[1];

#if DEBUG_MODE == 1
        printf("The file name is %s \n", in_file_name);
#endif

        FILE *fp = fopen(in_file_name, "r");
        if (fp == NULL) {
            printf("wgrep: cannot open file\n");
            exit(1);
        }
}