/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keddib <keddib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 17:16:35 by keddib            #+#    #+#             */
/*   Updated: 2021/06/23 18:35:53 by keddib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"

int	g_num[9];

char	bin_to_char(int *num)
{
	int		i;
	char	c;

	c = 0;
	i = 0;
	while (i < 8)
	{
		if (num[i] == 1)
			c += (1 << i);
		i++;
	}
	return (c);
}

void	siguser1(int sig)
{
	sig = 0;
	g_num[g_num[8]] = 0;
	g_num[8]++;
}

void	siguser2(int sig)
{
	sig = 0;
	g_num[g_num[8]] = 1;
	g_num[8]++;
}

int	main(int argc, char **argv)
{
	int		pid;
	char	c;

	if (argc != 1)
		ft_exit(1);
	argv[0] = NULL;
	g_num[8] = 0;
	pid = getpid();
	ft_putnbr(pid);
	ft_putchar('\n');
	while (1)
	{
		signal(SIGUSR1, siguser1);
		signal(SIGUSR2, siguser2);
		if (g_num[8] > 7)
		{
			c = bin_to_char(g_num);
			if (!c)
				ft_putchar('\n');
			else
				ft_putchar(c);
			g_num[8] = 0;
		}
	}
	return (0);
}
