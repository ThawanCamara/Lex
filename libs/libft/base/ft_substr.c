/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 11:13:10 by tde-souz          #+#    #+#             */
/*   Updated: 2022/06/02 20:25:27 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i_len;
	size_t	o_len;

	i_len = ft_strlen(s);
	if (start > i_len)
		start = i_len;
	while (start--)
		s++;
	o_len = ft_strlen(s);
	if (len > o_len)
		len = o_len;
	ret = (char *)malloc((len + 1) * sizeof(char));
	if (ret == 0)
		return (0);
	ft_strlcpy(ret, s, len + 1);
	return (ret);
}
