/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsion <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 20:18:55 by nsion             #+#    #+#             */
/*   Updated: 2023/02/21 16:21:14 by nsion            ###   ########.fr       */
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

int	ft_putnbr(int n)
{
	int	num;

	num = 0;
	if (n == -2147483648)
	{
		num = ft_putstr("-2147483648\0");
		return (num);
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
		num++;
	}
	if (n >= 0 && n <= 9)
	{
		ft_putchar(n + '0');
		num++;
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	return (num);
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
//	if (s == 'p')
	if (s == 'd')
		num += ft_putnbr(va_arg(trois, int));
	printf("\n%d\n", num);
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
	va_end(trois);
	return (num);
}

int	main(void)
{
	ft_printf("hello%d\n", 678);
	return (0);
}
