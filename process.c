#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> // for wait()

int main() {
    pid_t pid;

    // Create a new process using fork()
    pid = fork();

    if (pid < 0) {
        // Error handling if fork() fails
        perror("fork failed");
        exit(1);
    } else if (pid == 0) {
        // This block is executed by the child process
        printf("Child process created with PID: %d\n", getpid());
        printf("Child process terminating.\n");
        exit(0); // Terminate the child process
    } else {
        // This block is executed by the parent process
        printf("Parent process created with PID: %d\n", getpid());

        // Wait for the child process to terminate
        wait(NULL);
        printf("Child process terminated. Parent process exiting.\n");
        exit(0); // Terminate the parent process
    }

    return 0;
}
