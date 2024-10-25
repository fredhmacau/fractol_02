/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmacau <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 14:07:48 by fmacau            #+#    #+#             */
/*   Updated: 2024/10/25 20:41:02 by fmacau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "./keys.h"
# include "./img.h"
# include "./colors.h"
# include <math.h>
# include <stdbool.h>
# define WIDTH 800
# define HEIGHT 800

typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;

typedef struct s_fractal
{
	void	*mlx_connection;
	void	*mlx_window;
	char	*title;
	t_img	img;
	double	escape_value;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
	int		max_iteration;

}	t_fractal;

t_complex	ft_sum_complex(t_complex z1, t_complex z2);
t_complex	ft_square_complex(t_complex z);
double		ft_scale(double num, double new_min,
				double new_max, double old_max);
double		ft_strod(int i, double n, double t, char *str);
void		ft_render(t_fractal *fractol);
void		ft_check_params(char *av);
void		ft_fractol_init(t_fractal *fractol);
void		ft_print_help(void);
int			key_handler(int keycode, t_fractal *fractol);
int			close_handler(t_fractal *fractol);
int			mouse_handler(int button, int x, int y, t_fractal *fractol);
#endif
