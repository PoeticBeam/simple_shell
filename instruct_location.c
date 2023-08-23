#include "main.h"

/*
 * instruct_location - gets full path of commands
 *
 * @instruct: command passed to function
 * Return: NULL
 */

char *instruct_location(char *instruct)
{
	char *location;
	char *loc_cpy;
	const char *delim = (":");
	int instruct_len;
	char *loc_token;
	char *loc_token_tank;
	int dir_len;
	struct stat buffer;

	location = getenv("PATH");

	if (location)
	{
		loc_cpy = strdup(location);
		instruct_len = strlen(instruct);

		loc_token = strtok(loc_cpy, delim);


		while (loc_token != NULL)
		{

			dir_len = strlen(loc_token);
			/* allocate mem for the full path into loc_token_tank */
			/* we add 2 for the forward slash and null byte */
			/* ex: /usr/bin/ls >> directory path + forward slash */
			/* + instruct + null byte */
			loc_token_tank = malloc((instruct_len + dir_len + 2));

			/* appending each variable step-wise */
			strcpy(loc_token_tank, loc_token);
			strcat(loc_token_tank, "/");
			strcat(loc_token_tank, instruct);
			strcat(loc_token_tank, "\0");

			/* now, we check if path exists after it has */
			/* appended necessary characters */
			/* we return 0, which means path was correct/found */
			/* then free the memory */
			if (stat(loc_token_tank, &buffer) == 0)
			{
				free(loc_cpy);
				return (loc_token_tank);
			}

			/* if that fails, we need to delete path stored */
			/* in loc_token_tank and try another path */
			else
			{
				free(loc_token_tank);
				loc_token = strtok(NULL, delim);
			}
		}

		/* loop runs, returns NULL after path not found, then free */
		free(loc_cpy);

		/* THESE ARE JUST FINAL CHECKS */
		/* to assure that path to instruct was truly not found */
		if (stat(instruct, &buffer) == 0)
		{
			return (instruct);
		}

		return (NULL);
	}
	return (NULL);
}
