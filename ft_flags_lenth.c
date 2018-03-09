/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_lenth.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvertohr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 14:58:19 by tvertohr          #+#    #+#             */
/*   Updated: 2018/03/07 14:58:20 by tvertohr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_flags_add(char **format, char *linepr)
{
	int		sharp;
	int		zero;
	int		space;
	int		minus;
	int		plus;

	space = 32;
	minus = 45;
	sharp = 35;
	zero = 48;
	plus = 43;
	if (**format == sharp && !*linepr)
		*linepr = sharp;
	if (**format == minus)
		*(linepr + 1) = **format;
	if (**format == zero && *(linepr + 1) != minus)
		*(linepr + 1) = **format;
	if (**format == plus)
		*(linepr + 2) = **format;
	if (**format == space && !*(linepr + 2))
		*(linepr + 2) = **format;
}

void		ft_flags(char **format, char *linepr)
{
	char	*s;
	int		i;

	s = "#+- 0";
	i = -1;
	while (ft_strindexof(s, **format) > i && **format)
	{
		ft_flags_add(format, linepr);
		(*format)++;
	}
}

static void	ft_lenth_add(char **format, char *linepr)
{
	int		h;
	int		l;
	int		bl;

	h = 104;
	l = 108;
	bl = 76;
	if (*(*format + 1) == h || **format == *(*format + 1))
	{
		if (**format == l || **format == h)
			*(linepr + 3) = -32 + **format;
		else
			*(linepr + 3) = bl;
		(*format)++;
	}
	else
		*(linepr + 3) = **format;
}

void		ft_lenth(char **format, char *linepr)
{
	char	*s;
	int		i;

	s = "hjzl";
	i = -1;
	while (ft_strindexof(s, **format) > i && **format)
	{
		ft_lenth_add(format, linepr);
		(*format)++;
	}
}
