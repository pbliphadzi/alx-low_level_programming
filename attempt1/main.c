#include 'btshell.h'

bool is_delimiter(char c)
{
    return (c == ' ' || c == '\t' || c == '\n');
}

int main(int argc, char *argv[])
{
    size_t BUFF = 0;
    char *LINE = NULL;
    int A;
    int nbtok = 0;
    int comnum = 1;
    int shinteract;

    int ret = signal(SIGINT, SIG_IGN);
    if (ret == SIG_ERR)
    {
        perror("Failed to set signal handler");
        exit(1);
    }

    shinteract = isatty(STDIN_FILENO);
    if (shinteract == 0 && !isatty(STDIN_FILENO))
    {
        ssize_t line_l;
        while ((line_l = getline(&LINE, &BUFF, stdin)) != -1)
        {
            int nbtok = nbcount(LINE);
            parse(LINE, nbtok, argv, comnum);
        }
        free(LINE);
        return 0;
    }

    while (shinteract)
    {
        write(1, "btshell$", 9);
        nbtok = 0;
        A = getline(&LINE, &BUFF, stdin);
        if (A < 0)
        {
            free(LINE);
            write(1, "\n", 1);
            break;
        }
        bool in_token = false;
        for (int j = 0; j < A; j++)
        {
            if (is_delimiter(LINE[j]))
            {
                in_token = false;
            }
            else if (!in_token)
            {
                nbtok++;
                in_token = true;
            }
        }
        parse(LINE, nbtok, argv, comnum);
        comnum++;
        LINE = NULL;
    }
    return 0;
}

int nbcount(const char *line)
{
    int count = 0;
    int length = strlen(line);
    bool in_token = false;

    for (int i = 0; i < length; i++)
    {
        if (line[i] == ' ' || line[i] == '\t' || line[i] == '\n')
        {
            in_token = false;
        }
        else if (!in_token)
        {
            count++;
            in_token = true;
        }
    }

    return count;
}

void parse(const char *line, int nbtok, char *argv[], int comnum)
{
    printf("Command: %s\n", line);
    printf("Number of Tokens: %d\n", nbtok);
    printf("Command Number: %d\n", comnum);

    int arg_index = 0;
    char *token = strtok((char *)line, " \t\n");
    while (token != NULL)
    {
        argv[arg_index] = token;
        arg_index++;
        token = strtok(NULL, " \t\n");
    }

    printf("Tokens:\n");
    for (int i = 0; i < arg_index; i++)
    {
        printf("%d: %s\n", i + 1, argv[i]);
    }
}
