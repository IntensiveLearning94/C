#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char* argv[]) {
    // check if filename provided
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <fileaname>\n", argv[0]);
        exit(1);
    }

    //open file
    FILE *fp = fopen(argv[1], "r");
    // check if opened
    if (fp == NULL) {
        fprintf(stderr, "Unable to open file: %s\n", argv[1]);
        exit(1);
    }

    // now file has been open
    // seek to the end of file
    fseek(fp, 0, SEEK_END);
    // now ftell will return the size of file
        long file_size = ftell(fp);
    // close file
    fclose(fp);
    // print
    printf("The file '%s' is %ld bytes in size\n", argv[1], file_size);

    return 0;
}
