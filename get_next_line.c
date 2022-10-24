/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 10:24:06 by hdelmas           #+#    #+#             */
/*   Updated: 2022/10/24 14:45:49 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	size_t	read_check;
	char	*buf;
	char	*last;
	char	*res;

	while (buf != "\n" || !buf)
	{
		buf = malloc(sizeof(char) * 16);
		if (!buf)
			return (NULL);
		read_check = read(fd, buf, buf_size);
		if (read_check == -1)
			return (NULL);
		ft_strljoin(res,buff,buf_size);
	}
	free(buf);
	return (res);
}
