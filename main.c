#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main()
{
	int fd;
	char *test;
	int	i = -1;

	fd = open("test_file", O_RDONLY);
	if (fd == -1)
		return(2);
	test = get_next_line(fd);
	while (++i < 23)
		printf("%c", test[i]);
	close(fd);
}
