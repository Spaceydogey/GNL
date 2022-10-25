/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 11:30:21 by hdelmas           #+#    #+#             */
/*   Updated: 2022/10/25 17:02:00 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		++i;
	return (i);
}

char	*to_join(char *str, char *remain)
{
	int	len_to_add;
	int	len_to_remain;
	int	i;
	char *res;

	len_to_add = 0;
	len_to_remain = 0;
	while (len_to_add < buffer_size)
	{	
		if (str[len_to_add] == '\n' || str[len_to_add] == '\0')
		{	
			len_to_add++;
			break;
		}
		len_to_add++;
	}
	len_to_remain = buffer_size - len_to_add;
	res = malloc(sizeof(char) * (len_to_add + 1));
	if (!res)
		return (NULL);
	i = -1;
	while (++i < len_to_add)
		res[i] = str[i];
	res[i] = '\0';
	i = -1;
	remain = malloc(sizeof(char) * (len_to_remain + 1));
	if (!remain)
		return (NULL);
	while (++i < len_to_remain)
		remain[i] = str[len_to_add + i];
	return (res);
}

char	*ft_strjoin(char *s1, char *s2, int *check)
{
	char	*strjoin;
	int	i;
	int	j;
	int	len_join;

	if (!s1 || !s2 || (!s1 && !s2))
		return (NULL);
	len_join = ft_strlen(s1) + ft_strlen(s2);
	strjoin = malloc(sizeof(char) * (len_join + 1));
	if (!strjoin)
		return (NULL);
	i = 0;
	j = -1;
	while (s1[++j])
		strjoin[i++] = s1[j];
	j = -1;
	while (s2[++j])
		strjoin[i++] = s2[j];
	strjoin[i] = '\0';	
	if (strjoin[i - 1] == '\n')
	{
		*check = 0;
		return (strjoin);
	}
    *check = -1;
	return (strjoin);
}

/*
char	*ft_strljoin(char *dst, char *src, size_t *res_len, int *check)
{
	char	*tmp;
	size_t	len_join;
	size_t	len_to_add;
	size_t	len_to_remain;
	size_t	i;

	if (!src)
		return (NULL);
	len_to_add = 0;
	while (len_to_add < buffer_size)
	{	
		if (src[len_to_add] == '\n' || src[len_to_add] == '\0')
		{	
			len_to_add++;
			break;
		}
		len_to_add++;
	}
	len_to_remain = buffer_size - len_to_add;
	len_join = *res_len + len_to_add;
	tmp = malloc(sizeof(char) * (*res_len));
	if (!tmp)
		return (NULL);
	i = -1;
	while (++i < *res_len)
		tmp[i] = dst[i];
	free(dst);
	dst = malloc(sizeof(char) * (len_join));
	if (!dst)
		return (NULL);
	i = -1;
	while (++i < *res_len)
		dst[i] = tmp[i];
	free(tmp);
	i = 0;
	while (i < len_to_add)
	{
		dst[*res_len] = src[i];
		i++;
		*res_len = *res_len + 1;
	}
	if (dst[*res_len] == '\n')
	{
		*check = 0;
		return (dst);
	}
    *check = -1;
	return (dst);
}*/

/*char	*ft_add_remains(char *dst, char *remains, size_t *res_len)
{

}*/
