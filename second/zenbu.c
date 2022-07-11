/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zenbu.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduong <qduong@students.42wolfsburg.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:50:34 by qduong            #+#    #+#             */
/*   Updated: 2022/05/24 13:22:05 by qduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

int	ex_itoa(int n);

void	ex_putchr(int c)
{
	write(1, &c, 1);
}

int	write_double(int d)
{
	int		n;

	n = 0;
	n = ex_itoa(d);
	return (n);
}

int	ex_itoa(int n)
{
	int	i;

	i = 0;
	if (n == INT_MIN)
	{
		return (write(1, "-2147483648", 11));
	}
	if (n < 0)
	{
		n = -n;
		i += write(1, "-", 1);
	}
	if (n > 9)
	{
		i += ex_itoa((n / 10));
		ex_itoa((n % 10));
	}
	else if (n < 10)
	{
		ex_putchr('0' + n);
	}
	i++;
	return (i);
}

int	write_string(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	convert_hexa_lowercase(unsigned long n)
{
	int	i;

	i = 0;
	if (n >= 16)
	{
		i = convert_hexa_lowercase((n / 16));
		convert_hexa_lowercase((n % 16));
	}
	if (n <= 9)
	{
		ex_putchr(('0' + n));
	}
	if (n >= 10 && n < 16)
	{
		ex_putchr(('a' - 10 + n));
	}
	i++;
	return (i);
}

int	ag_printf(const char *format, ...)
{
	int			is_variable;
	int			bytes_written;
	va_list		args;

	va_start (args, format);
	is_variable = 0;
	bytes_written = 0;
	int i = 0;
	while (format[i])
	{
		if (is_variable)
		{
		if (format[i] == 's')
			bytes_written += (write_string(va_arg(args, char *)));
		if (format[i] == 'd')
			bytes_written += (write_double(va_arg(args, int)));
		if (format[i] == 'x')
			bytes_written += (convert_hexa_lowercase(va_arg(args, unsigned int)));
		if (format[i] == '%')
		{
			write(1, "\%", 1);
			bytes_written += 1;
		}
			is_variable = 0;
		}
		else if (format[i] != '%')
		{
			write(1, &format[i], 1);
			bytes_written++;
		}
		else
			is_variable = 1;
		i++;
	}
	va_end (args);
	return (bytes_written);
}

int main()
{
	printf("my return:%d\n", ag_printf("%x%s%d%%\n", 812345678, "hello", -2147483649));
	printf("return value:%d\n",printf("%x%s%d%%\n", 812345678, "hello", -2147483649));
	return 0;
}
