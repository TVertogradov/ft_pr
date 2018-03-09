/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maxgeters.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvertohr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 15:02:08 by tvertohr          #+#    #+#             */
/*   Updated: 2018/03/07 15:09:01 by tvertohr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_strlenthmax_add(int longest, int *lenth)
{
	if (longest > *(lenth + 1))
		return (*(lenth + 1));
	else
		return (longest);
}

int				ft_strlenthmax(t_ftprintf line, char *linepr, int *lenth)
{
	intmax_t	longest;

	longest = 0;
	if (*(linepr + 4) == 115 && !*(linepr + 3))
		longest = ft_strlen(line.str);
	else if (*(linepr + 4) == 83 || (*(linepr + 3) == 108 &&
		*(linepr + 4) == 115))
		longest = ft_wstrlen(line.stroka, *(lenth + 1));
	else if (*(linepr + 4) == 99 && !*(linepr + 3))
		longest = 1;
	else
	{
		if (L >= line.dlina)
			longest = 1;
		else if (LL >= line.dlina)
			longest = 2;
		else if (LLL >= line.dlina)
			longest = 3;
		else
			longest = 4;
	}
	if (*(lenth + 1) >= 0 && *(linepr + 4) != 99 && *(linepr + 4) != 67)
		return (ft_strlenthmax_add(longest, lenth));
	else
		return (longest);
}

static int		ft_numlenthmax_add1(LLI llinum)
{
	if (llinum < 0)
		return (1);
	else
		return (0);
}

static intmax_t	ft_numlenthmax_add2(int *lenth, intmax_t strdl)
{
	if (strdl > *(lenth + 1))
		return (strdl);
	else
		return (*(lenth + 1));
}

int				ft_numlenthmax(LLI llinum, char *linepr, int *lenth)
{
	intmax_t	longest;
	intmax_t	strdl;
	char		*s;

	strdl = ft_numlenthmax_add1(llinum);
	s = "dDi";
	ft_make_set(linepr, lenth);
	if (-1 < ft_strindexof(s, *(linepr + 4)))
		strdl = strdl + nblen(llinum, *(lenth + 2));
	else
		strdl = unblen((unsigned long long int)llinum, *(lenth + 2));
	longest = ft_numlenthmax_add2(lenth, strdl);
	if (!*lenth && longest == *(lenth + 1) && (*(linepr + 4) == 111 ||
		*(linepr + 4) == 79))
		longest = longest - 1;
	if ((*(linepr + 2) && *(linepr + 4) != 37) ||
		(*linepr == 35 && (*(linepr + 4) == 111 || *(linepr + 4) == 79)))
		longest = longest + 1;
	if (*(linepr + 4) == 112 || (*linepr == 35 && (*(linepr + 4) == 120 ||
		*(linepr + 4) == 88)))
		longest = longest + 2;
	if (!*(lenth + 1) && !llinum)
		longest = longest - 1;
	return (longest);
}
