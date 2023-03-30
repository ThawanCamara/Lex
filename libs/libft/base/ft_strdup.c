/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 11:02:32 by tde-souz          #+#    #+#             */
/*   Updated: 2022/09/19 14:49:27 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*ret;

	if (s1 == NULL)
		return (0);
	len = ft_strlen(s1) + 1;
	ret = (char *)malloc(len * sizeof(char));
	if (ret == 0)
		return (0);
	ft_strlcpy(ret, s1, len);
	return (ret);
}
