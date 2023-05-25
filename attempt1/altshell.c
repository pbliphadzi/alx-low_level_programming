#include "btshell.h"
#define MAX_COMMAND_LENGTH 100
/**
 * main - Entry point of the UNIX command line interpreter
 *
 * Return: Always 0 (success)
 */

int main() {
    char command[MAX_COMMAND_LENGTH];
    char prompt[] = "btshell$ ";

    while (1) {
        printf("%s", prompt);

        if (fgets(command, sizeof(command), stdin) == NULL) {
            printf("\n");
            break;
        }

        command[strcspn(command, "\n")] = '\0';

        if (strlen(command) == 0) {
            continue;
        }

        pid_t pid = fork();

        if (pid < 0) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            char* token = strtok(command, " ");
            char* args[MAX_COMMAND_LENGTH];
            int argIndex = 0;

            while (token != NULL) {
                args[argIndex++] = token;
                token = strtok(NULL, " ");
            }
            args[argIndex] = NULL;

            char* path = getenv("PATH");

            execve(args[0], args, path);

            perror("execve");
            exit(EXIT_FAILURE);
        } else {
            int status;
            waitpid(pid, &status, 0);
        }
    }

    return (0);
}







