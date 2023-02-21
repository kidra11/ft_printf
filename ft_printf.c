/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsion <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 20:18:55 by nsion             #+#    #+#             */
/*   Updated: 2023/02/21 15:58:01 by nsion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libftprintf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
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

static	int	find(char s, va_list trois, int num)
{
	if (s == 'c')
	{
		ft_putchar(va_arg(trois, int));
		num++;
	}
	if (s == 's')
		num += ft_putstr(va_arg(trois, char *));
	return (num);
}

int	ft_printf(const char *s, ...)
{
	int	i;
	int	num;
	va_list	trois;

	va_start(trois, s);
	i = 0;
	num = 0;
	while (s[i])
	{
		if (s[i] == '%')
			num = find(s[++i], trois, num);
		else
			ft_putchar(s[i]);
		i++;
		num++;
	}
	printf("%d\n", num);
	va_end(trois);
	return (num);
}

int	main(void)
{
	ft_printf("hello%s\n", "ow");
	return (0);
}
