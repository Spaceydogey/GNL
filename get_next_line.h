/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 10:28:41 by hdelmas           #+#    #+#             */
/*   Updated: 2022/10/26 11:11:32 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# define buffer_size 16

int	    ft_strlen(const char *s);
int	ft_len_to_add(char *str);
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);
char	*ft_strdup(char *s, int *check);
void	ft_bzero(void *s, size_t n);
char	*ft_strjoin(char *s1, char *s2, int *check);
char	*get_next_line(int fd);

#endif
