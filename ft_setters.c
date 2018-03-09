/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvertohr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 18:48:26 by tvertohr          #+#    #+#             */
/*   Updated: 2018/03/07 18:48:28 by tvertohr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define CHECKER(a) (a == 88 || a == 112 || a == 120)

static void	ft_underf_s_add(char **format, char *linepr, int *lenth, int size)
{
	int		i;
	int		k;

	i = *lenth - size;
	k = *lenth - 1;
	if (*(linepr + 4) != '\0')
	{
		ft_putchar(*(linepr + 4));
		(*format)++;
		++*(lenth + 3);
	}
	if (*(lenth + 1) < *lenth && *(linepr + 1) == 45)
	{
		if (size > 0)
			ft_putnchar(32, i);
		else
			ft_putnchar(32, k);
	}
}

static int	ft_underf_s_add1(int size)
{
	if (size < 0)
		return (1);
	else
		return (size);
}

static int	ft_underf_s_add2(int size)
{
	if (size == -7)
		return (-1);
	else
		return (size);
}

void		ft_underf_s(char **format, char *linepr, int *lenth, int size)
{
	int		i;
	int		sum;

	sum = *(lenth + 3) + *lenth;
	if ((*(linepr + 4) == 99 || *(linepr + 4) == 115) && !*(lenth + 1))
		*(lenth + 1) = -1;
	i = *lenth - ft_underf_s_add1(size);
	if (*(linepr + 1) == 48)
		ft_putnchar(48, i);
	else if (((!*(linepr + 2)) || *(linepr + 2) == 32) && !*(linepr + 1))
		ft_putnchar(32, i);
	if (*lenth != 0 && size < 0)
		*(lenth + 3) = sum + ft_underf_s_add2(size);
	if (size == -7)
		ft_underf_s_add(format, linepr, lenth, size);
}

void		ft_make_set(char *linepr, int *lenth)
{
	int		i;

	i = -1;
	if (*(linepr + 4) == 111 || *(linepr + 4) == 79)
		*(lenth + 2) = 8;
	else if (CHECKER(*(linepr + 4)))
		*(lenth + 2) = 16;
	else
		*(lenth + 2) = 10;
	if (*(linepr + 4) == 37)
		*(lenth + 1) = i;
}
