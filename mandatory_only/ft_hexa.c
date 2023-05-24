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

void type_x(t_flags *f)
{
	unsigned int a[8];
	unsigned int j = 1, m = 268435456, n, sum = 0;
	char diff;

	n = va_arg(f->args, unsigned int);
    if (f->specifier_type == 'x')
	    diff = 'a' - ':';
    else
	    diff = 'A' - ':';
	a[0] = n / m;
	for (; j < 8; j++)
	{
		m /= 16;
		a[j] = (n / m) % 16;
	}
	for (j = 0; j < 8; j++)
	{
		sum += a[j];
		if (sum || j == 7)
		{
			if (a[j] < 10)
				f->len += ft_putchar('0' + a[j]);
			else
				f->len += ft_putchar('0' + diff + a[j]);
		}
	}
}