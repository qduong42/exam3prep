#include "ft_printf.h"

void	ex_putchar(int c)
{
	write(1, &c, 1);
}

int	ex_putstr(char *str)
{
	int i = 0;
	if (str == NULL)
		return (write(1, "(null)", 6));
	while (str[i])
	{
		write(1, &str[i], 1);
		i ++;
	}
	return (i);
}

int	exputnbr(int c)
{
	int i = 0;
	if (c == -2147483648)
	{
		return (write(1, "-2147483648", 11));
	}
	if (c < 0)
	{
		c = -c;
		write(1, "-", 1);
		i++;
	}
	if (c >= 10)
	{
		i += exputnbr(c / 10);
		exputnbr(c % 10);
	}
	else
	{
		ex_putchar(c + '0');
	}
	i++;
	return (i);
}

int	puthexnbr(unsigned int c)
{
	int i = 0;
	// unsigned int a;
	// a = (unsigned int)c;
	if (c >= 16)
	{
		i += puthexnbr(c / 16);
		puthexnbr(c % 16);
	}
	else if (c > 9 )
	{
		ex_putchar(c + 'a' - 10);
	}
	else
		ex_putchar(c + '0');
	i++;
	return (i);
}

int ft_printf(const char *format, ...)
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
			bytes += exputnbr(va_arg(a, int));
			else if (format[i] == 'x')
			bytes += puthexnbr(va_arg(a, unsigned int));
			else if (format[i] == 's')
			bytes += ex_putstr(va_arg(a, char *));
		}
		else
		{
			bytes += write(1, &format[i], 1);
		}
		i++;
	}
	va_end(a);
	return (bytes);
}

// int main()
// {
	//char a[] = "ugdhiawuhdwakdhwuisadiuah";
	// printf("decFake:return val%d\n", ft_printf(" %d ", 10));
	// printf("decreal:return val%d\n", printf(" %d ", 10));
	// printf("hexFake:return val%d\n", ft_printf(" NULL %s NULL ", NULL));
	// printf("hexreal:return val%d\n", printf(" NULL %s NULL ", NULL));
	// printf("string real:return val%x\n", printf("%s", a));
	// printf("string fake:return val%x\n", ex_printf("%s", a));
	// write(1, "\n", 1);
// 	return (0);
// }