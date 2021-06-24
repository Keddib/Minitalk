/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keddib <keddib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 19:48:12 by keddib            #+#    #+#             */
/*   Updated: 2021/06/24 15:29:43 by keddib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	*char_to_bin(char c)
{
	int	i;
	int	j;
	int	*num;

	i = 7;
	j = 0;
	num = malloc(sizeof(int) * 7);
	if (num == NULL)
		return (NULL);
	while (i >= 0)
	{
		num[j] = c & (1 << i);
		--i;
		j++;
	}
	return (num);
}

int	check_errors(int argc, char **argv)
{
	int	pid;
	int	er;

	er = 0;
	if (argc != 3 || !argv[2][0])
		ft_exit(1);
	else if (!ft_isdigit(argv[1]))
		ft_exit(2);
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		ft_exit(2);
	return (pid);
}

void	send_char(int pid, int *num)
{
	int	i;
	int	ret;

	i = 7;
	while (i >= 0)
	{
		if (num[i] == 0)
			ret = kill(pid, SIGUSR1);
		else
			ret = kill(pid, SIGUSR2);
		if (ret == -1)
			ft_exit(2);
		usleep(150);
		i--;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;
	int	*num;

	pid = check_errors(argc, argv);
	i = 0;
	while (argv[2][i])
	{
		num = char_to_bin(argv[2][i]);
		send_char(pid, num);
		free(num);
		i++;
	}
	return (0);
}
