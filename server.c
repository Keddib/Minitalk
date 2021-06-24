/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keddib <keddib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 17:16:35 by keddib            #+#    #+#             */
/*   Updated: 2021/06/24 15:23:35 by keddib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <string.h>

char	bin_to_char(volatile sig_atomic_t *num)
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

void	check_pid(pid_t pid)
{
	if (g_num[9])
	{
		if (g_num[9] != pid)
		{
			g_num[8] = 0;
			g_num[9] = pid;
		}
		return ;
	}
	g_num[9] = pid;
}

void	siguser(int sig, siginfo_t *si, void *data)
{
	(void)data;
	check_pid(si->si_pid);
	if (sig == SIGUSR1)
	{
		g_num[g_num[8]] = 0;
		g_num[8]++;
	}
	else if (sig == SIGUSR2)
	{
		g_num[g_num[8]] = 1;
		g_num[8]++;
	}
}

void	assing_ver(char **argv, struct sigaction *sa)
{
	ft_putchar('\n');
	argv[0] = NULL;
	g_num[8] = 0;
	g_num[9] = 0;
	memset(sa, 0, sizeof(*sa));
	sa->sa_flags = SA_SIGINFO;
	sa->sa_sigaction = siguser;
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	if (argc != 1)
		ft_exit(1);
	ft_putnbr(getpid());
	assing_ver(argv, &sa);
	while (1)
	{
		sigaction(SIGUSR1, &sa, 0);
		sigaction(SIGUSR2, &sa, 0);
		if (g_num[8] > 7)
		{
			ft_putchar(bin_to_char(g_num));
			g_num[8] = 0;
		}
		pause();
	}
	return (0);
}
