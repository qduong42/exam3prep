#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <limits.h>

void	ft_putchar(int c);


int putstr(char *c);


int hexa(unsigned int c);


int decimal(int c);

int ft_printf(const char *fkmat, ...);


#endif