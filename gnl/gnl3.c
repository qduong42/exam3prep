#include "get_next_line.h"

char *gnl_3(int fd)
{
	int bytes, i = 0;
	char c;
	char *buffer;
	buffer = malloc(10000);
	while ((bytes = read(fd, &c, BUFFER_SIZE - BUFFER_SIZE + 1) > 0))
	{
		buffer[i++] = c;
		if (c =='\n')
			break;
	}
	if ((!bytes && !buffer[0]) || bytes == -1)
	{
		free(buffer);
		return (NULL);
	}
	buffer[i] = 0;
	return (buffer);
}

// int main()
// {
// 	int fd;
// 	char *str;
// 	fd = open("x.txt", O_RDONLY);
// 	str = gnl_3(fd);
// 	while (str != NULL)
// 	{
// 		printf("%s", str);
// 		str = gnl_3(fd);
// 	}
// 	free(str);
// 	close(fd);
// 	return 0;
// }

int main()
{
	int fd;
	char *str;
	fd = open("x.txt", O_RDONLY);
	str = gnl_3(fd);
	while (str != NULL)
	{
		printf("%s", str);
		str = gnl_3(fd);
	}
	free(str);
	close(fd);
	return (0);
}
