#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int* arr = malloc(100 * sizeof(int));
    // Invalid write of size 4, because block size 400 is allocated. Nothing is allocated for index 100
    arr[100] = 0;
    free(arr);
    // Invalid read of size 4, Access memory after free
    printf("%d\n", arr[2]);

    int* arr2 = malloc(50 * sizeof(int));
    // Free an address inside the array, causes abort of the program (invalid pointer)
    free(arr + 3);
    return 0;
}