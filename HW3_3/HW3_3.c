#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    // check if filename provided
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filaname>\n", argv[0]);
        exit(1);
    }

    //open file in binary mode
    FILE *fp = fopen(argv[1], "rb");
    // check if opened
    if (fp == NULL) {
        fprintf(stderr, "Unable to open file: %s\n", argv[1]);
        exit(1);
    }

    // create a buffer
    char buf[BUFSIZ];
    int len;

    while ((len = fread(buf, sizeof(char), BUFSIZ, fp)) != 0) {
        // print on console
        for (int i = 0; i < len; i++) {
            printf("%x", buf[i]);
        }
    }

    // close file
    fclose(fp);
    return 0;
}
