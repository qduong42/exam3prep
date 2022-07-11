#include "ft_printf.h"

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

int putstr(char *c)
{
	int i = 0;
	if (c == NULL)
	{
		return (write(1, "(null)", 6));
	}
	while (c[i])
	{
		write(1, &c[i], 1);
		i++;
	}
	return (i);
}

int hexa(unsigned int c)
{
	int i = 0;
	if (c >= 16)
	{
		i += hexa(c /16);
		hexa(c % 16);
	}
	else if (c < 16 && c >= 10)
	{
		ft_putchar(c + 'a' - 10);
	}
	else if (c < 10)
	{
		ft_putchar(c + '0');
	}
	i++;
	return (i);
}

int decimal(int c)
{
	int i = 0;
	if (c == -2147483648)
		return (write(1, "-2147483648", 11));
	if (c < 0)
	{
		c = -c;
		write(1, "-", 1);
		i += 1;
	}
	if (c >= 10)
	{
		i += decimal(c / 10);
		decimal(c % 10);
	}
	else if (c < 10 && c >= 0)
	{
		ft_putchar(c + '0');
	}
	i++;
	return (i);
}

int ft_printf(const char *fkmat, ...)
{
	int i = 0;
	va_list a;
	int bytes = 0;
	va_start(a,fkmat);
	while (fkmat[i])
	{
		if (fkmat[i] == '%')
		{
			i++;
			if (fkmat[i] == 'd')
				bytes+= decimal(va_arg(a, int));
			else if (fkmat[i] == 's')
				bytes+= putstr(va_arg(a, char *));
			else if (fkmat[i] == 'x')
				bytes+= hexa(va_arg(a, unsigned int));
			i++;
		}
		else
		{
			write(1, &fkmat[i], 1);
			bytes += 1;
			i++;
		}
	}
	va_end(a);
	return (bytes);
}

// int main()
// {
// 	printf("Fakereturn value:%d\n", ft_printf("%d\t", -1));
// 	printf("realreturn value:%d\n" ,printf("%d\t", -1));
// 	return 0;
// }
