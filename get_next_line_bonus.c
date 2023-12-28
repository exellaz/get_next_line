/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:20:58 by kkhai-ki          #+#    #+#             */
/*   Updated: 2023/11/17 17:44:16 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_store_str(int fd, char *stored)
{
	char	*buffer;
	int		i;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	i = 1;
	while (!ft_has_newline(stored) && i != 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			free(buffer);
			return (0);
		}
		buffer[i] = '\0';
		stored = ft_strjoin(stored, buffer);
	}
	free(buffer);
	return (stored);
}

char	*ft_get_line(char *stored)
{
	int		i;
	char	*str;

	i = 0;
	if (!*stored)
		return (0);
	while (stored[i] && stored[i] != '\n')
		i++;
	str = malloc(sizeof(char) * (i + 2));
	if (!str)
		return (0);
	i = 0;
	while (stored[i] && stored[i] != '\n')
	{
		str[i] = stored[i];
		i++;
	}
	if (stored[i] == '\n')
	{
		str[i] = stored[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_get_new_stored(char *stored)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	while (stored[i] && stored[i] != '\n')
		i++;
	if (!stored[i])
	{
		free(stored);
		return (0);
	}
	str = malloc(sizeof(char) * (ft_strlen(stored) - i + 1));
	if (!str)
		return (0);
	i++;
	j = 0;
	while (stored[i])
		str[j++] = stored[i++];
	str[j] = '\0';
	free(stored);
	return (str);
}

char	*get_next_line(int fd)
{
	static char		*stored[OPEN_MAX];
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= OPEN_MAX)
		return (0);
	stored[fd] = ft_store_str(fd, stored[fd]);
	if (!stored[fd])
		return (0);
	line = ft_get_line(stored[fd]);
	stored[fd] = ft_get_new_stored(stored[fd]);
	return (line);
}

// int	main(void)
// {
// 	int		fd1 = open("test/test.txt", O_RDONLY);
// 	char	*stored;
// 	char	*line;
// 	int		len;

// 	stored = ft_store_str(fd1, stored);
// 	line = ft_get_line(stored);
// 	len = ft_strlen(line);
// 	printf("%s", stored);
// 	printf("%s", line);
// 	stored = ft_get_new_stored(stored, len);
// 	printf("%s\n", stored);
// }

	// int main(void)
	// {
	// 	int	fd1;

	// 	fd1 = open("test/test.txt", O_RDONLY);
	// 	printf("%s", get_next_line(fd1));
	// 	// printf("%s", get_next_line(fd1));
	// }