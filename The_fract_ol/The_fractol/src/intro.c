/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intro.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramos-c <cramos-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:20:50 by cramos-c          #+#    #+#             */
/*   Updated: 2024/10/28 17:40:23 by cramos-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#include "fractol.h"

void	print_fractal_options(void)
{
	ft_putendl_fd("\tIntrodução Errada:", 1);
	ft_putendl_fd("\t./fractol m ou ./fractol madelbrot\n", 1);
	ft_putendl_fd("\t./fractol j ou ./fractol julia <real> <imaginario>\n", 1);
	ft_putendl_fd("\tNúmeros no intervalo de: -2.0 e 2.0\n", 1);
	ft_putendl_fd("\tPossiveis combinações para formar o julia:\n", 1);
	ft_putendl_fd("\t./fractol J 0.285 0.01\n", 1);
	ft_putendl_fd("\tPodes alterar o padrão de cores:\n", 1);
	ft_putendl_fd("\t./fractol J 0.285 0.01 CC6600", 1);
}

void	help_msg(t_fractol *f)
{
	ft_putendl_fd("|             FRACT'OL              |", 1);
	print_fractal_options();
	clean_exit(EXIT_FAILURE, f);
}
