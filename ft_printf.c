/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsion <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 20:18:55 by nsion             #+#    #+#             */
/*   Updated: 2023/02/23 19:45:48 by nsion            ###   ########.fr       */
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

int	ft_putnbr_base(int n, char *base, int num)
{
	int	xbase;
	int	n_final[16];
	int	i;

	xbase = ft_len(base);
	i = 0;
	if (n < 0)
	{
		num += ft_putchar('-');
		n = n * -1;
	}
	while (n)
	{
		n_final[i] = n % xbase;
		n = n / xbase;
		i++;
	}
	while (--i >= 0)
		num += ft_putchar(base[n_final[i]]);
	return (num);
}

int	find(char s, va_list trois, int num)
{
	if (s == 'c')
		num += ft_putchar(va_arg(trois, int));
	if (s == 's')
		num += ft_putstr(va_arg(trois, char *));
	if (s == 'p')
		num += ft_putnbr_base(va_arg(trois, int), "0123456789abcdef", num);
	if (s == 'd')
		num += ft_putnbr_base(va_arg(trois, int), "0123456789", num);
	if (s == 'i')
		num += ft_putnbr_base(va_arg(trois, int), "0123456789", num);
	if (s == 'u')
		
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
			num += ft_putchar(s[i]);
		i++;
	}
	printf("%d\n", num);
	va_end(trois);
	return (num);
}

int	main(void)
{
	ft_printf("%ihello\n", -645178);
	printf ("%d\n", printf("%ihello\n", -645178));
	return (0);
}

