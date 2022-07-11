#include <stdlib.h>
#include <unistd.h>

int	exputstr(char *s)
{
	if (s == NULL)
	{
		write(1, "null", 6);
		return (6);
	}
	int i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	exnumber(int c)
{
	int i = 0;
	if (c > 9)
	{
		i = 
	}
	
	return (i);
}