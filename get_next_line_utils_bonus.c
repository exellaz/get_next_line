/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:53:40 by kkhai-ki          #+#    #+#             */
/*   Updated: 2023/12/28 14:20:47 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s++)
		len++;
	return (len);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*dst_temp;
	unsigned const char	*src_temp;

	if (!dst && !src)
		return (0);
	dst_temp = dst;
	src_temp = src;
	while (n-- > 0)
		*dst_temp++ = *src_temp++;
	return (dst);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	size_t	s1_len;
	size_t	s2_len;
	size_t	new_len;

	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		*s1 = '\0';
	}
	if (!s1 || !s2)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_len = s1_len + s2_len;
	result = malloc(sizeof(char) * (new_len + 1));
	if (!result)
		return (0);
	ft_memcpy(result, s1, s1_len);
	ft_memcpy(result + s1_len, s2, s2_len);
	free(s1);
	result[new_len] = '\0';
	return (result);
}

char	*ft_has_newline(char *s)
{
	if (!s)
		return (0);
	while (*s != '\n')
	{
		if (*s == '\0')
			return (0);
		s++;
	}
	return (s);
}
