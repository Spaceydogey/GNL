/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 11:18:17 by hdelmas           #+#    #+#             */
/*   Updated: 2022/10/28 11:20:02 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_len_to_add(char *str)
{
	int	len_to_add;

	len_to_add = 0;
	while (len_to_add < BUFFER_SIZE)
	{
		if (str[len_to_add] == '\n' || str[len_to_add] == '\0')
		{
			len_to_add++;
			break ;
		}
		len_to_add++;
	}
	return (len_to_add);
}

char	*add_to_line(char *res, char *remains, int *check, int fd)
{
	int		read_check;
	int		len_to_add;
	char	buf[BUFFER_SIZE + 1];

	while (*check == -1)
	{
		ft_bzero(buf, BUFFER_SIZE + 1);
		read_check = read(fd, buf, BUFFER_SIZE);
		if (read_check == -1)
		{
			free(res);
			ft_bzero(remains, BUFFER_SIZE + 1);
			return (NULL);
		}
		len_to_add = ft_len_to_add(buf);
		ft_strlcpy(remains, &buf[(len_to_add)], BUFFER_SIZE + 1);
		ft_strlcpy(buf, buf, len_to_add + 1);
		res = ft_strjoin(res, buf, check);
		if (read_check == 0)
		{
			ft_bzero(remains, BUFFER_SIZE + 1);
			break ;
		}
	}
	return (res);
}

char	*get_next_line(int fd)
{
	int			check;
	static char	remains[OPEN_MAX][BUFFER_SIZE + 1];
	char		*res;

	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE < 1)
		return (NULL);
	check = -1;
	res = ft_strdup(remains[fd], &check);
	ft_strlcpy(remains[fd], &remains[fd][check + 1], BUFFER_SIZE + 1);
	res = add_to_line(res, remains[fd], &check, fd);
	if (!res || res[0] == '\0')
	{
		free(res);
		return (NULL);
	}
	return (res);
}
