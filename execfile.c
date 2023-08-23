#include "main.h"

/*
 * exec - executes command or instruct passed to argv
 * @argv: pointer to delimited command
 *
 * Return: void
 */

void exec(char **argv)
{
	char *instruct = NULL;
	char *instruct_with_path = NULL;

	/* if command passed to first position in array not NULL */
	/* instruct with path is the new command with link to the /usr/bin path */
	if (argv)
	{
		instruct = argv[0];

		instruct_with_path = instruct_location(instruct);

		if (execve(instruct_with_path, argv, NULL) == -1)
		{
			perror("Error:");
		}
	}
}
