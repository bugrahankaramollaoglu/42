/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 03:55:00 by bkaramol          #+#    #+#             */
/*   Updated: 2022/07/24 15:01:19 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// This function is exactly the same as our ft_putnbr function except that we
// will be using our ft_putchar_fd function instead of ft_putchar beacuse we 
// will be accepting a parameter for this function that is our file descriptor.

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{	
		write(fd, "-2147483648", 11);
		return ;
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
}

/* #include <fcntl.h>
int main()
{
	int xxy = open("abc.txt", O_CREAT | O_RDWR);
	write(xxy, "test", 4);
	int x = 2434;
	ft_putnbr_fd(x, 1);
} */