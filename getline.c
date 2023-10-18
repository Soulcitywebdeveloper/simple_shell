#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100
/**
 * main - accept input
 *
 * Return: Always 0.
 */
int main(void)
{
	char command[MAX_COMMAND_LENGTH];
	int status;

	while (1)
	{
		printf("$ ");

	if (fgets(command, sizeof(command), stdin) == NULL)
	{

		printf("\n");
		break;
	}

	command[strcspn(command, "\n")] = '\0';

		pid_t pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{

		if (execlp(command, command, (char *)NULL) == -1)
		{

			perror(command);
			exit(EXIT_FAILURE);
		}
	}
	else
	{

		waitpid(pid, &status, 0);
	}
	}

	return (0);
}
