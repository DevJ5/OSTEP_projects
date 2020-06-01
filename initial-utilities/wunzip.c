#include <stdio.h>

int main (int argc, char* argv[])
{
    if (argc < 2)
    {
        printf("Usage: wunzip [file]");
    }

    for (int i = 1; i < argc; i++)
    {
        printf("%s: ", argv[i]);
        FILE* fp = fopen(argv[i], "rb");
        int count;
        char c;
        // Loop as long as 1 element of size count is successfully read
        while (fread(&count, sizeof(count), 1, fp) == 1)
        {
            fread(&c, sizeof(c), 1, fp);
            for (int n = 0; n < count; n++)
            {
                printf("%c", c);
            }
        }
        printf("\n");
        fclose(fp);
    }
}