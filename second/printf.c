#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <limits.h>

// integer(int d)
// {
// 	putnbr;
// }

int putnn(int a)
{
	int size = 0;

	if (a == -2147483648)
	{
		return (write(1, "-2147483648", 11));
	}
	if (a < 0)
	{
		a = -a;
		size += write(1, "-", 1);
	}
	if (a > 9)
	{
		putnn(a / 10);
		putnn(a % 10);
	}
	else
		ft_putchar(a + '0');
}

// MIN_INT from limits.h

int string(char *a)
{
	int i;

	i = 0;
	if (a == NULL)
	{
		write(1, "null", 6);
		return (6);
	}
	while (a[i])
	{
		write(1, &a[i], 1);
		i++;
	}
	return (i);
}

// int	integer(int a)
// {

// }

int exam_printf(const char *format, ...)
{
	va_list a;
	va_start(a, format);
	int i = 0;
	int bytes = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'd')
			{
				bytes +=putnn(va_arg(a, int));
			}
			if (format[i] == 's')
			{
				bytes +=string(va_arg(a, char *));
			}
			// if (format[i + 1] == 'x')
			// {
			// 	bytes += hexa(va_arg(a, int));
			// }
		}
		else
		{
		write(1, &format[i], 1);
		bytes ++;
		}
		i++;
	}
	va_end(a);
	return (bytes);
}

int main()
{
	char a[]="123456";
	printf("%d\n",exam_printf("123456789%s123456789\n", a));
	printf("%d\n",printf("123456789%s123456789\n", a));
	return (0);
}
//	va_list to init va_list
//	va_start adds format to list
//	va_arg