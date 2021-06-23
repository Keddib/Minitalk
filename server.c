/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keddib <keddib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 17:16:35 by keddib            #+#    #+#             */
/*   Updated: 2021/06/23 18:14:32 by keddib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"

int yex;
int num[9];

char bin_to_char(int *num)
{
	int i;
	int bin[8] = {1, 2, 4, 8, 16, 32, 64, 128};
	char c = 0;
	i = 0;
	while (i < 8)
	{
		if (num[i] == 1)
			c += bin[i];
		i++;
	}
	return (c);
}

void siguser1()
{
	num[num[8]] = 0;
	num[8]++;
}

void siguser2()
{
	num[num[8]] = 1;
	num[8]++;
}

int	main(int argc, char **argv)
{
	int		pid;
	char	c;

	if (argc != 1)
		ft_exit(1);
	argv[0] = NULL;
	num[8] = 0;
	pid = getpid();
	ft_putnbr(pid);
	ft_putchar('\n');
	while (1)
	{
		signal(SIGUSR1, siguser1);
		signal(SIGUSR2, siguser2);
		if (num[8] > 7)
		{
			c = bin_to_char(num);
			if (!c)
				ft_putchar('\n');
			else
				ft_putchar(c);
			num[8] = 0;
		}
	}
	return 0;
}
