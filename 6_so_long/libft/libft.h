/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42.istanbul.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 03:12:20 by bkaramol          #+#    #+#             */
/*   Updated: 2022/11/14 21:39:06 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <fcntl.h>
# include <stdarg.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

int		ft_strlen(const char *s);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(const char *s, char c);

// get_next_line
char	*get_next_line(int fd);
char	*read_fd(int fd, char *str, char *temp, char *buf);
char	*read_line(char *str);
char	*not_read(char *str);
int		is_newline(char *str);
char	*ft_strjoin_gnl(char *s1, char *s2);
int		ft_strlen_gnl(char *str);
int		ft_strchr_gnl(char *str, int *i, int *give_loc);

// ft_printf
int		ft_printf(const char *fmt, ...);
int		ft_print_char(int c);
int		ft_print_string(char *str);
int		ft_print_point(unsigned long long n);
int		ft_print_int(int num);
int		ft_print_unsigned_int(unsigned int num);
int		ft_print_hex(unsigned int hex, char c);

#endif
