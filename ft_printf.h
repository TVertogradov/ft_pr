/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvertohr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 19:04:25 by tvertohr          #+#    #+#             */
/*   Updated: 2018/03/07 19:04:29 by tvertohr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <limits.h>
# include <stdarg.h>
# include <unistd.h>
# include <wchar.h>
# include <locale.h>
# include "libft/libft.h"
# include <inttypes.h>

# define MODS "sSpdDioOuUxXcC%"
# define LLI long long int
# define MRES -9223372036854775807 - 1
# define CHECK 65535
# define L 0x7F
# define LL 0x7FF
# define LLL 0xFFFF
# define MAX(x, y) ((x < y) ? y : x)

typedef	struct	s_ftprintf
{
	va_list		ap;
	int			symbol;
	const char	*str;
	wchar_t		dlina;
	wchar_t		*stroka;
	int			i;
	char		*lenth;
}				t_ftprintf;

void			ft_tag_get(char **format, char *opt, int *plen);
void			ft_flags(char **fmt, char *opt);
void			ft_lenth(char **fmt, char *opt);
void			ft_linepr_pr(char *opt, int *plen, int max, LLI nbr);
void			ft_base_pr(int base, LLI nbr, char *opt);
void			ft_convertation(va_list ap, char *opt, int *plen,
	t_ftprintf string);
LLI				ft_number_conv(va_list ap, char c, char *opt);
LLI				ft_integer_conv(va_list ap, char opt1, char opt2);
LLI				ft_integeru_conv(va_list ap, char opt1, char opt2);
void			ft_perameters_put(int *plen, char *opt, t_ftprintf *string);
void			ft_underf_s(char **fmt, char *opt, int *plen, int total);
void			ft_make_set(char *opt, int *plen);
void			ft_text_err(char *opt);
void			ft_err_dupl(char **fmt, char *opt, int *plen);
int				ft_printf(char *fmt, ...);
void			ft_get_presis(char **fmt, int *plen);
int				ft_strlenthmax(t_ftprintf string, char *opt, int *plen);
int				ft_numlenthmax(LLI nbr, char *opt, int *plen);
void			ft_string_pr(char *opt, int *plen, t_ftprintf string);
void			ft_number_pr(char *opt, int *plen, LLI nbr);

#endif
