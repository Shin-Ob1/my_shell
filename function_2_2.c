#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/* _getline - stores input characters as a string
 *
 * @lineptr: pointer to the bigining of the line
 * @n: number of bytes to be read
 *
 * Return: The number of characters read
 */

ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	ssize_t num_char_read = 0;
	int current_char = 0;
	
	*lineptr = (char *)malloc(100);
	if (lineptr == NULL || n == NULL)
	{
		return -1;
	}

	if (*lineptr == NULL)
	{
		*n = 128;
		*lineptr = (char *)malloc(*n);
		if (*lineptr == NULL)
		{
			return -1;
		}
	}

	while ((current_char = fgetc(stream)) != EOF)
	{
		if (num_char_read >= (*n - 1))
		{
			*n *= 2;
			*lineptr = realloc(*lineptr, *n);
			if (*lineptr == NULL)
			{
				return -1;
			}
		}
		(*lineptr)[num_char_read++] = current_char;

		if (current_char == '\n')
		{
			break;
		}		
	}
	(*lineptr)[num_char_read] = '\0';

	return (num_char_read == 0 && current_char == EOF) ? -1 : num_char_read;
}


int main (int argc, char **argv)
{
	char *lineptr;
	size_t n;
	ssize_t j;
	int i = 0;
	FILE *stream;

	if (argc != 2)
		exit(0);
	n = 10;
	stream = fopen(argv[1], "r");
	
	while (i < 30)
	{
		i++;
		j = _getline(&lineptr, &n, stream);
		write(STDOUT_FILENO, lineptr, j);
	}
	printf("\n");
	free(lineptr);
	fclose(stream);

	return 0;
}
	
