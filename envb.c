#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"
#include <string.h>
/**
 * env_builtin - Print the current environment
 */
void env_builtin(void)
{
	extern char **environ;
	char **env = environ;

	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
}

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char command[100];

	if (strcmp(command, "env") == 0)
	{
		env_builtin();
	}

	return (0);
}
