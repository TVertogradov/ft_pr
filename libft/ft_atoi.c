/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvertohr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 15:40:10 by tvertohr          #+#    #+#             */
/*   Updated: 2018/03/09 15:40:17 by tvertohr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						ft_atoi(const char *str)
{
	size_t				i;
	int					s;
	unsigned long int	res;

	i = 0;
	s = 1;
	res = 0;
	while (ft_whitespace(str[i]))
		i++;
	if (str[i] == '-')
		s = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while ((str[i] != '\0') && ft_isdigit(str[i]))
	{
		if ((res > 922337203685477580 || (res == 922337203685477580
						&& (str[i] - '0') > 7)) && s == 1)
			return (-1);
		else if ((res > 922337203685477580 || (res == 922337203685477580
						&& (str[i] - '0') > 8)) && s == -1)
			return (0);
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return ((int)(res * s));
}
