/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboia-pe <rboia-pe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 09:58:55 by rboia-pe          #+#    #+#             */
/*   Updated: 2023/03/21 08:57:49 by rboia-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_base_rec(int nbr, char *base, int size)
{
	unsigned char	a;
	unsigned int	n;
	unsigned int	count;

	count = 0;
	if (nbr < 0)
	{
		count += ft_putchar('-');
		n = nbr * (-1);
	}
	else
		n = nbr;
	if (n >= (unsigned int)size)
		ft_putnbr_base_rec(n / size, base, size);
	a = base[n % size];
	count += ft_putchar(a);
	return (count);
}

int	ft_ver_bas(char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == base[i + 1])
			return (0);
		i++;
	}
	if (i <= 1)
		return (0);
	return (1);
}

int	ft_putnbr_base(int nbr, char *base)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	if (ft_ver_bas(base) == 1)
	{
		while (base[i] != '\0')
			i++;
		count += ft_putnbr_base_rec(nbr, base, i);
	}
	return (count);
}

/*int main()
{
<32 espaco para tras| 127 DEL | 43 + | 45 -
	printf(" - Binario");
	ft_putnbr_base(69, "01");
	printf("\n - Decimal");
	ft_putnbr_base(-696969, "0123456789");
	printf("\n - Hexadecimal");
	ft_putnbr_base(9898, "0123456789ABCDEF");
	printf("\n - Octal");
	ft_putnbr_base(27, "01234567");
}*/
