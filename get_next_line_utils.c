/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshana <sshana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 17:02:25 by sshana            #+#    #+#             */
/*   Updated: 2022/05/15 16:59:03 by sshana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s || !c)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*check_ft_strjoin(char *line)
{
	char	*str;

	if (!line)
	{
		str = (char *)malloc(sizeof(char) * 1);
		str[0] = '\0';
		return (str);
	}
	return (line);
}

char	*ft_strjoin(char *line, char *buff)
{
	char	*str;
	int		i;
	int		j;

	line = check_ft_strjoin(line);
	if (!line || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(line) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	while (line[++i] != '\0')
		str[i] = line[i];
	while (buff[j] != '\0')
	{
		str[i] = buff[j];
		i++;
		j++;
	}
	str[i] = '\0';
	free(line);
	return (str);
}

char	*ft_one_line(char *s_line)
{
	char	*str;
	int		i;

	i = 0;
	if (!s_line[i])
		return (NULL);
	while (s_line[i] && s_line[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s_line[i] && s_line[i] != '\n')
	{
		str[i] = s_line[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_new_line(char *s_line)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s_line[i] && s_line[i] != '\n')
		i++;
	if (!s_line[i])
	{
		free(s_line);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(s_line) - i + 1));
	if (!str)
		return (NULL);
	i = i + 1;
	while (s_line[i] != '\0')
		str[j++] = s_line[i++];
	str[j] = '\0';
	free(s_line);
	return (str);
}
