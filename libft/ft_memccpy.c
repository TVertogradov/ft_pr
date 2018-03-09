/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvertohr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 15:29:28 by tvertohr          #+#    #+#             */
/*   Updated: 2017/10/31 16:21:16 by tvertohr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned int		i;
	unsigned char		*s1;
	const unsigned char	*s2;
	unsigned char		x;

	i = 0;
	s1 = (unsigned char *)dst;
	s2 = (const unsigned char *)src;
	x = (unsigned char)c;
	while (i < n)
	{
		if ((*s1++ = *s2++) == x)
			return (s1);
		i++;
	}
	return (NULL);
}
