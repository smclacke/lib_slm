/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/04 15:47:32 by smclacke      #+#    #+#                 */
/*   Updated: 2023/03/04 15:47:35 by smclacke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int	ft_strlen(char *s)
{
	int  i = 0;
	while (s[i])
		i++;
	return (i);
}

int	print_string(char *str)
{
	if (!str)
		return(0);
	write(1, str, ft_strlen(str));
	return (ft_strlen(str));
}

int	ft_putchar(int c)
{
	if (c == 58)
		write(1, "a", sizeof(char));
	else if (c == 59)
		write(1, "b", sizeof(char));
	else if (c == 60)
		write(1, "c", sizeof(char));
	else if (c == 61)
		write(1, "d", sizeof(char));
	else if (c == 62)
		write(1, "e", sizeof(char));
	else if (c == 63)
		write(1, "f", sizeof(char));
	else
		write(1, &c, sizeof(char));
	return (1);
}

int	print_nbr(long long n, int base)
{
	int i = 0;
	if (n < 0 && base == 10)
	{
		n *= -1;
		i+= write (1, "-", sizeof(char));
	}
	if (n >= base)
		i += print_nbr(n / base, base);
	i += ft_putchar((n % base) + '0');
	return (i);
}

int	ft_eval_format(char *str, va_list valist)
{
	int i = 0;
	if (*str == 's')
		return (i += print_string(va_arg(valist, char *)));
	else if (*str == 'd')
		return (i += print_nbr(va_arg(valist, int), 10));
	else if (*str == 'x')
		return (i += print_nbr(va_arg(valist, unsigned int), 16));
	return (i);
}

int	ft_printf(const char *str, ...)
{
	int	i = 0;
	va_list valist;

	va_start(valist, (char *)str);
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == '%' && *(str + 1))
		{
			str++;
			i += ft_eval_format((char *)str, valist);
		}
		else if (*str != '%')
		{
			i += write(1, str, 1);
		}
		if (str)
			str++;
	}
	va_end(valist);
	return (i);
}

int main(void)
{
	char str[] = "abc%xabc";
	printf("|%d\n", ft_printf(str, 94578));
	printf("|%d\n", printf(str, 94875));
	return 0;
}
