/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 20:16:16 by tde-souz          #+#    #+#             */
/*   Updated: 2022/05/30 20:16:16 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{	
	if (dest == 0 && src == 0)
		return (0);
	if (n > 0)
	{
		if (src > dest)
			ft_memcpy(dest, src, n);
		else
		{
			while (n)
			{
				*(char *)(dest + (n - 1)) = *(char *)(src + (n - 1));
				n--;
			}
		}
	}
	return (dest);
}
