/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 10:24:06 by hdelmas           #+#    #+#             */
/*   Updated: 2022/10/25 17:01:56 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	int		read_check;
	int			check;
	char		*buf;
	static char	*remains;
	char		*res;
	int			i = -1;

	
	check = -1;
	res = malloc(sizeof(char));
	if (!res)
		return (NULL);
	remains = malloc(sizeof(char *));
	if (!remains)
		return (NULL);
//	res = ft_add_remains(res, remains, &res_len);
//	free(remains);
	while (check == -1 && ++i < 10)
	{
		buf = malloc(sizeof(char) * buffer_size);
		if (!buf)
			return (NULL);
		read_check = read(fd, buf, buffer_size);
		if (read_check == -1)
			return (NULL);
		buf = to_join(buf, remains);
		res  = ft_strjoin(res, buf, &check);
		free(buf);
	//	printf("GNL > [%s]\n", res);
		printf("check > [%d]\n", check);
		printf("remains> [%s]\n", remains);
	}
	return (res);
}
