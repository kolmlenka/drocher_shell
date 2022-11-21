#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

const char *initstr = "[%s@%s]: ";

enum
{
    MAX_CMD_LEN = 4096
};

int main(int argc, char **argv, char **envp)
{
    printf("Penis project by kolenmka (aka drocher228)\n");
    while (true) {
        char cur_dir[PATH_MAX + 1];
        char cmd[MAX_CMD_LEN + 1];
        getcwd(cur_dir, PATH_MAX);
        printf(initstr, getenv("USERNAME"), cur_dir);
        scanf("%s", cmd);
        fflush(stdout);
    }
}
