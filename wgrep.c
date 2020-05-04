#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXCHAR 1000

void usage(void);

int main(int argc, char* argv[]) {
    if (argc != 3) 
    {
        usage();
    }

    FILE* fp;
    size_t size = 80;
    char* line = NULL;
    char* searchterm = argv[1];
    char* filename = argv[2];

    // Open file
    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("wgrep: cannot open file\n");
        exit(1);
    }

    while (getline(&line, &size, fp) != -1)
    {
        char* result = strstr(line, searchterm);
        if (result != NULL)
        {
            printf("%s", line);
        }

    }

    // Getline reallocates memory using realloc under the hood.
    // char line[MAXCHAR];
    // while (fgets(line, MAXCHAR, fp) != NULL)
    // {
    //     char* result = strstr(line, searchterm);
    //     if (result != NULL) 
    //     {
    //         printf("%s", line);
    //     }
    // }

    return 0;
}

void usage(void) {
    printf("Usage: wgrep [searchterm] [file]\n");
    exit(1);
}