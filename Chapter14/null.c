#include <stdlib.h>
#include <stdio.h>

// Run valgrind --leak-check=yes ./null
int main (void)
{
    int* p = malloc(sizeof(int));
    // Dereferencing a null pointer causes segfault, always check for pointer == NULL -> error
    p = NULL;
    printf("%d\n", *p);

    free(p);
    return 0;
}