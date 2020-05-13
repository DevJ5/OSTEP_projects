#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>

int question1();
int question2();
int question3();
int question4();
int question6();
int question7();

int main(void)
{
    //question1();
    //question2();
    //question3();
    //question4();
    //question6();
    //question7();
    //question8();
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

int question3()
{
    int fd = open("foo.txt", O_RDWR | O_APPEND);
    int rc = fork();

    if (rc < 0) 
    {
        fprintf(stderr, "Something went wrong with fork.");
        return 1;
    }
    else if (rc == 0)
    {
        write(fd, "hello\n", strlen("hello\n"));
    }
    else
    {
        sleep(1);
        char* greeting = "goodbye\n";
        write(fd, greeting, strlen(greeting));
    }

    return 0;
}

int question4()
{
    int rc = fork();

    if (rc < 0)
    {
        fprintf(stderr, "Something went wrong with fork.");
        return 1;
    }
    else if (rc == 0)
    {
        // char* args[2];
        // args[0] = "ls";
        // args[1] = '\0';
        //execvp("ls", args);
        execlp("ls", "ls", (void*)0);
        printf("The child process won't get here...");
    }
    else
    {
        printf("The parent process: %d\n", getpid());
    }
    return 0;
}

int question6()
{
    int rc = fork();
    if (rc < 0)
    {
        fprintf(stderr, "Something went wrong with fork.");
        exit(1);
    }
    else if (rc == 0)
    {
        printf("Rc: %d\n", rc);
        printf("Child process: %d\n", getpid());
    }
    else
    {
        printf("Rc: %d\n", rc);
        waitpid(rc, NULL, WUNTRACED | WCONTINUED);
        printf("Parent process: %d\n", getpid());
    }
}

int question7()
{
    int rc = fork();
    if (rc < 0)
    {
        fprintf(stderr, "Something went wrong with fork.");
        return 1;
    }
    else if (rc == 0)
    {
        close(STDOUT_FILENO);
        printf("Child_PID: %i\n", getpid());
    }
    else
    {
        printf("Parent_PID: %i\n",getpid());
    }
}

int question8()
{
    // Inititalize a pipe filedescriptor with a reading part [0] and a writing part [1]
    int pipefd[2];
    // Initialize an array for 2 process return codes
    pid_t rc[2];
    // Create pipe
    if (pipe(pipefd))
    {
        fprintf(stderr, "Pipe failed.\n");
        return EXIT_FAILURE;
    }
    // Create first child
    rc[0] = fork();

    if (rc[0] < 0)
    {
        fprintf(stderr, "Something went wrong with fork.");
        exit(1);
    }
    else if (rc[0] == 0)
    {
        // Close the reading end
        close(pipefd[0]);
        char* greeting = "hello from first child\n";
        // Write to the writing end
        write(pipefd[1], greeting, strlen(greeting));
        // Close the writing end
        close(pipefd[1]);
    }
    else
    {
        // In the parent create another child process
        rc[1] = fork();
        char buffer;
        if (rc[1] < 0)
        {
            fprintf(stderr, "Something went wrong with fork.");
            exit(1);
        }
        else if (rc[1] == 0)
        {
            close(pipefd[1]);
            // Read 1 character into the memory address of the buffer
            while (read(pipefd[0], &buffer, 1) > 0)
            {
                // Print to stdout
                printf("%c", buffer);
            }
            close(pipefd[0]);

        }
        else
        {
            printf("Parent continues here.\n");
        }
        return 0;
    }
}