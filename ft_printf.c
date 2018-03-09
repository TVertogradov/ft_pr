/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvertohr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 11:12:49 by tvertohr          #+#    #+#             */
/*   Updated: 2018/03/06 11:12:52 by tvertohr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_add(char **format, char *linepr, int *lenth,
	t_ftprintf *line)
{
	int proc;

	proc = 37;
	*(lenth + 3) = *(lenth + 3) + ft_strprintcount(*format, proc);
	*format = *format + ft_strchrlen(*format, proc);
	ft_perameters_put(lenth, linepr, line);
}

int				ft_printf(char *format, ...)
{
	t_ftprintf	line;
	va_list		ap;
	int			lenth[10];
	char		*linepr;

	va_start(ap, format);
	*(lenth + 3) = 0;
	linepr = (char *)malloc(sizeof(char) * 10);
	while (*format != 0)
	{
		ft_add(&format, linepr, lenth, &line);
		if (*format != 0)
		{
			ft_tag_get(&format, linepr, lenth);
			*(lenth + 4) = ft_strindexof(MODS, linepr[4]);
			if (*(lenth + 4) > -1 && format++)
				ft_convertation(ap, linepr, lenth, line);
			else
				ft_underf_s(&format, linepr, lenth, -7);
		}
	}
	va_end(ap);
	free(linepr);
	return (*(lenth + 3));
}

static void		ft_add_conv(LLI result, char *linepr, int *lenth,
	t_ftprintf line)
{
	char		*str[5];
	int			i[5];

	str[0] = "dDi";
	str[1] = "pdDioOuUxX%";
	i[0] = ft_strindexof(str[0], *(linepr + 4));
	i[1] = -1;
	if (result != MRES && result < 0 && i[0] > i[1])
	{
		*(linepr + 2) = 45;
		result = result * i[1];
	}
	if (ft_strindexof(str[1], *(linepr + 4)) > i[1])
		ft_number_pr(linepr, lenth, result);
	else
		ft_string_pr(linepr, lenth, line);
}

void			ft_convertation(va_list ap, char *linepr, int *lenth,
	t_ftprintf line)
{
	LLI	result;

	result = 0;
	if (*(linepr + 4) == 37)
		result = 1;
	else if ((*(linepr + 3) == 108 && *(linepr + 4) == 99) ||
		*(linepr + 4) == 67)
		line.dlina = va_arg(ap, wchar_t);
	else if ((*(linepr + 3) == 108 && *(linepr + 4) == 115) ||
		*(linepr + 4) == 83)
		line.stroka = va_arg(ap, wchar_t *);
	else if (*(linepr + 3) != 108 && *(linepr + 4) == 115)
		line.str = va_arg(ap, const char *);
	else if (*(linepr + 4) == 99)
		line.symbol = va_arg(ap, int);
	else
		result = ft_number_conv(ap, *(linepr + 4), linepr);
	ft_add_conv(result, linepr, lenth, line);
}

LLI				ft_number_conv(va_list ap, char smb, char *linepr)
{
	LLI			result;
	char		*str[4];

	result = 0;
	str[0] = "DIOU";
	str[1] = "oOuUxX";
	str[2] = "di";
	str[3] = "ouxX";
	if (-1 < ft_strindexof(str[0], *(linepr + 4)) || *(linepr + 3))
	{
		if (-1 < ft_strindexof(str[1], smb))
			result = ft_integeru_conv(ap, *(linepr + 3), *(linepr + 4));
		else
			result = ft_integer_conv(ap, *(linepr + 3), *(linepr + 4));
	}
	else
	{
		if (-1 < ft_strindexof(str[2], smb))
			result = va_arg(ap, int);
		else if (-1 < ft_strindexof(str[3], smb))
			result = va_arg(ap, unsigned int);
		else
			result = va_arg(ap, LLI);
	}
	return (result);
}
