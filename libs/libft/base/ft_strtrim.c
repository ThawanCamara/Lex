/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 12:44:11 by tde-souz          #+#    #+#             */
/*   Updated: 2022/06/02 20:25:25 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	is_trimmable(char const c, char const *set)
{
	while (*set)
	{
		if (c == *set || c == 0)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	start = 0;
	end = ft_strlen(s1);
	while (is_trimmable(*(s1 + start), set))
		start++;
	while (is_trimmable(*(s1 + end), set))
		end--;
	return (ft_substr(s1, start, end - start + 1));
}
