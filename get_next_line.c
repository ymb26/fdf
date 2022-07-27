/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshana <sshana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:33:14 by sshana            #+#    #+#             */
/*   Updated: 2022/05/15 19:10:23 by sshana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*ft_all_lines(int fd, char *s_line)
{
	char	*buf;
	int		byte_in_line;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	byte_in_line = 1;
	while (!ft_strchr(s_line, '\n') && byte_in_line != 0)
	{
		byte_in_line = read(fd, buf, BUFFER_SIZE);
		if (byte_in_line == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[byte_in_line] = '\0';
		s_line = ft_strjoin(s_line, buf);
	}
	free(buf);
	return (s_line);
}

char	*get_next_line(int fd)
{
	static char	*s_line;
	char		*mini_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	s_line = ft_all_lines(fd, s_line);
	if (!s_line)
		return (NULL);
	mini_line = ft_one_line(s_line);
	s_line = ft_new_line(s_line);
	return (mini_line);
}
