#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXCHAR 1000

void usage(void);

int main(int argc, char* argv[]) {
    if (argc < 2) 
    {
        usage();
    }

    FILE* fp;
    size_t size = 80;
    char* line = NULL;
    char* searchterm = argv[1];
    if (argc == 2) 
    {
        getline(&line, &size, stdin);
        char* result = strstr(line, searchterm);
        if (result != NULL)
        {
            printf("%s", line);
        }
    }
    else
    {
        for (int i = 2; i < argc; i++)
        {
            char* filename = argv[i];

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
                    printf("%s: %s", filename, line);
                }

            }
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