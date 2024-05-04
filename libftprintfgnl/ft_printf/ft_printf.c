/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aproust <aproust@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:43:02 by aproust           #+#    #+#             */
/*   Updated: 2023/03/23 15:17:52 by aproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_sequel(char c, va_list args)
{
	void	*p;

	if (c == '\0')
		return (0);
	if (c == 'c')
		return (ft_putcharfd(va_arg(args, int), 1));
	if (c == 's')
		return (ps(va_arg(args, char *)));
	if (c == 'p')
	{
		p = va_arg(args, void *);
		if (p)
			return (ps("0x") + pu((long unsigned int)p, 16, L16));
		else
			return (write(1, "(nil)", 5));
	}
	if (c == 'd' || c == 'i')
		return (putnb(va_arg(args, int), 1));
	if (c == 'u')
		return (pu(va_arg(args, unsigned int), 10, B10));
	if (c == 'x')
		return (pu(va_arg(args, unsigned int), 16, L16));
	if (c == 'X')
		return (pu(va_arg(args, unsigned int), 16, B16));
	return (ft_putcharfd('%', 1));
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	if (!format)
		return (0);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			count += ft_printf_sequel(format[i + 1], args);
			i += 2;
		}
		else
			count += ft_putcharfd(format[i++], 1);
	}
	va_end(args);
	return (count);
}

// int	main(void)
// {
// 	ft_printf(NULL);
// }
