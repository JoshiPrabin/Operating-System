#include <stdio.h>
#include <unistd.h>

int main()
{
    pid_t first_child_pid, second_child_pid;

    first_child_pid = fork();

    if (first_child_pid == 0)
    {
        printf("Hello from First Child! PID: %d\n", getpid());
    }
    else if (first_child_pid > 0)
    {
        second_child_pid = fork();

        if (second_child_pid == 0)
        {
            printf("Hello from Second Child! PID: %d\n", getpid());
        }
        else if (second_child_pid > 0)
        {
            printf("Hello from Parent! PID: %d\n", getpid());
        }
        else
        {
            fprintf(stderr, "Second fork failed\n");
            return 1;
        }
    }
    else
    {
        fprintf(stderr, "First fork failed\n");
        return 1;
    }

    return 0;
}
