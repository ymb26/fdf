/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshana <sshana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 16:38:04 by sshana            #+#    #+#             */
/*   Updated: 2022/05/16 20:59:05 by sshana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move_picture(int key, t_fdf *data)
{
	if (key == 123)
		data->shift_x -= 10;
	if (key == 124)
		data->shift_x += 10;
	if (key == 126)
		data->shift_y -= 10;
	if (key == 125)
		data->shift_y += 10;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
}

void	change_angle(int key, t_fdf *data)
{
	if (key == 78)
		data->angle += 0.1;
	if (key == 69)
		data->angle -= 0.1;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
}

void	reset(t_fdf *data)
{
	set_default(data);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
}

void	rotate_image(t_fdf *data)
{
	data->angle *= -1;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
}

void	change_z(int key, t_fdf *data)
{
	int	length;
	int	weigth;

	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	weigth = 0;
	while (weigth < data->weight)
	{
		length = 0;
		while (length < data->length)
		{
			if ((data->value[weigth][length] > 0) && (key == 17))
				data->value[weigth][length] *= 1.05;
			if ((data->value[weigth][length] < 0) && (key == 17))
				data->value[weigth][length] *= 1.05;
			if ((data->value[weigth][length] > 0) && (key == 5))
				data->value[weigth][length] /= 1.05;
			if ((data->value[weigth][length] < 0) && (key == 5))
				data->value[weigth][length] /= 1.05;
			length++;
		}
		weigth++;
	}
	draw(data);
}
