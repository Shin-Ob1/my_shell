#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <dirent.h>

/* main - ads /bin to anexisting input command
 *
 * Return: always 0
 */

int main(void)
{
	DIR *dir;
	char *fn, *fname, *nfname;
	char req_dir[1024] = "/bin/";
	struct dirent* entity;
	
	dir = opendir(req_dir);
	fn = "ls";
	if (dir == NULL)
	{
		return 1;
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
			return 0;
		}		
		entity = readdir(dir);
	}
	closedir(dir);

	return 1;
}
