/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsion <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 20:18:55 by nsion             #+#    #+#             */
/*   Updated: 2023/02/21 20:09:00 by nsion            ###   ########.fr       */
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

int	checkbase(int n)
{
	if (n < 2)
		return (2);
	else if (n >= 65 && n <= 70)
		return (16);
	else
		return (10);

}

int	ft_putnbr_base(int n, int num)
{
	int	base;

	base = checkbase(n);
	if (base == 2)
		base = 2;
	if (base == 10)
		base = 10;
	if (base == 16)
		base = 16;
	if (n < 0)
	{
		ft_putchar('-');
		n = n * -1;
		num++;
	}
	if (n >= base)
	{
		ft_putnbr_base((n / base), num);
	}
	ft_putchar((n % base) + '0');
	num++;
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
		num += ft_putnbr_base(va_arg(trois, int), num);
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
	ft_printf("hello%d\n", -645178);
	return (0);
}
