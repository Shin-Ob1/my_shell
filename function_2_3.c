#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *_strtok(char *str, const char *delim)
{
	static char *last_token;
	char *token;
	int j = 0, i = 0;

	
	/* If called with NULL argument, continue from last token found*/
	if (str == NULL)
	{
		if (last_token == NULL)
		{
			return NULL;
		}
		str = last_token;
	}
	
	/* Find the start of the next token */
	while (str[j] != '\0' && strchr(delim, str[j]) == NULL)
	{
		j++;
	}	
	token = malloc(sizeof(char) * j);

	for (i = 0; i < j; i++)
	{
		token[i] = str[i];
		str[i] = '\0';		
	}
	token[j] = '\0';

	if (str[j] == '\0')
	{
		last_token =  NULL;
		return(token);
	}
	str = &str[j + 1];
	last_token = str;
	

	return(token);
}

/* main - tests the _strtok function
 *
 * Return: Aways 0
i */

int main(void)
{
	char str[30] = "They are very good";
	char *piece;

	piece = _strtok(str, " ");
	while (piece != NULL)
	{
		printf("String is : %s\n", piece);
		piece = _strtok(NULL, " ");
	}
	return 0;
}


