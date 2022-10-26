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

int	ft_len_to_add(char *str)
{
	int	len_to_add;

	len_to_add = 0;
	while (len_to_add < buffer_size)
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
	while (*check == -1)
	{
		int		read_check;
		int		len_to_add;
		char	buf[buffer_size + 1];

		ft_bzero(buf, buffer_size + 1);
		read_check = read(fd, buf, buffer_size);
		if (read_check == -1)
			return (NULL);
		len_to_add = ft_len_to_add(buf);
		ft_strlcpy(remains, &buf[(len_to_add)], buffer_size + 1);
		ft_strlcpy(buf, buf, len_to_add + 1);
		res = ft_strjoin(res, buf, check);
		if (read_check == 0)
		{
			ft_bzero(remains, buffer_size + 1);
			break ;
		}
	}
	return (res);
}

char	*get_next_line(int fd)
{
	int			check;
	static char	remains[buffer_size + 1];
	char		*res;

	check = -1;
	res = ft_strdup(remains, &check);
	ft_strlcpy(remains, &remains[check + 1], buffer_size + 1);
	res = add_to_line(res, remains, &check, fd);
	if (res[0] == '\0')
		return (NULL);
	return (res);
}
