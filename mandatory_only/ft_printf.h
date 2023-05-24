/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboia-pe <rboia-pe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 02:19:58 by rboia-pe          #+#    #+#             */
/*   Updated: 2023/04/07 02:19:58 by rboia-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "libft/libft.h"
#include <stdarg.h>
#include <stddef.h>
#include <limits.h>

#include <stdio.h>

typedef struct	s_flags
{
	va_list	args;

	char	specifier_type;
	char	*string;

	int		len;
}				t_flags;

const char *ft_pf_type(t_flags *f, char *s);

void	ft_pf_f_init(t_flags *f);
void	ft_diux(t_flags *f);

int		ft_printf(const char *format, ...);

int ft_putchar(char c);
void type_x(t_flags *f);
void ft_csp(t_flags *f);
void type_s(t_flags *f);
void type_p(t_flags *f);
char *_itoa(unsigned long int value, int base);

#endif