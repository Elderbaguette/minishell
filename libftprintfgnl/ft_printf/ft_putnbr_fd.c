/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aproust <aproust@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:54:57 by aproust           #+#    #+#             */
/*   Updated: 2022/11/14 17:54:57 by aproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putnb(int n, int fd)
{
	if (n == -2147483648)
		return (write(fd, "-2147483648", 11));
	if (n < 0)
	{
		ft_putcharfd('-', fd);
		n = -n;
		if (n > 9)
			return (1 + putnb(n / 10, fd) + ft_putcharfd(n % 10 + '0', fd));
		if (n != 0)
			return (1 + ft_putcharfd(n + '0', fd));
	}
	if (n > 9)
		return (putnb(n / 10, fd) + ft_putcharfd(n % 10 + '0', fd));
	if (n != 0)
		return (ft_putcharfd(n + '0', fd));
	return (ft_putcharfd(n + '0', fd));
}

// int	main(void)
// {
// 	printfft_putnbr_fd(-214748364, 1);
// }
