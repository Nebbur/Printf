/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboia-pe <rboia-pe@student.42porto.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 02:19:58 by rboia-pe          #+#    #+#             */
/*   Updated: 2023/04/07 02:19:58 by rboia-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/// @brief 		converts a float into a string or exponent string
/// @param f 	struct containing the format parameters and the float

size_t	ft_intlen(int n)
{
	long int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	printf("Valor de len %ld\n", len);
	return (len);
}

void	type_u(t_flags *f)
{
	unsigned int a[10];
	unsigned int j = 1, m = 1000000000, n, sum = 0;

	n = (int)va_arg(f->args, unsigned int);
	a[0] = n / m;
	for (; j < 10; j++)
	{
		m /= 10;
		a[j] = (n / m) % 10;
	}
	for (j = 0; j < 10; j++)
	{
		sum += a[j];
		if (sum != 0 || j == 9)
			f->len += ft_putchar('0' + a[j]);
	}
}

void	type_i(t_flags *f)
{
	int a[10];
	int j = 1, m = 1000000000, n, sum = 0;

	n = (int)va_arg(f->args, int);
	if (n < 0)
	{
		n *= -1;
		f->len += ft_putchar('-');
	}
	a[0] = n / m;

	for (; j < 10; j++)
	{
		m /= 10;
		a[j] = (n / m) % 10;
	}

	for (j = 0; j < 10; j++)
	{
		sum += a[j];
		if (sum != 0 || j == 9)
			f->len += ft_putchar('0' + a[j]);
	}
}

void	ft_diux(t_flags *f)
{
	if (f->specifier_type == 'i' || f->specifier_type == 'd') 
		type_i(f);
	else if (f->specifier_type == 'u')
		type_u(f);
	else if (f->specifier_type == 'x' || f->specifier_type == 'X')
		type_x(f);
}