#include <stdio.h>

int main(int argc, char* argv[])
{
    // Run Length Encoding
    // 4 byte integer + single ASCII character
    // Output to stdout
    char* filename = argv[1];
    FILE* readfile = fopen(filename, "r");
    if (readfile == NULL)
    {
        printf("File is not available \n");
    }

    // Initialize the first character
    char currentChar = fgetc(readfile);
    int counter = 1;
    char nextChar;

    while (1)
    {
        if (currentChar == -1) {
            break;
        }

        while (1)
        {
            nextChar = fgetc(readfile);
            if (currentChar != nextChar)
            {
                //fprintf(stdout, "%i%c", counter, currentChar);
                fwrite(&counter, sizeof(int), 1, stdout);
                fputc(currentChar, stdout);
                currentChar = nextChar;
                counter = 1;
                break;
            }
            counter++;
        }

    }
}