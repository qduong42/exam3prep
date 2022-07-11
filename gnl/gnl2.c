#include "get_next_line.h"

char *get_next_line(int fd)
{
	int read_count, i = 0;
	char c;
	char *buffer;

	buffer = malloc(10000);
	while ((read_count = read(fd, &c, BUFFER_SIZE - BUFFER_SIZE + 1) > 0))
	{
		buffer[i++] = c;
		if (c == '\n')
			break ;
	}
	if (!read_count && !buffer[0] || read_count == -1)
	{
		free(buffer);
		return (NULL);
	}
	// buffer[i] = '\0';
	return (buffer);
}

// char *get_next_line(int fd)
// {
//     int read_count, i = 0;
//     char c;
//     char    *buffer;

//     buffer = malloc(10000);
//     while ((read_count = read(fd, &c, 1) > 0))
//     {
//         buffer[i++] = c;
//         if (c == '\n')  
//             break; 
//     } 
//     if ((!read_count && !buffer[0]) || read_count == -1)
//     {     
//         free(buffer);
//         return NULL;
//     }     
//     buffer[i] = '\0';
//     return (buffer); 
// } 

int main()
{
	int fd;
	char *str;
	fd = open("x.txt", O_RDONLY);
	str = get_next_line(fd);
	while (str != NULL)
	{
		printf("%s", str);
		str=get_next_line(fd);
	}
	free(str);
	close(fd);
	return (0);
}
