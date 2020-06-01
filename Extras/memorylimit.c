#include <sys/time.h>
#include <sys/resource.h>
#include <stdlib.h>
#include <stdio.h>

void setmemlimit(char*);

int main(int argc, char **argv)
{
        setmemlimit(argv[1]);
        int* numbers = malloc(100);

        for (int i = 0; i<= 100; i++)
        {
            numbers[i] += 1;
            if (i == 100) 
                i = 0;
        }


        return 0;
}

void setmemlimit(char* numberOfMB)
{
        struct rlimit memlimit;
        long bytes;

        if(numberOfMB != NULL)
        {
            printf("Memory limit set\n");
            bytes = atol(numberOfMB)*(1024*1024);
            memlimit.rlim_cur = bytes;
            memlimit.rlim_max = bytes;
            setrlimit(RLIMIT_AS, &memlimit);
        }
}