#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int ft_putchar(char c)
{
    write(1, &c, 1);
    return (1);
}

int ft_putstr(char *str)
{
    int i = 0;

    if (!str)
        str = "(null)";
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
    return (i);
}

int ft_putnbr(int num)
{
    int len = 0;

    if (num < 0)
    {
        len += write(1, "-", 1);
        num *= -1;
    }
    else if (num <= 9 && num >= 0)
        len += ft_putchar(num + '0');
    else if (num > 9)
    {
        len += ft_putnbr(num / 10);
        len += ft_putnbr(num % 10);
    }

    return (len);
}

int ft_printhex(unsigned int num)
{
    int len = 0;

    if (num >= 16)
    {
        len += ft_printhex(num / 16);
        len += ft_printhex(num % 16); 
    }
    else
    {
        if (num >= 10 && num < 16)
            len += ft_putchar(num - 10 + 'a');
        else
            len += ft_putchar(num + '0');
    }

    return (len);
}

int	ft_printf(const char *format, ... )
{
    int len = 0;
    int i = 0;
    va_list args;

    va_start(args,format);
    while(format[i])
    {
        if (format[i] != '%')
            len += ft_putchar(format[i]);
        if (format[i] == '%' && format[i + 1])
        {
            i++;
            if (format[i] == 's')
                len += ft_putstr(va_arg(args, char *));
            else if (format[i] == 'd')
                len += ft_putnbr(va_arg(args, int));
            else if (format[i] == 'x')
                len += ft_printhex(va_arg(args, unsigned int));
        }
        i++;
    }
    va_end(args);
    return (len);
}

#include <stdio.h>
int main()
{
    int len = 0;
	len = ft_printf("%x\n", 4253584);
    printf("%d\n", len);
    len = printf("%x\n", 4253584);
    printf("%d\n", len);
}
