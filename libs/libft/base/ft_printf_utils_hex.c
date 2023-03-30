/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 00:29:28 by tde-souz          #+#    #+#             */
/*   Updated: 2022/07/12 06:13:13 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putptr_n(void *ptr, int fd)
{
	int				count;
	unsigned long	n;

	count = 0;
	n = (unsigned long) ptr;
	count += ft_putstr_n("0x", fd);
	count += ft_puthexlowlong_n(n, fd);
	return (count);
}

int	ft_puthexlowlong_n(unsigned long n, int fd)
{
	const char	*base = "0123456789abcdef";
	static int	count;

	count = 0;
	if (n >= 16)
		ft_puthexlowlong_n(n / 16, fd);
	count += ft_putchar_n(base[n % 16], fd);
	return (count);
}

int	ft_puthexlow_n(unsigned int n, int fd)
{
	const char	*base = "0123456789abcdef";
	static int	count;

	count = 0;
	if (n >= 16)
		ft_puthexlow_n(n / 16, fd);
	count += ft_putchar_n(base[n % 16], fd);
	return (count);
}

int	ft_puthexup_n(unsigned int n, int fd)
{
	const char	*base = "0123456789ABCDEF";
	static int	count;

	count = 0;
	if (n >= 16)
		ft_puthexup_n(n / 16, fd);
	count += ft_putchar_n(base[n % 16], fd);
	return (count);
}
