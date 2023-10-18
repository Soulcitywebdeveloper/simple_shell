#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100
/**
 * main - accept input
 *
 * Return: Always 0.
 */
int main(void)
{
	char *command = NULL;
	size_t command_length = 0;

	while (1)
	{
		printf("$");
		fflush(stdout);


		ssize_t input_length = getline(&command, &command_length, stdin);


	if (input_length == -1)
	{
		break;
	}


	command[strcspn(command, "\n")] = '\0';


	if (strcmp(command, "") == 0)
	{
		continue;
	}
	else if (system(command) == -1)
	{
		fprintf(stderr, "Error executing command: %s\n", command);
	}


	}

	free(command);
	return (0);
}
