/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramos-c <cramos-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 09:22:27 by cramos-c          #+#    #+#             */
/*   Updated: 2024/10/28 17:40:14 by cramos-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	type_cmp(char *av, char *str, char c, char n)
{
	int	i;

	i = 0;
	while (av[i])
	{
		av[i] = ft_tolower(av[i]);
		i++;
	}
	if (!ft_strncmp(av, str, ft_strlen(str) + 1))
		return (1);
	else if (av[1] == '\0' && (av[0] == c || av[0] == n))
		return (1);
	return (0);
}

static void	get_set(t_fractol *f, char **av)
{
	if (type_cmp(av[1], "mandelbrot", 'm', '1'))
		f->set = MANDELBROT;
	else if (type_cmp(av[1], "julia", 'j', '2'))
		f->set = JULIA;
	else
		help_msg(f);
}

static void	get_julia_starting_values(t_fractol *f, int ac, char **av)
{
	if (f->set == JULIA)
	{
		if (ac < 4)
		{
			help_msg(f);
			return ;
		}
		if (!ft_strchr(av[2], '.') || !ft_strchr(av[3], '.'))
		{
			help_msg(f);
			return ;
		}
		f->kr = ft_atof(av[2]);
		f->ki = ft_atof(av[3]);
		if (f->kr > 2.0 || f->kr < -2.0 || f->ki >= 2.0 || f->ki <= -2.0)
		{
			help_msg(f);
			return ;
		}
	}
	else
	{
		f->kr = -0.766667;
		f->ki = -0.090000;
	}
}

static void	handle_args(t_fractol *f, int ac, char **av)
{
	get_set(f, av);
	if (f->set == JULIA && ac == 2)
	{
		help_msg(f);
		return ;
	}
	if (f->set != JULIA && ac > 3)
	{
		help_msg(f);
		return ;
	}
	else if (f->set == JULIA && ac > 5)
	{
		help_msg(f);
		return ;
	}
	get_julia_starting_values(f, ac, av);
	get_color(f, ac, av);
}

int	main(int ac, char **av)
{
	t_fractol	f;

	clean_init(&f);
	if (ac < 2)
		help_msg(&f);
	handle_args(&f, ac, av);
	init(&f);
	render(&f);
	mlx_hook(f.win, EVENT_CLOSE_BTN, 0, end_fractol, &f);
	mlx_key_hook(f.win, key_event, &f);
	mlx_mouse_hook(f.win, mouse_event, &f);
	mlx_loop(f.mlx);
}
