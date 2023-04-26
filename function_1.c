#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
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

/**
 * ch_wd - changes the current working directory
 * @dir: pointer to a string ewith directory path
 *
 * Return: 0 if fails and 1 if success
 */

char *ch_fn(char *fn)
{
	DIR *dir;
	char *fname, *nfname;
	struct dirent* entity;	
	char req_dir[1024] = "/bin/";

	dir = opendir(req_dir);
	/*fn = "ls";*/
	if (dir == NULL)
	{
		return NULL;
	}

	entity = readdir(dir);
	printf("fn = %s\n", fn);
	while (entity != NULL)
	{
		fname = entity->d_name;
		/*printf("%s\n", entity->d_name);*/
		if (strcmp(fname, fn) == 0)
		{
			printf("function found\n");
			nfname = (char *)malloc(1024);
			nfname = strcat(req_dir, fname);
			printf("New function: %s\n", nfname);
			closedir(dir);
			return (nfname);
		}		
		entity = readdir(dir);
	}
	closedir(dir);

	return NULL;
}


/**
 * char *ch_fn(char *fn)
{
	DIR *dir;
	char *nfn;
	struct dirent *entity;
		
	dir = opendir("/bin");
	if (dir == NULL)
	{
		printf("Opening /bin directory failed\n");
		exit(99);
	}
	entity = readdir(dir);
	while (entity != NULL)
	{
		if (entity->d_name == fn)
		{
			printf("function exists in/bin\n");
		}
		entity = readdir(dir);
	}
	nfn = fn;
	closedir(dir);
	return (nfn);
}*/


