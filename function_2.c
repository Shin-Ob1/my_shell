#include <stdio.h>
#include <stdlib.h>

/*ssize_t getline(char **restrict lineptr, size_t *restrict n, FILE *restrict stream);*/

/* main - tests the functions
 *
 * Return: Always 0
 */

int main (void)
{
	char *ptr, *line;
	int i = 0, s = 0;
	char c;

	while (c = getchar() != '\n')
	{
		if (i == s)
		{
			s = (s == 0)? 1: s * 2;
			ptr  = (char *)realloc(ptr, s);
			if (ptr == NULL)
			{
				printf("Error: Unable to allccate memory");
				exit(EXIT_FAILURE);
			}
		}
		ptr[i] = c;
		i++;
		printf("ptr[%d]: %c\n", i, c);
	}
	if (i == 0 && c == EOF)
	{
		return 0;
	}
	ptr[i] = '\0';
	printf("You typed: %s\n", ptr);
	return 0;
}
