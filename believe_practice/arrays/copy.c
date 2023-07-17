#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(void) {
    char *command_input = NULL;
    char *ccmd = NULL;
    size_t n = 0;
    ssize_t nread_char; 
    char *toks;
    const char *dlimeter = " \n";
    char **argv;
    int i = 0;
    int num_toks = 0;

    /* qb_strcpy(ccmd, command_input); */ 
    /* print a prompt for the user to type something */
    write(STDOUT_FILENO, "$ ", 2);

    /* get the string that the user types in and pass it to command_input */
    nread_char= getline(&command_input, &n, stdin);

    /* let's allocate space to store the characters read by getline */
    ccmd = malloc(sizeof(char) * nread_char);

    if (ccmd == NULL) {
        perror("tsh: memory allocation error");
        return (-1);
    }

    /* make a copy of the command that was typed */
    qb_strcpy(ccmd, command_input);

    /* check if the getline function failed or reached EOF or user use CTRL + D */
    if (nread_char == -1) {
        write(STDOUT_FILENO, "Exiting shell....\n", 18);
        return (-1);
    } else {
        /* split the string (command_input) into an array of words */
        toks = strtok(command_input, dlimeter);

        /* allocate space to store the variable arguments but before then determine how many tokens are there */
        while (toks != NULL) {
            num_toks++;
            toks = strtok(NULL, dlimeter);
        }
        num_toks++;
        // printf(">>>>> %d \n", num_toks);

        /* use malloc to allocate enough space for the pointer to the argument variables */
        argv = malloc(sizeof(char *) * num_toks);

        toks = strtok(ccmd, dlimeter);

        for (i = 0; toks != NULL; i++) {
            argv[i] = malloc(sizeof(char) * qb_strlen(toks));
            qb_strcpy(argv[i], toks);

            // printf(">>>>> %s \n", argv[i]);
            toks = strtok(NULL, dlimeter);
        }
        argv[i] = NULL;

        /* execute the commands with execve */

if (execve(argv[0], argv, NULL) == -1) {
            perror("tsh: execve failed");
            return (-1);


        free(argv);
        free(command_input);
        free(ccmd);
    }

    return (0);
}

char qb_strcpy(char* destination, const char* source, size_t num_chars)
{
    size_t copied_chars = 0;

    for (copied_chars = 0; copied_chars < num_chars && *(source + copied_chars) != '\0'; copied_chars++)
    {
        *(destination + copied_chars) = *(source + copied_chars);
    }

    for (; copied_chars < num_chars; copied_chars++)
    {
        *(destination + copied_chars) = '\0';
    }

    return destination;
}
