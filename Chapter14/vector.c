#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int* array;
    size_t used;
    size_t size;
} Array;

int main (void)
{
    Array arr;
    arr.array = malloc(8 *  sizeof(int));
    
    arr.used = 0;
    arr.size = 8;
    
    for (int i = 0; i < 100; i++)
    {
        if (arr.used == arr.size)
        {
            arr.size *= 2;
            arr.array = (int *) realloc(arr.array, arr.size * sizeof(int));
        }
        arr.array[arr.used] = i;
        arr.used++;
    }
    printf("%d\n", arr.array[0]);
    printf("%ld\n", arr.size);
    free(arr.array);

}