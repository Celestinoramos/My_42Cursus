/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramos-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 11:08:50 by cramos-c          #+#    #+#             */
/*   Updated: 2024/06/12 10:12:20 by cramos-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_mainprintf(char specifier, va_list var)
{
	int	p;

	p = 0;
	if (specifier == '%')
		p = ft_printf_character('%');
	else if (specifier == 'c')
		p = ft_printf_character(va_arg(var, int));
	else if (specifier == 's')
		p = ft_printf_string(va_arg(var, char *));
	else if (specifier == 'i' || specifier == 'd')
		p = ft_printf_number(va_arg(var, int));
	else if (specifier == 'u')
		p = ft_printf_unsigend(va_arg(var, unsigned int));
	else if (specifier == 'x' || specifier == 'X')
		p = ft_printf_hexadecimal(va_arg(var, unsigned int), specifier);
	else if (specifier == 'p')
		p = ft_printf_pointer(va_arg(var, unsigned long));
	return (p);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	var;

	va_start(var, str);
	i = 0;
	count = 0;
	while (*(str + i))
	{
		if (*(str + i) == '%' && ft_checkspecifier(*(str + i + 1)))
			count += ft_mainprintf(*(str + i++ + 1), var);
		else if (*(str + i) == '%' && !ft_checkspecifier(*(str + i + 1)))
		{
			write (1, "Especifier ERROR!", 18);
			return (count);
		}
		else
		{
			write (1, (str + i), 1);
			count++;
		}
		i++;
	}
	va_end(var);
	return (count);
}
