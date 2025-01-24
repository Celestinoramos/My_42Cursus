/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramos-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 11:09:34 by cramos-c          #+#    #+#             */
/*   Updated: 2024/06/12 10:13:06 by cramos-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_pointer(unsigned long number)
{
	int	count;

	count = 0;
	if (!number)
	{
		write (1, "(nil)", 5);
		return (5);
	}
	count += ft_printf_string("0x");
	count += ft_printf_hexadecimal(number, 'x');
	return (count);
}
