/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramos-c <cramos-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 14:00:07 by cramos-c          #+#    #+#             */
/*   Updated: 2024/10/28 17:39:48 by cramos-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	color_shift_special(t_fractol *f)
{
	int	alt_color;

	if (f->color == 0xf0d181)
		alt_color = 0xf0d181;
	else
		alt_color = f->color;
	if (f->color_pattern == 5)
		set_color_contrasted(f, alt_color);
	else if (f->color_pattern == 6)
		set_color_opposites(f, f->color);
	else if (f->color_pattern == 7)
		set_color_graphic(f, f->color);
	else if (f->color_pattern == 8)
		set_color_multiple(f, (int [8]){0xFF0000, 0xFF7F00, 0xFFFF00,
			0x00FF00, 0x0000FF, 0x4B0082, 0x9400D3, 0xFFFFFF}, 8);
}

static void	color_shift_striped(t_fractol *f)
{
	if (f->color_pattern == 2)
		set_color_zebra(f, f->color);
	else if (f->color_pattern == 3)
		set_color_triad(f, f->color);
	else if (f->color_pattern == 4)
		set_color_tetra(f, f->color);
	else
		color_shift_special(f);
}

void	color_shift(t_fractol *f)
{
	int	alt_color;

	f->color_pattern = (f->color_pattern + 1) % 9;
	reinit_img(f);
	if (f->color == 0x000000)
		alt_color = 0x333333;
	else
		alt_color = f->color;
	if (f->color_pattern == 0)
		set_color_mono(f, alt_color);
	else if (f->color_pattern == 1)
		set_color_multiple(f, (int [4]){0x000000, alt_color,
			get_percent_color(f->color, 50), 0xFFFFFF}, 4);
	else
		color_shift_striped(f);
}
