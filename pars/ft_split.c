#include "../minishell.h"

static int	word_num(char const *s, char c)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			while (s[i] && s[i] != c)
			{
				i++;
			}
			n++;
		}
	}
	return (n);
}

static int	word_len(char const *s, char c, int i)
{
	int	a;

	a = 0;
	while (s[i] && s[i] != c)
	{
		i++;
		a++;
	}
	return (a);
}

static char	**alloc(char **p, const char *s, int i, char c)
{
	int	j;
	int	k;

	j = 0;
	while (s[i])
	{
		k = 0;
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			p[j] = malloc(sizeof(char) * (word_len(s, c, i) + 1));
			if (!p[j])
				return (NULL);
			while (s[i] && s[i] != c)
				p[j][k++] = s[i++];
			p[j++][k] = '\0';
		}
	}
	p[j] = NULL;
	return (p);
}

char	**ft_split(char *s, char c)
{
	char	**p;
	int		i;

	p = malloc(sizeof(char *) * (word_num(s, c) + 1));
	if (!p)
		return (NULL);
	i = 0;
	alloc(p, s, i, c);
	return (p);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		len_s1;
	int		len_s2;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
		j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

size_t	ft_strlen(const	char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

// #include <stdio.h>
// #include <readline/readline.h>
// #include <readline/history.h>

// // Replace this with your implementation of ft_split
// char **ft_split(const char *str, char delimiter);

// int main() {
//     char *input = readline("Enter a line: ");

//     if (input) {
//         // Split the input using your ft_split function
//         char **tokens = ft_split(input, ' ');

//         if (tokens) {
//             for (int i = 0; tokens[i] != NULL; i++) {
//                 printf("Token %d: %s\n", i, tokens[i]);
//             }
//         }

//         // Free the input and token arrays
//         free(input);

//         // You need to implement freeing the tokens array here
//         // (based on how your ft_split function allocates memory)
//     }

//     return 0;
// }
