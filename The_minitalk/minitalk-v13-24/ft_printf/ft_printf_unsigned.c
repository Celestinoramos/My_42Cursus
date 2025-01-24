/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramos-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 11:11:52 by cramos-c          #+#    #+#             */
/*   Updated: 2024/08/02 06:19:52 by cramos-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_unsigend(unsigned int number)
{
	int	count;

	count = 0;
	if (number < 10)
		count += ft_printf_character(number + '0');
	else
	{
		count += ft_printf_number(number / 10);
		count += ft_printf_number(number % 10);
	}
	return (count);
}
