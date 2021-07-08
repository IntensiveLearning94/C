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
    FILE *fPointer = fopen(argv[1], "r");
    // check if opened
    if (fPointer == NULL) {
        fprintf(stderr, "Unable to open file: %s\n", argv[1]);
        exit(1);
    }

    // now file has been open
    // seek to the end of file
    fseek(fPointer, 0, SEEK_END);
    // now ftell will return the size of file
        long file_size = ftell(fPointer);
    // close file
    fclose(fPointer);
    // print
    printf("The file '%s' is %ld bytes in size\n", argv[1], file_size);

    return 0;
}
