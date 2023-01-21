/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42.istanbul.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 21:22:55 by bkaramol          #+#    #+#             */
/*   Updated: 2022/11/14 21:39:07 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*fill_buf(char *buf, int loc)
{
	char	*result;

	result = NULL;
	if (loc == -1)
		result = NULL;
	else
		result = ft_strjoin_gnl(NULL, &buf[loc + 1]);
	free(buf);
	buf = NULL;
	return (result);
}

char	*create_result(char *buf, int loc)
{
	char	c;
	char	*result;

	if (!buf)
		return (NULL);
	if (loc == -1)
	{
		result = ft_strjoin_gnl(NULL, buf);
		return (result);
	}
	c = buf[loc + 1];
	buf[loc + 1] = '\0';
	result = ft_strjoin_gnl(NULL, buf);
	buf[loc + 1] = c;
	return (result);
}

char	*ft_read(int fd, char *buf, int *loc)
{
	char	s[2];
	int		read_c;
	int		i;

	i = 0;
	read_c = 0;
	while (ft_strchr_gnl(buf, &i, loc) == -1)
	{
		read_c = read(fd, s, 1);
		if (read_c <= 0)
			break ;
		s[read_c] = '\0';
		buf = ft_strjoin_gnl(buf, s);
	}
	return (buf);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*result;
	int			loc;

	loc = 0;
	result = NULL;
	if (fd < 0 || fd > 1024)
		return (NULL);
	buf = ft_read(fd, buf, &loc);
	if (buf == NULL)
		return (NULL);
	result = create_result(buf, loc);
	buf = fill_buf(buf, loc);
	if (result[0] == '\0')
		result = NULL;
	return (result);
}
