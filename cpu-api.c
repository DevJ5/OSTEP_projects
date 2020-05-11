#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int question1();
int question2();

int main(void)
{
    //question1();
    question2();


    return 0;
}

int question1()
{
    int x = 100;
    int rc = fork();

    if (rc < 0)
    {
        fprintf(stderr, "Something went wrong with fork.");
        return 1;
    }
    else if (rc == 0)
    {
        x = 101;
        printf("Child_PID: %i \tx = %i\n", (int) getpid(), x);
    }
    else
    {
        x = 102;
        printf("Parent_PID: %i \tx = %i\n", (int) getpid(), x);
    }

    printf("x is %i\n", x);
}

int question2()
{
    // open returns a file descriptor
    int fd_parent = open("foo.txt", O_RDWR | O_CREAT);
    int rc = fork();

    if (rc < 0)
    {
        fprintf(stderr, "Something went wrong with fork.");
        return 1;
    }
    else if (rc == 0)
    {
        printf("Inside child process %d", (int) getpid());
        int fd_child = open("foo.txt", O_RDWR | O_APPEND);
        write(fd_child, "foobar\n", strlen("foobar\n"));
        printf("\tWrite child\n");
        close(fd_child);
    }
    else
    {
        printf("Inside parent process %d", (int) getpid());
        char* greeting = "hello world";
        int sz = write(fd_parent, greeting, strlen(greeting));
        printf("\tWrite parent\n");
        //int fd_parent2 = open("foo.txt", O_RDWR | O_CREAT);
        //char arr[4];
        //read(fd_parent2, arr, 45);
        //arr[3] = '\0';
        //printf("%s\n", arr);
        printf("Bits written: %d\n", sz);
        close(fd_parent);
    }
    return 0;
}