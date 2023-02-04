/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 03:33:39 by bkaramol          #+#    #+#             */
/*   Updated: 2022/07/25 11:37:23 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* A file descriptor is a positive number
that uniquely identifies an open file in
a computer's operating system. The descriptor
is identified by a unique non-negative integer,
such as 0, 12, or 567. At least one file descriptor
exists for every open file on the system. File
descriptors were first used in Unix, and are used
by modern operating systems including Linux, macOS,
and BSD. In Microsoft Windows, file descriptors
are known as file handles. ilk 3 FD default olarak şunlardır:
    - 0 - standard input (stdin): The default data stream for input, for example in a command pipeline.
    In the terminal, this defaults to keyboard input from the user.
    - 1 - standard output (stdout): The default data stream for output,
    for example when a command prints text. In the terminal, this defaults to the user's screen.
    - 2 - standard error: The default data stream for output that relates
    to an error occurring. In the terminal, this defaults to the user's screen.*/
#include <fcntl.h>

void ft_putchar_fd(char c, int fd)
{
    write(fd, &c, 1);
}

int main()
{
    int x = open("bugra.txt", O_CREAT | O_RDWR);
    ft_putchar_fd('s', x);
    ft_putchar_fd('\n', x);
    ft_putchar_fd('a', x);
}

// sonrasında izin vermezse sudo chmod 777 ile izin alıp dosyaya bakabilirsin

