/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshana <sshana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 16:00:23 by sshana            #+#    #+#             */
/*   Updated: 2022/05/16 21:31:44 by sshana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_default(t_fdf *head)
{
	int	j;

	head->zoom = 20;
	head->shift_x = 600;
	head->shift_y = 300;
	head->angle = 1.0;
	j = 0;
	if (head->value)
	{
		while (j <= head->weight)
		{
			free(head->value[j]);
			j++;
		}
		free(head->value);
	}
	get_z_massive(head, head->arg);
}
