#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

int	ft_strlen(char *str)
{
	int	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_putstr(char *str)
{
	if (!str)
		return (0);
	write(1, str, ft_strlen(str));
	return (ft_strlen(str));
}

int	ft_putchar(int c)
{
	if (c == 58)
		write(1, "a", sizeof(char));
	else
		write(1, &c, sizeof(char));
	return (1);
}

int ft_putnbr(long long n, int base)
{
	int	i = 0;
	if (n < 0 && base == 10)
	{
		n *= -1;
		i += write(1, "-", sizeof(char));
	}
	if (n >= base)
	{
		i += ft_putnbr(n / base, base);
	}
	i += ft_putchar((n % base)+ '0');
	return (i);
}

int	eval_form(char *str, va_list valist)
{
	int	i = 0;
	if (*str == 's')
		return (i += ft_putstr(va_arg(valist, char *)));
	else if (*str == 'd')
		return (i += ft_putnbr(va_arg(valist, int), 10));
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
			i += eval_form((char *)str, valist);
		}
		else if (*str != '%')
			i += write(1, str, 1);
		if (str)
			str++;
	}
	va_end(valist);
	return (i);
}

int	main(void)
{
	char str[] = "abc%dabc";

	printf("%d|\n", ft_printf(str, 2324));
	printf("%d|\n", printf(str, 2324));
	return (0);
}
