/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaestre <jmaestre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 17:49:38 by username          #+#    #+#             */
/*   Updated: 2026/10/30 20:06:53 by jmaestre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long long num, int lowercase)
{
	int		i;
	char	*base;

	if (lowercase)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	i = 0;
	if (num >= 16)
		i += ft_puthex(num / 16, lowercase);
	i += ft_putchar(base[num % 16]);
	return (i);
}
