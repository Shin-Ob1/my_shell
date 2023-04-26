#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <dirent.h>
#include "main.h"

/**
 * main - a simple shell program
 * @av: an array of input parameters
 * @ac: number of input parameters from the terminal
 * @env: the environment variable
 *
 * Return: does not return
 */

int main(int ac, char **av, char **env)
{
	char *buffer;
	char **argv;
	char *bufcpy;
	char *fn;
	size_t len = 0;
	char *token;
	pid_t id;

	buffer  = (char *)malloc(1024);
	env = NULL;
	if (ac != 1)
	{
		perror("");
	}
	bufcpy = (char *)malloc(1024);

	/* never ending loop to keep the shell always active*/
	while (1)
	{
		/*fn[50] = "ls";
		fn = ch_fn(fn);*/
		printf("#cisfun$ ");			
		getline(&buffer, &len, stdin);
		strcpy(bufcpy, buffer);
		token = strtok(buffer, " ");

		/* execute the shell program in the child process*/
		while (token != NULL)
		{
			token = strtok(NULL, " ");
			i++;
		}
		free(buffer);
		argv = buffer_split(i, bufcpy);
		free(bufcpy);
		argv[0] = fn;
		id = fork();
		int i = 0, check;

		/* only child proces would enter this loop*/
		if (id == 0)
		{
			check = execve(argv[0], argv, env);
			if (check == -1)
			{
				dprintf(STDERR_FILENO, "%s: ", av[0]);
				perror("");
				exit(99);
			}
		}
		else
		{
			wait(NULL);
			/*release_strings(*argv);*/
			/*free(argv);*/
		}
	}
}


