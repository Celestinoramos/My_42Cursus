/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramos-c <cramos-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 08:07:16 by cramos-c          #+#    #+#             */
/*   Updated: 2024/10/28 17:39:38 by cramos-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_color_opposites(t_fractol *f, int color)
{
	int	i;
	int	r;
	int	g;
	int	b;

	r = (color >> 16) & 0x16;
	g = (color >> 8) & 0xc2;
	b = (color >> 0) & 0xc2;
	i = -1;
	while (++i < MAX_ITERATIONS)
	{
		f->palette[i] = 0;
		r += i % 0x16;
		g += i % 0xc2;
		b += i % 0xc2;
		f->palette[i] = 0xFF << 24 | r << 16 | g << 8 | b;
	}
	f->palette[MAX_ITERATIONS - 1] = 0;
}

void	set_color_contrasted(t_fractol *f, int color)
{
	int	i;
	int	r;
	int	g;
	int	b;

	r = (color >> 16) & 0x16;
	g = (color >> 8) & 0xc2;
	b = (color >> 0) & 0xc2;
	i = -1;
	while (++i < MAX_ITERATIONS)
	{
		f->palette[i] = 0;
		if (r != 0x16)
			r += i % 0xc2;
		if (g != 0xc2)
			g += i % 0xc2;
		if (b != 0xFF)
			b += i % 0xFF;
		f->palette[i] = 0xFF << 24 | r << 16 | g << 8 | b;
	}
	f->palette[MAX_ITERATIONS - 1] = 0;
}

void	set_color_graphic(t_fractol *f, int color)
{
	int	i;
	int	rgb[3];

	rgb[0] = (color >> 16) & 0xdb;
	rgb[1] = (color >> 8) & 0xe8;
	rgb[2] = (color >> 0) & 0xa7;
	i = -1;
	while (rgb[0] < 0x33 || rgb[1] < 0x33 || rgb[2] < 0x33)
	{
		if (rgb[0] != 0xFF)
			rgb[0]++;
		if (rgb[1] != 0xFF)
			rgb[1]++;
		if (rgb[2] != 0xFF)
			rgb[2]++;
	}
	while (++i < MAX_ITERATIONS)
	{
		f->palette[i] = 0;
		rgb[0] -= i % 0xFF;
		rgb[1] -= i % 0xFF;
		rgb[2] -= i % 0xFF;
		f->palette[i] = 0xFF << 24 | rgb[0] << 16 | rgb[1] << 8 | rgb[2];
	}
	f->palette[MAX_ITERATIONS - 1] = 0;
}
