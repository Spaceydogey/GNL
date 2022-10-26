/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 10:24:06 by hdelmas           #+#    #+#             */
/*   Updated: 2022/10/26 12:55:25 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;
	size_t	len_to_check;

	i = 0;
	len_to_check = 0;
	if (!s)
		return (NULL);
	while (start < ft_strlen(s)
		&& s[start + len_to_check] && len_to_check < len)
		len_to_check++;
	res = malloc(sizeof(char) * (len_to_check + 1));
	if (!res)
		return (NULL);
	if (start < ft_strlen(s))
	{
		while (s[start + i] && i < len_to_check)
		{
			res[i] = s[start + i];
			i++;
		}
	}
	res[i] = '\0';
	free(s);
	return (res);
}

char	*ft_strdup(const char *s, int *check)
{
	int		len;
	int		i;
	char	*res;

	len = 0;
	i = 0;
	while (s[len])
	{
		if (s[len] == '\n')
		{
			len++;
			break;
		}
		len++;
	}
//	printf("len >>>>> %d\n",len);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (0);
	while (i < len) 
	{
		res[i] = s[i];
//		printf("while :i >>>> %d\n", i);
		i++;
	}
//	printf("last :i >>>> %d\n", i);
	res[i] = '\0';
	if (res[i - 1] == '\n')
	{
		i = i - 1;
		*check = i;
	//	printf("i >>>> %d\n", i);
	//	printf("check >>>> %d\n", *check);
		return (res);
	}
	return (res);
}

char	*get_next_line(int fd)
{
	int		read_check;
	int			check;
	int		len_to_add;
	char		*buf;
	static char	*remains;
	char		*res;

	check = -1;
	if (!remains)
	{
		remains = malloc(sizeof(char *));
		if (!remains)
			return (NULL);
	}
//	printf("remains > [%s]\n", remains);
	res = ft_strdup(remains, &check);
	if (check != -1)
	{
		len_to_add = ft_strlen(&remains[check + 1]);
		remains = ft_substr(remains, check + 1, len_to_add);
		if (!remains)
			return (NULL);
//		printf("remains > [%s]\n", remains);
		return(res);
	}
	free(remains);
	while (check == -1)
	{
		buf = malloc(sizeof(char) * buffer_size);
		if (!buf)
			return (NULL);
		read_check = read(fd, buf, buffer_size);
		if (read_check == -1)
			return (NULL);
		if (read_check == 0)
			return (res);
		len_to_add = ft_len_to_add(buf);
		remains = ft_add_remains(buf, len_to_add);
//		printf("hi > [%s]\n", remains);
		buf = ft_to_join(buf, len_to_add);
		res  = ft_strjoin(res, buf, &check);
		free(buf);
	}
	return (res);
}
