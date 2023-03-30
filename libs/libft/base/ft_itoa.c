/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 19:49:44 by tde-souz          #+#    #+#             */
/*   Updated: 2022/10/19 15:48:18 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Itoa's goal is to convert a given int into a string. It allocates memory
**	by using malloc which must be freed after use. In this implementation it
**	first finds the amount of dozens, then places the sign in the first byte 
**	if n is negative and the \0 at last allocated byte. Lastly it writes the
**	values to the string backwards.
*/
char	*ft_itoa(int n)
{
	long int	i;
	size_t		dozens;
	char		*ret;

	i = n;
	dozens = 0;
	while (++dozens && (i >= 10 || i <= -10))
		i /= 10;
	ret = (char *)malloc(((i < 0) + dozens + 1) * sizeof(char));
	if (ret == 0)
		return (0);
	i = n;
	ret[0] = '-' * (n < 0);
	if (n < 0)
		i = (long int)n * -1;
	ret[dozens + (n < 0)] = 0;
	while (dozens--)
	{
		ret[dozens + (n < 0)] = i % 10 + '0';
		i /= 10;
	}
	return (ret);
}
