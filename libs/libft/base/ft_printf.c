/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 00:22:39 by tde-souz          #+#    #+#             */
/*   Updated: 2022/07/12 06:12:16 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	spec_handler(char c, va_list args)
{
	if (c == SPEC_CHAR)
		return (ft_putchar_n(va_arg(args, int), 1));
	if (c == SPEC_STR)
		return (ft_putstr_n(va_arg(args, const char *), 1));
	if (c == SPEC_PTR)
		return (ft_putptr_n(va_arg(args, void *), 1));
	if (c == SPEC_DEC || c == SPEC_INT)
		return (ft_putnbr_n(va_arg(args, int), 1));
	if (c == SPEC_UDEC)
		return (ft_putunbr_n(va_arg(args, unsigned int), 1));
	if (c == SPEC_HEXLOW)
		return (ft_puthexlow_n(va_arg(args, unsigned int), 1));
	if (c == SPEC_HEXUP)
		return (ft_puthexup_n(va_arg(args, unsigned int), 1));
	if (c == SPEC_PERCENT)
		return (ft_putchar_n('%', 1));
	return (0);
}

int	print_handler(const char *s, va_list args)
{
	int	print_count;
	int	check;	

	print_count = 0;
	while (*s)
	{
		check = 0;
		if (*s == '%' && *++s)
			check = spec_handler(*s, args);
		else
			check = ft_putchar_n(*s, 1);
		print_count += check;
		s++;
	}
	return (print_count);
}

int	ft_printf(const char *s, ...)
{
	int		print_count;
	va_list	args;

	va_start(args, s);
	print_count = print_handler(s, args);
	va_end(args);
	return (print_count);
}
