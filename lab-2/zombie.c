#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(1);
    }

    if (pid == 0) {
        printf("Child process (PID %d) exiting\n", getpid());
        exit(0);
    } else {
        printf("Parent process (PID %d) sleeping\n", getpid());
        sleep(60);

        printf("Parent process exiting\n");
    }

    return 0;
}
