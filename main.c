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
	printf("1:%s", test);
	free(test);
	test = get_next_line(fd);
	printf("2:%s", test);
	free(test);
	test = get_next_line(fd);
	printf("3:%s", test);
	free(test);
	test = get_next_line(fd);
	printf("4:%s", test);
	free(test);
	test = get_next_line(fd);
	printf("5:%s", test);
	free(test);
	test = get_next_line(fd);
	free(test);
	printf("6:%s", test);
	test = get_next_line(fd);
	free(test);
	printf("7:%s", test);
	test = get_next_line(fd);
	free(test);
	printf("8:%s", test);
	close(fd);
}
