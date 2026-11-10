/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaestre <jmaestre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 11:12:59 by username          #+#    #+#             */
/*   Updated: 2026/10/30 20:35:13 by jmaestre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_format(char c, va_list args)
{
	int	i;

	i = 0;
	if (c == 'c')
		i = ft_putchar(va_arg(args, int));
	else if (c == 's')
		i = ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		i = ft_putptr(va_arg(args, void *));
	else if (c == 'd' || c == 'i')
		i = ft_putnbr((long) va_arg(args, int));
	else if (c == 'u')
		i = ft_putnbr_u(va_arg(args, unsigned int));
	else if (c == 'x')
		i = ft_puthex((unsigned long long) va_arg(args, unsigned int), 1);
	else if (c == 'X')
		i = ft_puthex((unsigned long long) va_arg(args, unsigned int), 0);
	else if (c == '%')
		i = ft_putchar('%');
	else
		i = ft_putchar(c);
	return (i);
}

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		i;
	int		total;

	va_start(args, format);
	i = 0;
	total = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			total += check_format(format[i + 1], args);
			i++;
		}
		else
			total += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (total);
}
