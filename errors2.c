/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshana <sshana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 02:19:44 by sshana            #+#    #+#             */
/*   Updated: 2022/05/15 19:10:07 by sshana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_error_malloc_two_dimendional_massive(t_fdf *head)
{
	free(head);
	perror("Error: malloc for z_massive.\n");
	exit(1);
}

void	ft_error_malloc_link_of_two_dimendional_massive(t_fdf *head)
{
	ft_free_fdf(head);
	perror("Error: malloc for z_massive.\n");
	exit(1);
}

void	ft_free_fdf(t_fdf *head)
{
	int	j;

	j = 0;
	while (j <= head->weight)
	{
		free(head->value[j]);
		j++;
	}
	free(head->value);
	head->mlx_ptr = NULL;
	head->win_ptr = NULL;
	head->arg = NULL;
	free(head);
}

void	free_massive(char **massive)
{
	int	i;

	i = 0;
	while (massive[i])
	{
		free(massive[i]);
		i++;
	}
	free(massive[i]);
	free(massive);
}
