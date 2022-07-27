/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshana <sshana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 21:16:42 by sshana            #+#    #+#             */
/*   Updated: 2022/05/16 22:03:04 by sshana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	take_x_y_z(t_fdf *head, char *argv)
{
	get_y_weight(head, argv);
	if ((head->weight == 0) || (head->length == 0))
		ft_error_map(head);
	if ((head->weight == 1) && (head->length == 1))
		ft_error_map(head);
	set_default(head);
}

static int	ft_cross(void *head)
{
	t_fdf	*head2;

	head2 = (t_fdf *)head;
	if (head2)
		ft_free_fdf(head2);
	exit (0);
	return (0);
}

void	malevich_mode(t_fdf *head)
{
	head->mlx_ptr = mlx_init();
	head->win_ptr = mlx_new_window(head->mlx_ptr, 1300, 900, "FDF");
	draw(head);
	mlx_hook(head->win_ptr, 17, 0, ft_cross, head);
	mlx_key_hook(head->win_ptr, deal_key, head);
	mlx_mouse_hook(head->win_ptr, mouse_key, head);
	mlx_loop(head->mlx_ptr);
}

static void	check_argv(char *arg)
{
	size_t	len;

	len = ft_strlen(arg);
	if ((arg[len - 4] == '.') && arg[len - 3] == 'f' \
	&& arg[len - 2] == 'd' && arg[len - 1] == 'f')
		return ;
	else
	{
		ft_putstr_fd("Not .fdf file\n", 1);
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	t_fdf	*head;

	if (argc == 2)
	{
		check_argv(argv[1]);
		head = (t_fdf *)malloc(sizeof(t_fdf));
		if (!head)
			ft_error_malloc_struct();
		head->mlx_ptr = NULL;
		head->win_ptr = NULL;
		head->value = NULL;
		head->arg = argv[1];
		take_x_y_z(head, argv[1]);
		malevich_mode(head);
		ft_free_fdf(head);
	}
	else
	{
		ft_putstr_fd("Wrong arguments.\n", 1);
		exit(0);
	}
	return (0);
}
