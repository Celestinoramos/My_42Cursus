/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkspecifier.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramos-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 11:08:34 by cramos-c          #+#    #+#             */
/*   Updated: 2024/08/02 06:15:32 by cramos-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_checkspecifier(char character)
{
	char	*specifier;
	int		i;

	i = 0;
	specifier = "cspdiuxX%";
	while (*(specifier + i))
	{
		if (character == *(specifier + i))
			return (*(specifier + i));
		i++;
	}
	return (0);
}
