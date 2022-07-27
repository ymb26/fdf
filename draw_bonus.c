/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshana <sshana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 21:32:21 by sshana            #+#    #+#             */
/*   Updated: 2022/05/16 22:02:56 by sshana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h" 

void	you_are_the_best_bonus(t_fdf *head)
{
	mlx_string_put(head->mlx_ptr, head->win_ptr, 5, \
	850, 0x800080, "You are the best!");
	mlx_string_put(head->mlx_ptr, head->win_ptr, 5, \
	10, 0x800080, "Instruction.");
	mlx_string_put(head->mlx_ptr, head->win_ptr, 5, \
	30, 0xffffff, "UP/DOWN/LEFT/RIGHT : Move picture.");
	mlx_string_put(head->mlx_ptr, head->win_ptr, 5, \
	50, 0xffffff, "W/S : rotate picture in Y.");
	mlx_string_put(head->mlx_ptr, head->win_ptr, 5, \
	70, 0xffffff, "T/G : change z-projection.");
	mlx_string_put(head->mlx_ptr, head->win_ptr, 5, \
	90, 0xffffff, "Tab : reset settings.");
	mlx_string_put(head->mlx_ptr, head->win_ptr, 5, \
	110, 0xffffff, "Mouse wheel : zoom.");
	mlx_string_put(head->mlx_ptr, head->win_ptr, 5, \
	130, 0xffffff, "+/- on right: rotation.");
}

static void	three_d(double *x, double *y, double z, t_fdf *data)
{
	*x = (*x - *y) * cos(data->angle);
	*y = (*x + *y) * sin(data->angle) - z;
}

static void	set_color(double z, double z1, t_fdf *data)
{
	if ((z > 0) && (z1 > 0) && (z == z1))
		data->color = 0xe80c0c;
	else if ((z == 0) && (z1 == 0))
		data->color = 0xffffff;
	else if ((z < 0) && (z1 < 0) && (z == z1))
		data->color = 0x0000ff;
	else
		data->color = 0x800080;
}

void	bresenham(t_fdf *data, double x_next, double y_next)
{
	t_list	param;

	param.x = data->x;
	param.x1 = data->x + x_next;
	param.y = data->y;
	param.y1 = data->y + y_next;
	param.z = (double)data->value[(int)param.y][(int)param.x];
	param.z1 = (double)data->value[(int)param.y1][(int)param.x1];
	add_zoom(&param, data);
	set_color(param.z, param.z1, data);
	three_d(&param.x, &param.y, param.z, data);
	three_d(&param.x1, &param.y1, param.z1, data);
	add_shift(&param, data);
	param.x_step = param.x1 - param.x;
	param.y_step = param.y1 - param.y;
	param.max = find_max(mod(param.x_step), mod(param.y_step));
	param.x_step /= param.max;
	param.y_step /= param.max;
	while ((int)(param.x - param.x1) || (int)(param.y - param.y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, \
		param.x, param.y, data->color);
		param.x += param.x_step;
		param.y += param.y_step;
	}
}

void	draw(t_fdf *data)
{
	data->y = 0;
	while (data->y < data->weight)
	{
		data->x = 0;
		while (data->x < data->length)
		{
			if (data->x < (data->length - 1))
				bresenham(data, 1, 0);
			if (data->y < (data->weight - 1))
				bresenham(data, 0, 1);
			data->x += 1.0;
		}
		data->y += 1.0;
	}
	you_are_the_best_bonus(data);
}
