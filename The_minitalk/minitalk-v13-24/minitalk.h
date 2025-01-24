/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcatar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 17:37:24 by jalcatar          #+#    #+#             */
/*   Updated: 2024/07/21 17:37:28 by jalcatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <unistd.h>
# include <signal.h>

int		ft_atoi(const char *str);
void	character_handler(int signal, siginfo_t *info, void *contexto);
int		ft_printf(const char *format, ...);

#endif
