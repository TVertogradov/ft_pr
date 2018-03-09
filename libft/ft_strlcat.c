/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvertohr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 12:52:34 by tvertohr          #+#    #+#             */
/*   Updated: 2017/11/09 14:37:20 by tvertohr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char	*c;
	char	*r;
	size_t	len;

	c = (char *)ft_memchr(dst, '\0', dstsize);
	if (c == NULL)
		return (dstsize + ft_strlen(src));
	r = (char *)src;
	len = (size_t)(c - dst) + ft_strlen(r);
	while ((size_t)(c - dst) < dstsize - 1 && *r != '\0')
		*c++ = *r++;
	*c = '\0';
	return (len);
}
