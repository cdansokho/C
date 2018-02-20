
#include "unistd.h"
#include <stdlib.h>

void	my_putchar(char c);

int    getNbWords(char *str)
{
	int counter;
	int i;

	counter = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
		{
			counter++;
		}
		i++;
	}
	return (counter);
}

void    processWords2(int i, int a, char **words, char *str)
{
	int e;

	e = 0;
	while (str[i + e] && str[i + e] != ' ' && str[i + e] != ' ')
	{
		if ((str[i + e] >= 'A' && str[i + e] <= 'Z')
			|| (str[i + e] >= 'a' && str[i + e] <= 'z')
			|| (str[i + e] >= '0' && str[i + e] <= '9'))
		{
			words[a][e] = str[i + e];
		}
		e++;
	}
	words[a][e] = '\0';
}

void	processWords(int i, int a, char **words, char *str)
{
	while (str[i] != 1)
	{
		if ((str[i] == ' ' && str[i + 1] && str[i + 1] != ' ') || i == 0)
		{
			while (str[i] <= ' ')
			{
				i++;
			}
			words[a] = malloc(sizeof(char) * 64);
			processWords2(i, a, words, str);
			a++;
		}
		i++;
	}
	words[a] = NULL;
}

char    **banishVoiders(char **words, int nb_words)
{
	int i;
	int a;
	char **words_processed;

	i = 0;
	a = 0;
	words_processed = malloc(sizeof(words) * nb_words * 64);
	while (words[i])
	{
		if (words[i][0] > ' ')
		{
			words_processed[a] = words[i];
			a++;
		}
		i++;
	}
	free(words);
	return (words_processed);
}

char	**my_str_to_wordtab(char *str)
{
	char **words;
	int i;
	int a;
	int nb_words;

	i = 0;
	a = 0;
	nb_words = getNbWords(str);
	words = malloc(sizeof(char) * nb_words * 64);
	processWords(i, a, words, str);
	words = banishVoiders(words, nb_words);
	return (words);
}
