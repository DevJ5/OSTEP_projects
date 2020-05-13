#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
//extern int errno;

int main(int argc, char* argv[])
{
    FILE* fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        printf("Errno: %d\n", errno);
        printf("%s\n", strerror(errno));
        exit(1);
    }

    
    char c;

    while ((c = fgetc(fp)) != EOF)
    {
        printf("%c", c);
    }

    printf("\n");
    fclose(fp);

    return 0;
}