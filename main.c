#include "main.h"

int main(void)
{
	char *prompt = "SS-Shell >> ";
	char *linepointer = NULL;
	char *linepointercpy = NULL;
	size_t n = 0;
	ssize_t num_char_read;
	const char *delimiter = " \n";
	int token_counter = 0;
	int x;
	char *token;
	char **argv;
	/* int test_counter = 0; */

	/* declaring void variables */
	/* void(ac); */

	/* infinite loop */
	while (1)
	{
		printf("%s", prompt);
		num_char_read = getline(&linepointer, &n, stdin);

		/* checks if the getline function failed or reached EOF or user CtrlD */
		if (num_char_read == -1)
		{
			printf("\nLogging off <<<   \n");
			exit(EXIT_FAILURE);
		}

		/* memory allocation using return value of num_char to linepointercopy */
		linepointercpy = malloc(sizeof(char) * num_char_read);
		if (linepointercpy == NULL)
		{
			perror("tsh: memory allocation failed");
			return (-1);
		}

		/* copies string in linepointer to linepointercopy */
		strcpy(linepointercpy, linepointer);

		/*now we separate by delimiter, str linepointer into array of words */
		token = strtok(linepointer, delimiter);

		/* let's see how many tokens */
		while (token != NULL)
		{
			token_counter++;
			token = strtok(NULL, delimiter);
		}
		token_counter++;
		/* array to store string tokens after counting characters */
		argv = malloc(sizeof(char *) * token_counter);

		/* we first allocated space to store the array, */
		/* now we store str tokens in array */
		token = strtok(linepointercpy, delimiter);

		for (x = 0; token != NULL; x++)
		{
			argv[x] = malloc(sizeof(char *) * strlen(token));
			strcpy(argv[x], token);

			token = strtok(NULL, delimiter);
		}
		argv[x] = NULL;

		exec(argv);
	}
	/* free allocated mem */
	free(argv);
	free(linepointercpy);
	return (0);
}
