#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int cmd_exec(const char *cmd, char *const *args, int in_fileno,
             int out_fileno)
{
    dup2(STDIN_FILENO, in_fileno);
    dup2(STDOUT_FILENO, out_fileno);
    pid_t pid = fork();
    if (pid < 0) {
        fprintf(stderr, "Error: could not create subprocess\n");
        return -1;
    } else if (!pid) {
        execvp(cmd, args);
        return -1;
    } else {
        return 0;
    }
}