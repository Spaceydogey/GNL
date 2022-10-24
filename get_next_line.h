/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 10:28:41 by hdelmas           #+#    #+#             */
/*   Updated: 2022/10/24 15:38:32 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef "GET_NEXT_LINE_H"
# define "GET_NEXT_LINE_H"
# include <unistd.h>
# include <stdlib.h>
# define buffer_size 16
char	*ft_strljoin(char *dst, char *src, size_t len)
char	*get_next_line(int fd);

#endif
