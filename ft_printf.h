/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsion <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 18:06:27 by nsion             #+#    #+#             */
/*   Updated: 2023/02/25 18:38:23 by nsion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>

int		ft_printf(const char *s, ...);

int		ft_len(char *s);

int		ft_putchar(char c);

int		ft_putstr(char *s);

int		for_p(unsigned long long int *n, char *base, int num);

int		ft_putnbr_base(int n, char *base, int num);

int		ft_unput(unsigned int n, char *base, int num);

int		find(char s, va_list trois, int num);

#endif
