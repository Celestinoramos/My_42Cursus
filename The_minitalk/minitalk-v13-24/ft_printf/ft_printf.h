/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramos-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 11:09:04 by cramos-c          #+#    #+#             */
/*   Updated: 2024/08/02 06:16:43 by cramos-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *str, ...);
int		ft_printf_number(long number);
int		ft_printf_hexadecimal(unsigned long number, char c);
int		ft_printf_character(char c);
int		ft_printf_string(char *str);
int		ft_printf_unsigend(unsigned int number);
int		ft_printf_pointer(unsigned long number);
char	ft_checkspecifier(char character);

#endif
