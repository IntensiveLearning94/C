#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char* argv[]) {

    //open file for output
    FILE *fp = fopen("output.txt", "w");
    // check if opened
    if (fp == NULL) {
        fprintf(stderr, "Unable to open output.txt\n");
        exit(1);
    }

    // Here I am creating a buffer size called BUFSIZ
    char buf[BUFSIZ];
    // read from user
    printf("Enter a string: ");
    fgets(buf, BUFSIZ, stdin);

    // write to output file
    fprintf(fp, "%s", buf);
    // close file
    fclose(fp);
    return 0;
}
