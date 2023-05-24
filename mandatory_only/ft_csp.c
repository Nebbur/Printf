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

int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}
	return (0);
}

char *_itoa(unsigned long int value, int base)
{
    // Verifica a base
    if (base < 2 || base > 36) 
        return NULL;

    // Calcula o tamanho necessário para a string resultante
    unsigned long int temp = value;
    int size = 0;
    while (temp > 0)
	{
        temp /= base;
        size++;
    }

    // Aloca memória para a string resultante
    char *buffer = (char *)malloc((size + 1) * sizeof(char));
    buffer[size] = '\0';

    // Converte o valor para a base especificada
    while (value > 0)
	{
        int digit = value % base;
        if (digit < 10) {
            buffer[--size] = digit + '0';
        } else {
            buffer[--size] = digit - 10 + 'a';
        }
        value /= base;
    }

    // Retorna a string resultante
    return buffer;
}

void	type_p(t_flags *f)
{
	char *p_buff;

	p_buff = _itoa(va_arg(f->args, unsigned long int), 16);
	if (!_strcmp(p_buff, "0"))
		f->len  += (ft_putstr("(nil)"));

	if (_strcmp(p_buff, "-1"))
	{
 		f->len += ft_putstr("0x");
 		f->len += ft_putstr(p_buff);
	}

/* 	if (!_strcmp(p_buff, "-1"))
		f->len += ft_putstr("ffffffffffffffff");
	else 
		f->len += ft_putstr(p_buff); */
}


void	type_s(t_flags *f)
{
	char	*str;
	int	i;

	i = -1;
	str = va_arg(f->args, char *);

	if (str == NULL)
		str = "(null)";
	while (str[++i])
		f->len += ft_putchar(str[i]);
}

void	ft_csp(t_flags *f)
{
	if (f->specifier_type == 'c')
	{
		char	c;
		c = (char)va_arg(f->args, int);
		f->len += ft_putchar(c);
	}
	else if (f->specifier_type == 's')
		type_s(f);
	else
		type_p(f);
}