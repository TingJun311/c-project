#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

unsigned int malloc_count(char *str)
{
	unsigned int c;

	c = 0;
	while (*str)
	{
		if (*str == 32 || (*str >= 9 && *str <= 13))
			c++;
		while (*str && (*str == 32 || (*str >= 9 && *str <= 13)))
			str++;
		str++;
	}
	if (*str == '\0')
		c++;
	return (c);
}

unsigned int count_word(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] && (str[i] != 32 || !(str[i] >= 9 && str[i] <= 13)))
		i++;
	return (i);
}

unsigned int count(char	*str)
{
	unsigned int j;

	j = 0;
	while(str[j])
		j++;
	return (j);
}

char	**ft_split(char *str)
{
	char	**matrix;
	unsigned int oc;
	unsigned int ic;
	unsigned int c;

	while (*str && (*str == 32 || (*str >= 9 && *str <= 13)))
		str++;
	c = malloc_count(str);
	matrix = (char **)malloc(sizeof(char *) * (c + 1));
	if (matrix == NULL || c == 0)
	{
		free(matrix);
		return (NULL);
	}
	oc = 0;
	while (oc < c)
	{
		ic = count_word(str);
		matrix[oc] = (char *)malloc(sizeof(char) * (ic + 1));
		ic = 0;
		while (*str)
		{
			if (*str == 32 || (*str >= 9 && *str <= 13))
				break;
			matrix[oc][ic] = *str;
			ic++;
			str++;
		}
		matrix[oc][ic] = '\0';
		while (*str && (*str == 32 || (*str >= 9 && *str <= 13)))
			str++;
		oc++;
	}
	matrix[oc] = '\0';
	return (matrix);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, &*str, 1);
		str++;
	}
	write(1, "\n", 1);

}

int	main(int ac, char **av)
{
	char	**str;
	int	o;

	if (ac == 2)
	{
		o = 0;
		str = ft_split(av[1]);
		while (str[o])
		{
			ft_putstr(str[o]);
			o++;
		}
		free(str);

	}
	else
		write(1, "\n", 1);	
	return (0);
}
