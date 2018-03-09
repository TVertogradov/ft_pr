/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvertohr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 16:16:28 by tvertohr          #+#    #+#             */
/*   Updated: 2018/03/09 16:16:29 by tvertohr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define CHECKE(a, b) ((a == '#' && (b == 'X' || b == 'x')) || b == 'p')

static void	ft_linepr_pr_add(char *linepr)
{
	char	*big;
	char	*small;

	big = "0X";
	small = "0x";
	if (*(linepr + 4) == 88)
		ft_putstr(big);
	else
		ft_putstr(small);
}

static void	ft_linepr_pr_add1(int *lenth)
{
	int		i;

	ft_putchar(48);
	if (*(lenth + 1) > 0)
		i = 1;
	else
		i = 0;
	*(lenth + 1) = *(lenth + 1) - i;
}

void		ft_linepr_pr(char *linepr, int *lenth, int m, LLI digit)
{
	int		res;

	res = *lenth - m;
	if ((*(linepr + 1) == 48 && *(lenth + 1) > 1) || (!*(linepr + 1)))
		ft_putnchar(32, res);
	if (*(linepr + 4) != 37 && *(linepr + 2))
		ft_putchar(*(linepr + 2));
	if (CHECKE(*linepr, *(linepr + 4)))
		ft_linepr_pr_add(linepr);
	if ((*(linepr + 4) == 111 || *(linepr + 4) == 79) && *linepr == 35)
		ft_linepr_pr_add1(lenth);
	if (*(lenth + 1) >= 1)
		ft_putnchar(48, *(lenth + 1) - nblen(digit, *(lenth + 2)));
	if (*(lenth + 1) < 0 && *(linepr + 1) == 48)
		ft_putnchar(48, res);
}

void		ft_base_pr(int bs, LLI digit, char *linepr)
{
	char	*lli;
	char	*end;
	char	*s;

	lli = "-9223372036854775808";
	s = "dDi";
	if (bs == 1)
		bs = -16;
	if (ft_strindexof(s, linepr[4]) != -1)
		end = (digit == MRES) ? ft_strdup(lli) : ft_itoa_base(digit, bs);
	else
		end = ft_uitoa_base((unsigned long long int)digit, bs);
	ft_putlenstr(end, ft_strlen(end));
	ft_memdel((void *)&end);
}
