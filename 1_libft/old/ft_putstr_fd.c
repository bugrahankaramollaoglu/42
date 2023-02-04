/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 03:46:37 by bkaramol          #+#    #+#             */
/*   Updated: 2022/07/29 00:00:07 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// putchar tek bir karakter yazdırıyordu. string yazdırmak
// istediğimizde yapmamız gereken tek şey bunu döngüye almak (s[i]) bitene kadar
// putchar uygulamak (ve tabi i'yi increment etmek)

void ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return;
	write(fd, s, ft_strlen(s));
}

#include <fcntl.h>
#include <stdio.h>
int main()
{
	int fd = open("abc.txt", O_CREAT | O_RDWR);
	write(fd, "test", 4);
	char x[] = "niye";
	ft_putstr_fd(x, fd);
}