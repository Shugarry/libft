/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frey-gal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 18:13:37 by frey-gal          #+#    #+#             */
/*   Updated: 2024/10/16 16:55:02 by frey-gal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!*s)
		return ;
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
}
