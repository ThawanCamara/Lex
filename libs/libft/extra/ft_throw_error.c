/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_throw_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 02:34:42 by tde-souz          #+#    #+#             */
/*   Updated: 2022/10/12 02:14:26 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	throw_error(char *msg, int error_code)
{
	ft_putendl_fd(">>> \e[38;5;9mError\e[0m <<<", 2);
	ft_putstr_fd("Exit with error code: ", 2);
	ft_putnbr_fd(error_code, 2);
	ft_putstr_fd("\n", 2);
	ft_putendl_fd(msg, 2);
	exit(error_code);
}
