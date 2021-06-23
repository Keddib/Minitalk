/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keddib <keddib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 17:18:01 by keddib            #+#    #+#             */
/*   Updated: 2021/06/23 17:51:33 by keddib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINITALK_H
# define MINITALK_H

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>


void	ft_exit(int x);
int		ft_isdigit(char *s);
void	ft_putnbr(int n);
void	ft_putchar(char c);
int		ft_atoi(const char *s);

#endif
