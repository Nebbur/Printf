/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboia-pe <rboia-pe@student.42porto.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 02:19:58 by rboia-pe          #+#    #+#             */
/*   Updated: 2023/04/07 02:19:58 by rboia-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	type_x_aux(t_flags *f, unsigned int j, unsigned int digits[8], \
	char diff);

	//diff = (f->specifier_type == 'x') ? 'a' - ':' : 'A' - ':';
void	type_x(t_flags	*f)
{
	char			diff;
	unsigned int	n_j[2];
	unsigned int	digits[8];

	n_j[0] = va_arg(f->args, unsigned int);
	if (f->specifier_type == 'x')
		diff = 'a' - ':';
	else
		diff = 'A' - ':';
	digits[0] = n_j[0] / 268435456;
	n_j[1] = 0;
	while (++n_j[1] < 8)
		digits[n_j[1]] = (n_j[0] >> (28 - n_j[1] * 4)) & 0xF;
	n_j[1] = -1;
	type_x_aux(f, n_j[1], digits, diff);
}

static void	type_x_aux(t_flags *f, unsigned int j, unsigned int digits[8], \
	char diff)
{
	int	print_zeros;

	print_zeros = 0;
	while (++j < 8)
	{
		if (digits[j] != 0 || j == 7)
		{
			print_zeros = 1;
			if (digits[j] < 10)
				f->len += ft_putchar('0' + digits[j]);
			else
				f->len += ft_putchar('0' + diff + digits[j]);
		}
		else if (print_zeros)
			f->len += ft_putchar('0');
	}
}
