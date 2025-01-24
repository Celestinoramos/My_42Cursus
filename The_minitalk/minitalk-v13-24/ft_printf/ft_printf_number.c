/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramos-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 11:09:18 by cramos-c          #+#    #+#             */
/*   Updated: 2024/08/02 06:18:32 by cramos-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_number(long number)
{
	int		count;

	count = 0;
	if (number < 0)
	{
		number *= -1;
		count += ft_printf_character('-');
	}
	if (number < 10)
		count += ft_printf_character(number + '0');
	else
	{
		count += ft_printf_number(number / 10);
		count += ft_printf_number(number % 10);
	}
	return (count);
}
