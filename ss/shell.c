#include <stdio.h>
#include <unistd.h>

int main() {
    if (isatty(STDIN_FILENO)) {
        const char prompt[] = "$ ";
        write(STDOUT_FILENO, prompt, sizeof(prompt) - 1);
    }

    char input[100];
    fgets(input, sizeof(input), stdin);
    printf("You entered: %s", input);

    return 0;
}