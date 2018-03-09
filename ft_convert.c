/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvertohr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 11:29:02 by tvertohr          #+#    #+#             */
/*   Updated: 2018/03/07 11:29:04 by tvertohr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define CH(a,b) (a == 111 || a == 120 || a == 79 || a == 88) && b

LLI			ft_integeru_conv(va_list ap, char c, char cc)
{
	char	tmp;
	LLI		result;

	result = 0;
	tmp = c;
	if (tmp == 72)
	{
		result = va_arg(ap, unsigned int);
		if (result != CHECK)
			result = (unsigned char)result;
	}
	else if (tmp == 108 || ft_isupper(cc))
		result = va_arg(ap, unsigned long int);
	else if (tmp == 104)
		result = (unsigned short)va_arg(ap, unsigned int);
	else if (tmp == 76)
		result = va_arg(ap, unsigned long long int);
	else if (tmp == 106)
		result = va_arg(ap, uintmax_t);
	else
		result = va_arg(ap, size_t);
	return (result);
}

LLI			ft_integer_conv(va_list ap, char c, char cc)
{
	LLI		result;

	result = 0;
	if (c == 72)
	{
		if (cc == 68)
			result = va_arg(ap, unsigned long int);
		else
		{
			result = va_arg(ap, int);
			if (result != CHECK)
				result = (signed char)result;
		}
	}
	else if (c == 108 || ft_isupper(cc))
		result = va_arg(ap, long int);
	else if (c == 104)
		result = (short)va_arg(ap, int);
	else if (c == 76)
		result = va_arg(ap, long long int);
	else if (c == 106)
		result = va_arg(ap, uintmax_t);
	else
		result = va_arg(ap, ssize_t);
	return (result);
}

void		ft_text_err(char *linepr)
{
	int		i;
	char	*s;

	s = "uU";
	i = ft_strindexof(s, *(linepr + 4));
	if (*(linepr + 2) && -1 < i)
		*(linepr + 2) = 0;
	if (*(linepr + 4) == 112 && *(linepr + 2))
		*(linepr + 2) = 0;
	if (CH(*(linepr + 4), *(linepr + 2)))
		*(linepr + 2) = 0;
}

void		ft_err_dupl(char **format, char *linepr, int *lenth)
{
	int		i;
	char	*s;
	int		pls;

	s = ".#0+ ";
	i = ft_strindexof(s, *(*format));
	pls = 43;
	while (-1 < i)
	{
		if (!*(linepr + 1) || !*linepr || !*(linepr + 2))
			ft_flags(format, linepr);
		else if (**format == pls)
		{
			format++;
			*(linepr + 2) = pls;
		}
		else
			format++;
	}
	if (*(linepr + 1) == 45 && *linepr == 35 && *(linepr + 2) == pls)
		*(lenth + 1) = 0;
}
