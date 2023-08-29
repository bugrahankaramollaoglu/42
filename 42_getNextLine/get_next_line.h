/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42.istanbul.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 01:02:00 by bkaramol          #+#    #+#             */
/*   Updated: 2022/11/12 01:02:00 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 3
#endif

size_t ft_strlen(char *str);
char *ft_buff(int fd, char *str);
char *get_next_line(int fd);
char *ft_strjoin(char *str, char *buff);
char *ft_strchr(char *str, int c);
char *ft_get_line(char *str);
char *ft_last_str(char *str);
#endif
