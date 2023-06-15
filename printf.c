#include <unistd.h>
#include <stdarg.h>

void	ft_putstr(char *str, int *len)
{
	if (!str)
		str = "(null)";
	while (*str)
		*len += write(1, str++, 1);
}

void	ft_putnum(long long int num, int base, int *len)
{
	char	*hexadecimal = "0123456789abcdef";

	if (num < 0)
	{
		num *= -1;
		*len += write(1, "-", 1);
	}
	if (num >= base)
		ft_putnum((num / base), base, len);
	else
		*len += write(1, &hexadecimal[num % base], 1);
}

int	ft_printf(const char *format, ...)
{
	int len = 0;

	va_list	args;
	va_start(args, format);

	while (*format)
	{
		if ((*format == '%') && ((*(format + 1) == 's') || (*(format + 1) == 'd') || (*(format + 1) == 'x')))
		{
			format++;
			if (*format == 's')
				ft_putstr(va_arg(args, char *), &len);
			else if (*format == 'd')
				ft_putnum((long long int)va_arg(args, int), 10, &len);
			else if (*format == 'x')
				ft_putnum((long long int)va_arg(args, unsigned int), 16, &len);
		}
		else
			length += write(1, format, 1);
		format++;
	}
	va_end(args);
	return (len);
}
