/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keddib <keddib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 19:48:12 by keddib            #+#    #+#             */
/*   Updated: 2021/06/22 20:51:43 by keddib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int *char_to_bin(char c)
{
	int i;
	int j;
	int *num;

	i = 7;
	j = 0;
	num = malloc(sizeof(int) * 7);
	if (num == NULL)
		return (NULL);
	while (i >= 0)
	{
		if (c & (1 << i))
			num[j] = 1;
		else
			num[j] = 0;
		--i;
		j++;
	}
	return (num);
}

int check_errors(int argc, char **argv)
{
	int	pid;
	int	er;

	if (argc != 3 || !argv[2][0])
	{
		printf("arguments error\n");
		exit(1);
	}
	pid = atoi(argv[1]);
	if (pid <= 0)
	{
		printf("invalid pid\n");
		exit(1);
	}
	return (pid);
}

void	send_char(int pid, int *num)
{
	int i;

	i = 7;
	while (i >= 0)
	{
		if (num[i] == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i--;
	}

}

int main(int argc, char **argv)
{
	int pid;
	int i;
	int *num;

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
