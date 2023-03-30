/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 07:27:36 by tde-souz          #+#    #+#             */
/*   Updated: 2022/06/02 20:24:40 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			count++;
		s++;
	}
	return (count);
}

static char	*get_next_word(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (*(s + len) && *(s + len) != c)
		len++;
	return (ft_substr(s, 0, len));
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	size_t	i;

	i = 0;
	ret = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (ret == 0)
		return (0);
	while (*s)
	{
		if (*s != c)
		{
			*(ret + i) = get_next_word(s, c);
			s += ft_strlen(*(ret + i++));
		}
		if (*s)
			s++;
	}
	*(ret + i) = 0;
	return (ret);
}
