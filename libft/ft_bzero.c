/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 11:55:14 by irodrigo          #+#    #+#             */
/*   Updated: 2021/03/23 14:47:37 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*aux;
	size_t	pos;

	aux = s;
	pos = 0;
	if (n != 0)
	{
		while (pos < n)
		{
			aux[pos] = '\0';
			pos++;
		}
	}
}
