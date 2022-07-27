/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mod.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshana <sshana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 16:17:36 by sshana            #+#    #+#             */
/*   Updated: 2022/05/15 18:36:41 by sshana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	add_zoom(t_list *param, t_fdf *data)
{
	param->x *= data->zoom;
	param->x1 *= data->zoom;
	param->y *= data->zoom;
	param->y1 *= data->zoom;
}

void	add_shift(t_list *param, t_fdf *data)
{
	param->x += data->shift_x;
	param->y += data->shift_y;
	param->x1 += data->shift_x;
	param->y1 += data->shift_y;
}

int	find_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

double	mod(double i)
{
	if (i < 0)
		return (-i);
	return (i);
}
