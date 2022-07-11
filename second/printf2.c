#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int	exputstr(char *s);

int	ex_printf(const char *format, ...)
{
	va_list list;
	va_start(list, format);
	int i = 0;
	int bytes_read = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'd')
			{
				bytes_read += exnumber(va_arg(list, int));
				//itoa
			}
			else if (format[i] == 's')
			{
				bytes_read += exputstr(va_arg(list, char *));
			}
			else if (format[i] == 'x')
			{
				bytes_read += exhexa(va_arg(list, unsigned int));
				//hexa convert
			}
			else if (format[i] == '%')
			{
				write(1, "\%", 1);
				bytes_read += 1;
			}
				i++;
		}
		else
		{
		write(1, &format[i], 1);
		bytes_read += 1;
		i++;
		}
	}
	va_end(list);
	return(bytes_read);
}

int main()
{
	printf("My value:%d\n", ex_printf("%s\n", "1234"));
	printf("Original value:%d\n", printf("%s\n", "1234"));
}

// int main()
// {
// 	ft_printf("%s\n", "toto");
// 	printf("%s\n", "toto");
// 	ft_printf("Magic %s is %d", "number", 42);
// 	printf("Magic %s is %d", "number", 42);
// 	ft_printf("Hexadecimal for %d is %x\n", 42, 42);
// 	printf("Hexadecimal for %d is %x\n", 42, 42);
// }


/*
1. 







*/