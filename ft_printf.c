/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsion <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 20:18:55 by nsion             #+#    #+#             */
/*   Updated: 2023/02/23 15:26:33 by nsion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libftprintf.h"

int	ft_len(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

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

void	ft_putnbr_base(int n, char *base, int *num)
{
	int	xbase;

	xbase = ft_len(base);
	if (n < 0)
	{
		ft_putchar('-');
		n = n * -1;
		num++;
	}
	if (n >= xbase)
	{
		ft_putnbr_base((n / xbase), base, num);
	}
	ft_putchar(base[n % xbase]);
	num++;
}

int	find(char s, va_list trois, int num)
{
	if (s == 'c')
	{
		ft_putchar(va_arg(trois, int));
		num++;
	}
	if (s == 's')
		num += ft_putstr(va_arg(trois, char *));
	if (s == 'p')
		ft_putnbr_base(va_arg(trois, int), "0123456789abcdef", &num);
	if (s == 'd')
		ft_putnbr_base(va_arg(trois, int), "0123456789", &num);
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
			num += find(s[++i], trois, num);
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
	ft_printf("hello%p\n", -645178);
	return (0);
}

