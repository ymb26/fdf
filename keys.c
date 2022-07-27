/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshana <sshana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:18:40 by sshana            #+#    #+#             */
/*   Updated: 2022/05/16 21:20:34 by sshana           ###   ########.fr       */
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
	return (0);
}
