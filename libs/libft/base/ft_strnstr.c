/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 07:40:57 by tde-souz          #+#    #+#             */
/*   Updated: 2022/06/02 20:25:14 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char	*t_haystack;
	const char	*t_needle;
	size_t		t_len;

	if (*needle == 0)
		return ((char *) haystack);
	if (len == 0)
		return (0);
	while (*haystack && len)
	{
		t_haystack = haystack;
		t_needle = needle;
		t_len = len;
		while (*t_needle && *t_haystack && *t_needle++ == *t_haystack++
			&& t_len--)
		{
			if (*t_needle == 0)
				return ((char *) haystack);
		}
		haystack++;
		len--;
	}
	return (0);
}
