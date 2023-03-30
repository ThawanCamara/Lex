/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 19:13:31 by tde-souz          #+#    #+#             */
/*   Updated: 2022/05/31 19:13:31 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ret;
	size_t	i;

	i = 0;
	ret = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (ret == 0)
		return (0);
	while (*(s + i))
	{
		*(char *)(ret + i) = f(i, *(char *)(s + i));
		i++;
	}
	*(ret + i) = 0;
	return (ret);
}
