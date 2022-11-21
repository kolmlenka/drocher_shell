#include <errno.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

extern int
cmd_process(const char *);

const char *initstr = "[%s@%s]: ";

const int MAX_CMD_LEN = 4096;

int
main(int argc, char **argv, char **envp)
{
    printf("\003\nPenis project by kolenmka (aka drocher228)\n");
    while (true) {
        char cur_dir[PATH_MAX + 1];
        char *cmd = NULL;
        size_t cmd_size = MAX_CMD_LEN;
        getcwd(cur_dir, PATH_MAX);
        printf(initstr, getenv("USERNAME"), cur_dir);
        fflush(stdout);
        getline(&cmd, &cmd_size, stdin);
        int status = cmd_process(cmd);
        if (status) {
            printf("Error occured: %s\n", strerror(status));
        }
    }
}
