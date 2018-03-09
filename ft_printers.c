/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvertohr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 12:11:18 by tvertohr          #+#    #+#             */
/*   Updated: 2018/03/09 12:11:19 by tvertohr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_string_pr_add(t_ftprintf line, int size)
{
	int		i;

	i = -1;
	if (!size)
		ft_putlenstr(NULL, i);
	else
		ft_putlenstr(line.str, size);
}

static int	ft_string_pr_add1(int *lenth, int size)
{
	if (size > *lenth)
		return (size);
	else
		return (*lenth);
}

void		ft_string_pr(char *linepr, int *lenth, t_ftprintf line)
{
	int		size;

	size = ft_strlenthmax(line, linepr, lenth);
	if (*(linepr + 4) == 115 && *(lenth + 1) && !*(linepr + 3) &&
		line.str == NULL)
		size = 6;
	ft_underf_s(NULL, linepr, lenth, size);
	if (*(linepr + 4) == 115 && !*(linepr + 3))
		ft_string_pr_add(line, size);
	else if ((*(linepr + 3) == 108 && *(linepr + 4) == 115) ||
		*(linepr + 4) == 83)
	{
		if (size < 0 ? size = 6 : 0)
			ft_putlenstr("(null)", 6);
		else
			ft_putwstr(line.stroka, size);
	}
	else if (*(linepr + 4) == 99 && !*(linepr + 3))
		ft_putchar(line.symbol);
	else
		ft_putwchar(line.dlina);
	*(lenth + 3) = *(lenth + 3) + ft_string_pr_add1(lenth, size);
	if (*(linepr + 1) == 45)
		ft_putnchar(32, *lenth - size);
}

static void	ft_number_pr_add(char *linepr, int *lenth, LLI digit, int m)
{
	int		i;
	int		one;

	one = 1;
	i = *lenth - m;
	if (*(linepr + 4) == 37)
		ft_putchar(37);
	if (*(linepr + 4) == 88 && *(lenth + 2) == 16)
		*(lenth + 2) = one;
	if (*(linepr + 4) != 37 && (digit || *(lenth + 1)))
		ft_base_pr(*(lenth + 2), digit, linepr);
	if (*lenth > *(lenth + 1) && *(linepr + 1) == 45)
		ft_putnchar(32, i);
}

void		ft_number_pr(char *linepr, int *lenth, LLI digit)
{
	int		m;

	if (!digit && *(linepr + 4) != 79 && *(linepr + 4) != 111)
		*linepr = 0;
	if (*linepr == 35 && !digit && *(lenth + 1) < 0 && *(linepr + 4) == 111)
		*(lenth + 1) = 0;
	m = ft_numlenthmax(digit, linepr, lenth);
	*(lenth + 3) = MAX(m, MAX(*lenth, *(lenth + 1))) + *(lenth + 3);
	ft_linepr_pr(linepr, lenth, m, digit);
	ft_number_pr_add(linepr, lenth, digit, m);
}
