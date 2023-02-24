/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsion <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 20:18:55 by nsion             #+#    #+#             */
/*   Updated: 2023/02/24 17:22:34 by nsion            ###   ########.fr       */
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

int	ft_unput(unsigned int n, char *base, int num)
{
	int	xbase;
        int	n_final[16];
	int	i;

	xbase = ft_len(base);
	i = 0;
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

int	for_p(void *n, char *base, int num)
{
	unsigned long long int	ln;
	unsigned long long int	xbase;
	int	n_final[16];
	int	i;

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

int	find(char s, va_list trois, int num)
{
	if (s == 'c')
		num += ft_putchar(va_arg(trois, int));
	if (s == 's')
		num += ft_putstr(va_arg(trois, char *));
	if (s == 'p')
		num = for_p(va_arg(trois, void *), "0123456789abcdef", num);
	if (s == 'd')
		num = ft_putnbr_base(va_arg(trois, int), "0123456789", num);
	if (s == 'i')
		num = ft_putnbr_base(va_arg(trois, int), "0123456789", num);
	if (s == 'u')
		num = ft_unput(va_arg(trois, unsigned int), "0123456789", num);
	if (s == 'x')
		num = ft_unput(va_arg(trois, unsigned int), "0123456789abcdef", num);
	if (s == 'X')
		num = ft_unput(va_arg(trois, unsigned int), "0123456789ABCDEF", num);
	if (s == '%')
		num += ft_putchar('%');
	return (num);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		num;
	va_list		trois;

	va_start(trois, s);
	i = 0;
	num = 0;
	while (s[i])
	{
		if (s[i] == '%')
			num = find(s[++i], trois, num);
		else
			num += ft_putchar(s[i]);
		i++;
	}
	va_end(trois);
	return (num);
}

int	main(void)
{
	int	v = 0;

	
	printf("%d\n", ft_printf("%phello\n", &v));
	printf ("%d\n", printf("%phello\n", &v));
	return (0);
}
