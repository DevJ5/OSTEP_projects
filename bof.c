// A C program to demonstrate buffer overflow 
#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
  
int main(int argc, char *argv[]) 
{ 
    // char buf2[16] = "overwriteme";
    // char buf1[16];

    // strcpy(buf1, "");

    // printf("buf1 val: %s\n", buf1);
    // printf("buf2 val: %s\n", buf2);

    // printf("buf1 addr: %p\n", buf1);
    // printf("buf2 addr: %p\n", buf2);

    char *buf3 = malloc(12 * sizeof(char));
    char *buf4 = malloc(12 * sizeof(char));
    
    strcpy(buf4, "mywordshere");
    strcpy(buf3, "12345678901234567890123456789012A");
    
    printf("buf3 val:  %s\n", buf3);
    printf("buf4 val:  %s\n", buf4);
    printf("buf3 addr: %p\n", (void *)buf3);
    printf("buf4 addr: %p\n", (void *)buf4);





} 
