/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshana <sshana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 01:35:54 by sshana            #+#    #+#             */
/*   Updated: 2022/05/15 19:10:03 by sshana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_error_malloc_struct(void)
{
	perror("Error: malloc fdf*.\n");
	exit(1);
}

void	ft_error_open_file(t_fdf *head, int fd)
{
	free(head);
	close(fd);
	perror("Error: open file.\n");
	exit(1);
}

void	ft_error_gnl(t_fdf *head, int fd)
{
	free(head);
	close(fd);
	perror("Error: gnl.\n");
	exit(1);
}

void	ft_error_make_massive(t_fdf *head, int fd, char *line)
{
	free(head);
	free(line);
	close(fd);
	perror("Error: massive.\n");
	exit(1);
}

void	ft_error_map(t_fdf *head)
{
	free(head);
	perror("Error: wrong map.\n");
	exit(1);
}
