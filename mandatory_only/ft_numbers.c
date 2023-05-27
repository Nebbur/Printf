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

/* static size_t	ft_intlen(int n)
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
	return (len);
} */

void	type_u(t_flags *f)
{
	unsigned int	a[10];
	unsigned int	j;
	unsigned int	m;
	unsigned int	n;
	unsigned int	sum;

	j = 0;
	m = 1000000000;
	sum = 0;
	n = (int)va_arg(f->args, unsigned int);
	a[0] = n / m;
	while (++j < 10)
	{
		m /= 10;
		a[j] = (n / m) % 10;
	}
	j = -1;
	while (++j < 10)
	{
		sum += a[j];
		if (sum != 0 || j == 9)
			f->len += ft_putchar('0' + a[j]);
	}
}

void	type_i(t_flags	*f)
{
	int	n;
	int			digits[10];
	int			digit_count;

	n = (int)va_arg(f->args, int);
	digit_count = 0;
	if (n == -2147483648)
	{
		f->len += ft_putstr("-214");
		n = 7483648;
	}
	else if (n < 0)
	{
		n *= -1;
		f->len += ft_putchar('-');
	}
	while (n > 0 || digit_count == 0)
	{
		digits[digit_count++] = n % 10;
		n /= 10;
	}
	while (--digit_count >= 0)
		f->len += ft_putchar ('0' + digits[digit_count]);
}

void	ft_diux(t_flags *f)
{
	int	n;
	n = (int)va_arg(f->args, int);
	if (f->specifier_type == 'i' || f->specifier_type == 'd')
		f->len += ft_putnbr_base(n, "0123456789");
	else if (f->specifier_type == 'u')
		type_u(f);
	else if (f->specifier_type == 'x')
		f->len += ft_putnbr_base(n, "0123456789abcdef");
	else if (f->specifier_type == 'X')
		f->len += ft_putnbr_base(n, "0123456789ABCDEF");

}
