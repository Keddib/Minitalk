/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keddib <keddib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 17:16:11 by keddib            #+#    #+#             */
/*   Updated: 2021/06/23 17:50:19 by keddib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"

void	ft_exit(int x)
{
	if (x == 1)
		write(1, "arguments error\n", 16);
	else if (x == 2)
		write(1, "invalid pid\n", 16);
	exit(1);
}

int	ft_isdigit(char *s)
{
	int	i;

	i = 0;
	if (s[i] == 45)
		i++;
	while (s[i])
	{
		if (s[i] > 47 && s[i] < 58)
			i++;
		else
			return (0);
	}
	return (1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	long nbr;

	nbr = n;
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr >= 0 && nbr <= 9)
		ft_putchar(nbr + '0');
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		ft_putchar(nbr % 10 + '0');
	}
}

int	ft_atoi(const char *str)
{
	int	i;
	int	p;
	int r;

	i = 0;
	p = 1;
	r = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			p = -1;
		i++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + str[i] - '0';
		i++;
	}
	return (r * p);
}
