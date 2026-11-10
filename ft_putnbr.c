/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaestre <jmaestre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 16:59:48 by username          #+#    #+#             */
/*   Updated: 2026/10/30 20:21:33 by jmaestre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long num)
{
	int		i;
	char	*base;

	i = 0;
	base = "0123456789";
	if (num < 0)
	{
		i += ft_putchar('-');
		num = -num;
	}
	if (num >= 10)
		i += ft_putnbr(num / 10);
	i += ft_putchar(base[num % 10]);
	return (i);
}

int	ft_putnbr_u(unsigned int num)
{
	int		i;
	char	*base;

	i = 0;
	base = "0123456789";
	if (num >= 10)
		i += ft_putnbr_u(num / 10);
	i += ft_putchar(base[num % 10]);
	return (i);
}
