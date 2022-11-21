#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

extern const int MAX_CMD_LEN;

struct CmdNode
{
    struct CmdNode *l, *r;
    char *value;
};

struct CmdNode *
new_node(const char *src)
{
    struct CmdNode *cmdn = malloc(sizeof(struct CmdNode));
    cmdn->l = NULL;
    cmdn->r = NULL;
    asprintf(&cmdn->value, "%s", src);
    return cmdn;
}

int cmd_process(const char *cmd_line)
{
    char *cmd = calloc(MAX_CMD_LEN + 1, sizeof(char));
    
    free(cmd);
    return 0;
}

int cmd_exec(const char *cmd, char *const *args, int in_fileno, int out_fileno)
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