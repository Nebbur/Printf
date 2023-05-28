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

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stddef.h>
# include <limits.h>

typedef struct s_flags
{
	va_list	args;
	char	specifier_type;
	char	*string;
	int		len;
	long	n;
}				t_flags;
/*

			|⎺⎺⎺\	/⎺⎺⎺|	   /⎺⎺⎺\	  |⎺⎺⎺⎺⎺⎺⎺⎺⎺|  |⎺⎺⎺⎺\ |⎺⎺|
			|	 \ /    |	  /	/⎺\ \	   ⎺⎺⎺| |⎺⎺⎺   |     \|  |
			|	  ⎺     |	 /	⎺⎺⎺	 \		  | |	   |  |\  \  |
			|   |⎺⎺⎺|   |	/  /⎺⎺⎺\  \       | |	   |  |	\  \ |
			|   | 	|   |  /  /		\  \  |⎺⎺⎺   ⎺⎺⎺|  |  |	 \  \|
             ⎺⎺⎺     ⎺⎺⎺   ⎺⎺⎺       ⎺⎺⎺   ⎺⎺⎺⎺⎺⎺⎺⎺⎺    ⎺⎺    ⎺⎺⎺
*/
int			ft_printf(const char *format, ...);
void		ft_pf_f_init(t_flags *f);
const char	*ft_pf_type(t_flags *f, char *s);

/*##################~~~~~NUMBERS~~~~~~###################*/
void		type_i(t_flags	*f);
void		ft_diux(t_flags *f);

/*##################~~~~~HEXA~~~~~~###################*/
void		hexa(unsigned long nbr, char *base, unsigned int size, t_flags *f);

/*##################~~~~~CSP~~~~~~###################*/
void		type_s(t_flags *f, char *str);

/*##################~~~~~AUX~~~~~~###################*/
int			ft_putchar(char c);
int			ft_putstr(char *str);
int			ft_strcmp(char *s1, char *s2);

size_t		ft_strlen(const char *str);

char		*ft_strchr(const char *str, int d);
char		*ft_itoa_base(unsigned long int value, int base);

#endif