/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshana <sshana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 20:22:33 by sshana            #+#    #+#             */
/*   Updated: 2022/04/18 20:22:33 by sshana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_free(char **mass, int k)
{
	k--;
	while (k >= 0)
	{
		free (mass[k]);
		k--;
	}
	free (mass);
}

static int	ft_count(char const *s, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
			word++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (word);
}

static char	**ft_mas(char **mass, char const *s, char c, int word)
{
	int	i;
	int	countword;
	int	k;

	i = 0;
	k = 0;
	while (k < word)
	{
		countword = 0;
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i] != '\0')
		{
			i++;
			countword++;
		}
		mass[k] = (char *)malloc(sizeof(char) * (countword + 1));
		if (mass[k] == NULL)
		{
			ft_free(mass, k);
			return (NULL);
		}
		k++;
	}
	return (mass);
}

static char	**ft_copy_mas(char **mass, char const *s, char c, int word)
{
	int	i;
	int	k;
	int	x;

	i = 0;
	k = 0;
	while (k < word)
	{
		x = 0;
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i] != '\0')
		{
			mass[k][x] = s[i];
			i++;
			x++;
		}
		mass[k][x] = '\0';
		k++;
	}
	return (mass);
}

char	**ft_split(char const *s, char c)
{
	char	**mass;
	int		word;

	if (s == NULL)
		return (NULL);
	word = ft_count(s, c);
	mass = (char **)malloc(sizeof(char *) * (word + 1));
	if (mass == NULL)
		return (NULL);
	mass[word] = NULL;
	mass = ft_mas(mass, s, c, word);
	if (mass == NULL)
		return (NULL);
	mass = ft_copy_mas(mass, s, c, word);
	return (mass);
}
