#include "btshell.h"
/**
 * main - entry point of the btshell program
 * @argc: the number of command-line arguments
 * @argv: an array of strings containing the command-line arguments
 *
 * Return: Always 0 (success)
 */
int main(int argc, char *argv[]) 
{
    size_t BUFF = 0;
    char *LINE = NULL;
    int A;
    int comnum = 1;
    int shinteract;
    pid_t pid;
    char *args[2];

    /* Use signal function that will ignore the signal specified by the first argument */
    signal(SIGINT, SIG_IGN);

    /* Check if the shell is in interactive or non-interactive mode */
    shinteract = isatty(STDIN_FILENO);
    if (shinteract == 0 && argc == 1) {
        ssize_t line_l;
        while ((line_l = getline(&LINE, &BUFF, stdin)) != -1) {
            write(STDOUT_FILENO, "Command: ", 9);
            write(STDOUT_FILENO, LINE, line_l);
            LINE[line_l - 1] = '\0';  /*Remove the newline character at the end*/

            /*Tokenize the command line into arguments*/
             char* token = strtok(LINE, " "); // Split the command line by spaces
            int argIndex = 0;
            while (token != NULL) {
                args[argIndex++] = token;
                token = strtok(NULL, " ");
            }
            args[argIndex] = NULL;

            /*Fork a new process to execute the command*/
            pid = fork();
            if (pid < 0) {
                perror("fork");
                exit(EXIT_FAILURE);
            } else if (pid == 0) {
                /*Child process*/
                execve(args[0], args, NULL);
                /*If the command execution failed, print an error message*/
                perror("execve");
                exit(EXIT_FAILURE);
            } else {
                /* Parent process */
                int status;
                waitpid(pid, &status, 0);
            }
        }
        free(LINE);
        return 0;
    }

    while (shinteract) {
        write(STDOUT_FILENO, "btshell $", 11);
        A = getline(&LINE, &BUFF, stdin);
        if (A < 0) {
            free(LINE);
            write(STDOUT_FILENO, "\n", 1);
            break;
        }
        write(STDOUT_FILENO, "Command: ", 9);
        write(STDOUT_FILENO, LINE, A);
        LINE[A - 1] = '\0';  /*Remove the newline character at the end*/

        /*Tokenize the command line into arguments*/
        args[0] = LINE;
        args[1] = NULL;

        /*Fork a new process to execute the command*/
        pid = fork();
        if (pid < 0) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            /*Child process*/
            execve(args[0], args, NULL);
            /*If the command execution failed, print an error message*/
            perror("execve");
            exit(EXIT_FAILURE);
        } else {
            /* Parent process */
            int status;
            waitpid(pid, &status, 0);
        }

        comnum++;
        LINE = NULL;
    }

    return 0;
}
