/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 22:20:33 by tde-souz          #+#    #+#             */
/*   Updated: 2023/01/27 00:56:41 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_merge(char **array, char c)
{
	size_t	len;
	size_t	i;
	char	*ret;

	len = 0;
	i = 0;
	if (!array || !*array)
		return (NULL);
	while (*(array + i))
		len += ft_strlen(*(array + i++));
	ret = (char *)malloc(sizeof(len + i));
	if (!ret)
		return (NULL);
	while (*array)
	{
		while (**array)
			*ret++ = *(*array)++;
		if (*(array++ + 1))
			*ret++ = c;
	}
	*ret = 0;
	return (ret - (len + i - 1));
}

int main(int argc, char *argv[])
{
	char *out;
	int		i;

	i = 0;
	(void)argc;
	out = ft_merge(argv, ' ');
	ft_printf(">> %s\n", out);
	while (*(argv + i))
		ft_printf("%s\n", *(argv + i++));
	free(out);
	return (0);
}
