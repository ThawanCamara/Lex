/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 07:10:53 by tde-souz          #+#    #+#             */
/*   Updated: 2022/10/19 16:19:12 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*c1;
	unsigned char	*c2;

	if (n == 0)
		return (0);
	c1 = (unsigned char *) s1;
	c2 = (unsigned char *) s2;
	while (--n)
	{
		if (*c1 == *c2)
		{
			c1++;
			c2++;
		}
		else
			break ;
	}
	return (*c1 - *c2);
}
