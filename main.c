/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:37:27 by hdelmas           #+#    #+#             */
/*   Updated: 2022/10/27 16:29:39 by hdelmas          ###   ########.fr       */
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
	end = 5;
	fd = open("empty", O_RDONLY);
	while (++i < end)
	{
		test = get_next_line(fd);
		printf("%d:%s", i, test);
		free(test);
	}	
	close(fd);
	system("leaks a.out");
}
