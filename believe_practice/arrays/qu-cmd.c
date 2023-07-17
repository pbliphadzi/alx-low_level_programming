void execute_command(char *argv[], char *err_mesg)
{
pid_t pid;
int status:
/** The function checks if the command exists using access **/
if (access(args[0], F_OK) == -1)
{
perror(err_mesg);
return;
}
/** forks a new process **/
pid = fork();
if (pid < 0)
{
perror(err_mesg);
exit(EXIT_FAILURE);
}
else if (pid == 0)
{
/**Child process **/
execve(args[0], args, environ);
perror(err_msg);
exit(EXIT_FAILURE);
}
else
{
if (waitpid(pid, &status, 0) == -1)
{
perror(err_msg);
exit(EXIT_FAILURE);
}
}
}