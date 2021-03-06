/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keddib <keddib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 17:18:01 by keddib            #+#    #+#             */
/*   Updated: 2021/06/24 15:23:35 by keddib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <sys/types.h>
# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include <stdlib.h>

/**
 * The type sig_atomic_t is used in C99 to guarantee
 * that a variable can be accessed/modified in an atomic way
 * in the case an interruption (reception of a signal for example) happens.
 */

volatile sig_atomic_t	g_num[10];

void	ft_exit(int x);
int		ft_isdigit(char *s);
void	ft_putnbr(int n);
void	ft_putchar(char c);
int		ft_atoi(const char *s);

#endif
