/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 11:30:21 by hdelmas           #+#    #+#             */
/*   Updated: 2022/10/24 13:27:01 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		++i;
	return (i);
}

char	*ft_strljoin(char *dst, const char *src, size_t len)
{
	char	*res;
	size_t	len_dest;
	size_t	len_join;

	if (!dst || !src)
		return (NULL);
	len_dst = ft_strlen(dst)
	len_join = len_dest + len;
	res = malloc(sizeof(char) * (len_join + 1));
	if (!strjoin)
		return (NULL);
	i = 0;
	*res = *dst;
	while (res[len_dst + i])
	{
		res[len_dst + i] = src[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
