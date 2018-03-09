/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvertohr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 12:11:48 by tvertohr          #+#    #+#             */
/*   Updated: 2018/03/07 12:11:50 by tvertohr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_finish_fl(char **format, char *linepr, int *lenth)
{
	ft_get_presis(format, lenth);
	ft_lenth(format, linepr);
	ft_err_dupl(format, linepr, lenth);
	*(linepr + 4) = **format;
	ft_text_err(linepr);
}

void		ft_tag_get(char **format, char *linepr, int *lenth)
{
	int		i;

	++(*format);
	ft_flags(format, linepr);
	i = ft_isdigit(**format);
	if (i)
	{
		*lenth = ft_atoi(*format);
		*format = *format + nblen(*lenth, 10);
	}
	ft_finish_fl(format, linepr, lenth);
}

void		ft_get_presis(char **format, int *lenth)
{
	int		dot;
	int		res;
	int		i;

	dot = 46;
	i = -1;
	if (**format == dot)
	{
		while (**format == dot)
			++(*format);
		res = ft_isdigit(*(*(format)));
		if (res)
		{
			*(lenth + 1) = ft_atoi(*(format));
			*format = *format + nblen(*(lenth + 1), 10);
		}
	}
	else
		*(lenth + 1) = i;
}

static void	ft_perameters_put_set(t_ftprintf *line)
{
	line->str = 0;
	line->symbol = 0;
	line->stroka = 0;
	line->dlina = 0;
}

void		ft_perameters_put(int *lenth, char *linepr, t_ftprintf *line)
{
	int		tmp;
	int		zero;

	zero = 0;
	tmp = zero;
	while (tmp < 5)
	{
		if (tmp < 3)
			*(lenth + tmp) = zero;
		*(linepr + tmp++) = zero;
	}
	ft_perameters_put_set(line);
}
