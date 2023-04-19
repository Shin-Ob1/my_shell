#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "main.h"

/**
 * buffer_split - splits the buffer into array of strings
 * @i: number of tokens
 * @bufcpy: input string
 *
 * Return: a pointer to an array of pointers to strings
 */

char **buffer_split(int i, char *bufcpy)
{
	char **argv;
	char *token;
	int j;

	argv = malloc(sizeof(char *) * i);
	token = strtok(bufcpy, " ");
	/* assigning input arguments to an array of strings*/
	for (j = 0; token != NULL; j++)
	{
		argv[j] = malloc(sizeof(char) * strlen(token));
		if (j != i - 1)
		{
			strcpy(argv[j], token);
		}
		else
		{
			strncpy(argv[j], token, strlen(token) - 1);
		}
		token = strtok(NULL, " ");
	}
	argv[j] = NULL;

	return (argv);
}

/**
 * release_strings - releases split strings
 * @argv: pointer to array of strings
 * @i: number of tokens
 *
 * Return: NULL
 */

void release_strings(char **argv)
{
	int j;

	j = 0;
	while (argv[j] != NULL)
	{
		free(argv[j]);
		j++;
	}
}


