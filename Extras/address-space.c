#include <stdlib.h>
#include <stdio.h>
int main(void)
{
    int x = 5;
    printf("Code: \t%p\n", main);
    printf("Heap: \t%p\n", malloc(100e6));
    printf("Stack: \t%p\n", &x);
}