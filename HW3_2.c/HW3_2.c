#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    // check if filename provided
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filaname>\n", argv[0]);
        exit(1);
    }

    //open file
    FILE *fp = fopen(argv[1], "r");
    // check if opened
    if (fp == NULL) {
        fprintf(stderr, "Unable to open file: %s\n", argv[1]);
        exit(1);
    }

    // create a buffer
    char buf[BUFSIZ];

    // fgets will return NULL if
    // it cannot read further
    while(fgets(buf, BUFSIZ, fp) ) {
        // print
        printf("%s", buf);
    }

    // close file
    fclose(fp);
    return 0;
}
