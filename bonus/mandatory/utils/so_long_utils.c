/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokten <yokten@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 18:47:21 by yokten            #+#    #+#             */
/*   Updated: 2023/05/04 04:19:02 by yokten           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = n * -1;
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else if (n < 10)
		ft_putchar_fd(n + '0', fd);
}

int	len_size(int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
	{
		len++;
	}
	else if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n != 0)
	{
		n /= 10 ;
		len ++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*a;
	size_t	i;
	size_t	len;

	i = 0;
	len = len_size(n);
	a = malloc((len + 1) * sizeof(char));
	if (!a)
		return (0);
	a[len] = '\0';
	while (i < len--)
	{
		a[len] = (n % 10) + '0';
		n /= 10;
	}
	return (a);
}
