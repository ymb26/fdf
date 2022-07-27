/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshana <sshana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:56:43 by sshana            #+#    #+#             */
/*   Updated: 2022/05/16 21:53:58 by sshana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <stdlib.h>
# include <string.h> 
# include <unistd.h>
# include <stdio.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <mlx.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

typedef struct s_data
{
	double	**value;
	double	angle;
	double	x;
	double	y;
	char	*arg;
	int		length;
	int		weight;
	int		color;
	int		zoom;
	int		shift_y;
	int		shift_x;
	void	*mlx_ptr;
	void	*win_ptr;
}	t_fdf;

typedef struct s_param
{
	double	x_step;
	double	y_step;
	double	z;
	double	z1;
	double	x;
	double	x1;
	double	y;
	double	y1;
	int		max;
}	t_list;

void		ft_error_malloc_struct(void);
void		ft_error_open_file(t_fdf *head, int fd);
void		ft_error_gnl(t_fdf *head, int fd);
void		ft_error_make_massive(t_fdf *head, int fd, char *line);
void		ft_error_map(t_fdf *head);
void		ft_error_malloc_two_dimendional_massive(t_fdf *head);
void		ft_error_malloc_link_of_two_dimendional_massive(t_fdf *head);
void		ft_free_fdf(t_fdf *head);
void		free_massive(char **massive);

int			ft_isdigit(int c);
int			ft_isspace(int c);
int			ft_tab(const char *str, int i);
long int	ft_atoi(const char *str);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
char		**ft_split(char const *s, char c);
size_t		ft_strlen(const char *ch);
char		*ft_itoa(int n);
char		*ft_strchr(char *s, int c);
char		*ft_strjoin(char *line, char *buff);
char		*ft_one_line(char *s_line);
char		*ft_new_line(char *s_line);
char		*ft_all_lines(int fd, char *s_line);
char		*get_next_line(int fd);

void		get_x_length(t_fdf *head, char *line, int fd);
void		get_y_weight(t_fdf *head, char *infile);
void		make_value_massive(double *array, char *line, t_fdf *head, int fd);
void		malloc_for_z_massive(t_fdf *head);
void		get_z_massive(t_fdf *head, char *infile);
void		take_x_y_z(t_fdf *head, char *argv);

void		set_default(t_fdf *head);
void		you_are_the_best(t_fdf *head);
void		add_zoom(t_list *param, t_fdf *data);
void		add_shift(t_list *param, t_fdf *data);
int			find_max(int a, int b);
double		mod(double i);

void		malevich_mode(t_fdf *head);
void		bresenham(t_fdf *data, double x_next, double y_next);
void		draw(t_fdf *data);
void		print_key(int key);
void		print_key_bonus(int key);
void		move_picture(int key, t_fdf *data);
void		change_angle(int key, t_fdf *data);
void		reset(t_fdf *data);
void		rotate_image(t_fdf *data);
void		change_z(int key, t_fdf *data);
int			deal_key(int key, t_fdf *data);
int			mouse_key(int key, int x, int y, t_fdf *data);

#endif
