/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:37:27 by hdelmas           #+#    #+#             */
/*   Updated: 2022/10/27 15:09:04 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*test;
	int		i;
	int		end;

	i = 0;
	end = 2;
	fd = open("test_file", O_RDONLY);
	while (++i < end)
	{
		test = get_next_line(fd);
		printf("%d:%s", i, test);
		free(test);
	}
	close(fd);
	i = 0;
	end = 9;
	fd = open("test_file", O_RDONLY);
	while (++i < end)
	{
		test = get_next_line(fd);
		printf("%d:%s", i, test);
		free(test);
	}
	close(fd);
//	system("leaks a.out");
}
