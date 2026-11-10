/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaestre <jmaestre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 16:16:09 by username          #+#    #+#             */
/*   Updated: 2026/10/30 19:38:12 by jmaestre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putptr(unsigned long long num)
{
	int		i;
	char	*base;

	base = "0123456789abcdef";
	i = 0;
	if (num >= 16)
		i += putptr(num / 16);
	i += ft_putchar(base[num % 16]);
	return (i);
}

int	ft_putptr(void *ptr)
{
	int	i;

	i = 0;
	if (!ptr)
		return (ft_putstr("(nil)"));
	i += ft_putstr("0x");
	i += putptr((unsigned long long) ptr);
	return (i);
}
