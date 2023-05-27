/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_csp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboia-pe <rboia-pe@student.42porto.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 02:19:58 by rboia-pe          #+#    #+#             */
/*   Updated: 2023/04/07 02:19:58 by rboia-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * print_pointer - Print a number in hexadecimal format
 * @list: Number to print
 *
 * Return: Length of the number
 **/

/**
 * _strcmp - Compare two strings
 * @s1: String 1
 * @s2: String 2
 * Return: Integer
 **/

int	_strcmp(char *s1, char *s2)
{
	int	i;

	i = -1;
	while (s1[++i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}
	return (0);
}

static char	*_itoa(unsigned long int value, int base)
{
	char				*buffer;
	int					digit_size[2];
	unsigned long int	temp;

	if (base < 2 || base > 36)
		return (NULL);
	temp = value;
	digit_size[1] = 0;
	while (temp > 0)
	{
		temp /= base;
		digit_size[1]++;
	}
	buffer = (char *)malloc((digit_size[1] + 1) * sizeof(char));
	buffer[digit_size[1]] = '\0';
	while (value > 0)
	{
		digit_size[0] = value % base;
		if (digit_size[0] < 10)
			buffer[--digit_size[1]] = digit_size[0] + '0';
		else
			buffer[--digit_size[1]] = digit_size[0] - 10 + 'a';
		value /= base;
	}
	return (buffer);
}

void	type_p(t_flags *f)
{
	char	*p_buff;

	p_buff = _itoa(va_arg(f->args, unsigned long int), 16);
	if (!_strcmp(p_buff, "0"))
		f->len += (ft_putstr("(nil)"));
	if (_strcmp(p_buff, "-1"))
	{
		f->len += ft_putstr ("0x");
		f->len += ft_putstr (p_buff);
	}
}

void	type_s(t_flags *f)
{
	char	*str;
	int		i;

	i = -1;
	str = va_arg(f->args, char *);
	if (str == NULL)
		str = "(null)";
	while (str[++i])
		f->len += ft_putchar(str[i]);
}

void	ft_csp(t_flags *f)
{
	char	c;

	if (f->specifier_type == 'c')
	{
		c = (char)va_arg(f->args, int);
		f->len += ft_putchar(c);
	}
	else if (f->specifier_type == 's')
		type_s(f);
	else
		type_p(f);
}
