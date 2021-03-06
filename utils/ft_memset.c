/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keddib <keddib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 15:18:18 by keddib            #+#    #+#             */
/*   Updated: 2021/06/24 15:23:35 by keddib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*s;

	s = (char *)b;
	i = 0;
	while (len > i)
	{
		s[i] = c;
		i++;
	}
	return (b);
}
