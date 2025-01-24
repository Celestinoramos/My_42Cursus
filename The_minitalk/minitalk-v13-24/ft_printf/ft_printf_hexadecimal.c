/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexadecimal.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramos-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 11:12:09 by cramos-c          #+#    #+#             */
/*   Updated: 2024/08/02 06:17:17 by cramos-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_hexadecimal(unsigned long number, char c)
{
	char	*basehex;
	int		count;

	count = 0;
	if (c == 'x')
		basehex = "0123456789abcdef";
	else
		basehex = "0123456789ABCDEF";
	if (number < 16)
		count += ft_printf_character(*(basehex + number));
	else
	{
		count += ft_printf_hexadecimal((number / 16), c);
		count += ft_printf_hexadecimal((number % 16), c);
	}
	return (count);
}
