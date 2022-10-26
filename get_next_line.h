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

//char	*ft_strljoin(char *dst, char *src, size_t *res_len, int	*check);
int		ft_strlen(const char *s);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2, int *check);
char	*ft_to_join(char *str, int len_to_add);
char	*ft_add_remains(char *str, int len_to_add);
int		ft_len_to_add(char *str);
#endif
