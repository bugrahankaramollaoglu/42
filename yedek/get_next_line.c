#include "get_next_line.h"
#include <stdio.h>

char *ft_buff(int fd, char *str)
{

	int rd_bytes;

	char *buff;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));

	if (!buff)
		return (NULL);

	rd_bytes = 1;

	while (!ft_strchr(str, '\n') && rd_bytes != 0)
	{

		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(str);
			free(buff);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	return (str);
}

char *get_next_line(int fd)
{
	char *line;

	static char *str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	str = ft_buff(fd, str);
	if (!str)
		return (NULL);
	printf("str ne geldi: %s\n", str);

	line = ft_get_line(str);

	str = ft_last_str(str);

	return (line);
}

int main()
{
	char *metin;

	int fd = open("abc.txt", O_CREAT | O_RDWR, 777);

	metin = get_next_line(fd);

	while (metin)
	{
		printf("%s", metin);
		free(metin);
		metin = get_next_line(fd);
	}
}
