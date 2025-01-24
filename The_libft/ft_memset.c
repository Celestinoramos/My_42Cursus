/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramos-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 15:59:58 by cramos-c          #+#    #+#             */
/*   Updated: 2024/05/18 16:00:05 by cramos-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *p, int valor, size_t tamanho)
{
	char	*conversor;

	conversor = (char *)p;
	while (tamanho > 0)
	{
		conversor[tamanho - 1] = valor;
		tamanho--;
	}
	return (p);
}
