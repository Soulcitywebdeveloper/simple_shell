#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
/**
 * main - Entry point
 *
 * Return: 0 on success.
 */
int main(void)
{
	char command[100];
	int status;
	pid_t child_pid;

	while (1)
	{
		printf("#simple_shell$ ");
		if (fgets(command, sizeof(command), stdin) == NULL)
		{
		break;
		}

	command[strcspn(command, "\n")] = '\0';

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (child_pid == 0)
	{
		if (execlp(command, command, (char *)NULL) == -1)
		{
			perror("execlp");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
	}
	}

	return (0);
}
