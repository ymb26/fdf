/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshana <sshana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 21:19:51 by sshana            #+#    #+#             */
/*   Updated: 2022/05/16 21:58:33 by sshana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_key(int key)
{
	char	*str;

	str = ft_itoa(key);
	ft_putstr_fd(str, 1);
	ft_putstr_fd("\n", 1);
	free(str);
}

static void	escape_exit(t_fdf *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	ft_free_fdf(data);
	exit(0);
}

int	deal_key(int key, t_fdf *data)
{
	print_key(key);
	if (key == 53)
		escape_exit(data);
	if (key == 123 || key == 124 || key == 125 || key == 126)
		move_picture(key, data);
	if (key == 78 || key == 69)
		change_angle(key, data);
	if (key == 13 || key == 1)
		rotate_image(data);
	if (key == 17 || key == 5)
		change_z(key, data);
	if (key == 48)
		reset(data);
	return (0);
}

int	mouse_key(int key, int x, int y, t_fdf *data)
{
	(void)x;
	(void)y;
	print_key(key);
	if (key == 4 || key == 5)
	{
		if (key == 4)
			data->zoom += 1;
		if (key == 5)
			data->zoom -= 1;
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		draw(data);
	}
	return (0);
}
