/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_parameters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshana <sshana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 20:59:20 by sshana            #+#    #+#             */
/*   Updated: 2022/05/15 18:39:09 by sshana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_x_length(t_fdf *head, char *line, int fd)
{
	int		length;
	char	**massive;

	massive = ft_split(line, ' ');
	if (!massive)
		ft_error_make_massive(head, fd, line);
	length = 0;
	while (massive[length])
		length++;
	free_massive(massive);
	head->length = length;
}

void	get_y_weight(t_fdf *head, char *infile)
{
	int		fd;
	char	*line;
	int		weight;

	fd = open(infile, O_RDONLY);
	if (fd == -1)
		ft_error_open_file(head, fd);
	weight = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (weight == 0)
			get_x_length(head, line, fd);
		weight++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	head->weight = weight;
}

void	make_value_massive(double *array, char *line, t_fdf *head, int fd)
{
	int		i;
	char	**massive;

	massive = ft_split(line, ' ');
	if (!massive)
	{
		ft_free_fdf(head);
		free(line);
		close(fd);
		perror("Error: ft_split for massive.\n");
		exit(1);
	}
	free(line);
	i = 0;
	while (massive[i])
	{
		array[i] = ((double)ft_atoi(massive[i]));
		i++;
	}
	array[i] = '\0';
	free_massive(massive);
}

void	malloc_for_z_massive(t_fdf *head)
{
	int	counter;

	head->value = (double **)malloc(sizeof(double *) * (head->weight + 1));
	if (!head->value)
		ft_error_malloc_two_dimendional_massive(head);
	counter = 0;
	while (counter <= head->weight)
	{
		head->value[counter] = (double *)malloc(sizeof(double) \
		* (head->length + 1));
		if (!head->value[counter])
			ft_error_malloc_link_of_two_dimendional_massive(head);
		counter += 1;
	}
}

void	get_z_massive(t_fdf *head, char *infile)
{
	int		fd;
	char	*line;
	int		counter;

	malloc_for_z_massive(head);
	fd = open(infile, O_RDONLY);
	counter = 0;
	while (counter < head->weight)
	{
		line = get_next_line(fd);
		make_value_massive(head->value[counter], line, head, fd);
		counter += 1;
	}
	free(head->value[counter]);
	head->value[counter] = NULL;
	close(fd);
}
