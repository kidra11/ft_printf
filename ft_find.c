/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsion <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 17:29:11 by nsion             #+#    #+#             */
/*   Updated: 2023/02/24 17:53:26 by nsion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_len(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}

int	for_p(void *n, char *base, int num)
{
	unsigned long long int	ln;
	unsigned long long int	xbase;
	int						n_final[16];
	int						i;

	ln = (unsigned long long int)n;
	xbase = ft_len(base);
	i = 0;
	num += ft_putstr("0x");
	while (ln)
	{
		n_final[i] = ln % xbase;
		ln = ln / xbase;
		i++;
	}
	while (--i >= 0)
		num += ft_putchar(base[n_final[i]]);
	return (num);
}	
