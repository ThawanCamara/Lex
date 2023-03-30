/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 20:33:32 by tde-souz          #+#    #+#             */
/*   Updated: 2022/05/30 20:33:32 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size < dst_len)
		return (src_len + size);
	else
	{
		dst += dst_len;
		size -= dst_len;
		while (size > 1 && *src != 0)
		{
			*dst++ = *src++;
			size--;
		}
		*dst = 0;
	}
	return (src_len + dst_len);
}
