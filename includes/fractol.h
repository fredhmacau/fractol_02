/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmacau <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 14:07:48 by fmacau            #+#    #+#             */
/*   Updated: 2024/10/20 15:41:45 by fmacau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "./keys.h"
# include <math.h>
# include <stdbool.h>
# define WIDTH 800
# define HEIGHT 800

typedef struct s_fractol
{
	void	*mlx_init;
	void	*mlx_win;
	void	*mlx_img;
	char	*img_addr;
	char	*set;
	int	bpp;
	int	size_line;
	int	endian;
	double	zoom;
	double	move_x;
	double	move_y;
	double	c_re;
	double	c_im;
}	t_fractol;

void	ft_print_help(void);
double  ft_strod(char *str);
int		ft_skep_blank_and_sign(char *str, int *sign);
int		ft_isblank(int c);
void    ft_julia_check_args(char **av);
void    ft_julia_set(char **av);
#endif
