/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:39:33 by nsiefert          #+#    #+#             */
/*   Updated: 2023/12/19 20:39:14 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static size_t	ft_strnlen(char *dest, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (dest[i] == '\0')
			break ;
		i++;
	}
	return (i);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	destlen;

	i = 0;
	j = 0;
	destlen = ft_strnlen(dest, size);
	while (i < size && dest[i])
		i++;
	if (i == size)
		return (i + ft_strlen(src));
	while (src[j])
	{
		if (j < size - destlen - 1)
		{
			dest[i] = src[j];
			i++;
		}
		j++;
	}
	dest[i] = '\0';
	return (destlen + j);
}
