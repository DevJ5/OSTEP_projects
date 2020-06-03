#include <stdlib.h>
#include <stdio.h>

int main (void)
{
    int* vector = malloc(2 * sizeof(int));
    int n;
    scanf("%d", &n);
    printf("%d\n", n);
}