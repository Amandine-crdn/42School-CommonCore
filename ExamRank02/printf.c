#include <stdarg.h>
#include <unistd.h>
#include <limits.h>


typedef struct s_sc
{
    int len;
    int widht;
}   t_sc;


void    ft_putchar(char c)
{
    write(1, &c, 1);
}



int ft_intlen(int nb, int base)
{
    int i = 0;
    int number;
    int neg;

    if (!nb)
        return (1);
    if (nb < 0)
    {
        neg = 1;
        number = -nb;
    }
    else
    {
        neg = 0;
        number = nb;
    }
    while (number)
    {
        number /= base;
        i++;
    }
    return (i + neg);
}

int ft_intlenhex(unsigned nb, int base)
{
    int i = 0;

    if (!nb)
        return (1);
    while (nb)
    {
        nb /= base;
        i++;
    }
    return (i);
}

void    ft_putstr(char *str)
{
    int i = 0;
    while (str[i])
    {
        ft_putchar(str[i]);
        i++;
    }
}

int ft_strlen(const char *s)
{
    int i = 0;
    while (s[i])
        i++;
    return (i);
}

void    ft_putnbr(int nb)
{
    if (nb == INT_MIN)
    {
        write(1, "-2147483648", 11);
        return ;
    } 
    if (nb >= 0 && nb <= 9)
        ft_putchar(nb + 48);
    else if (nb < 0)
    {
        ft_putchar('-');
        ft_putnbr(-nb);
    }
    else
    {
        ft_putnbr(nb / 10);
        ft_putnbr(nb % 10);
    }
}

void    ft_printhexa(unsigned long x)
{
    char *hexa = "0123456789abcdef";
    int res[100];
    int i = 0;

    while (x >= 16)
    {
        res[i] = hexa[x % 16];
        x = x / 16;
        i++;
    } 
    res[i] = hexa[x];
    while (i >= 0)
    {
        ft_putchar(res[i]);
        i--;
    }
}

const char *ft_search_arg(va_list arg, const char *format, t_sc *sc)
{
    if (*format == 'd')
    {
        int d = va_arg(arg, int);
        ft_putnbr(d);
        sc->len += ft_intlen(d, 10);
    }
    else if (*format == 's')
    {
        char *str = va_arg(arg, char *);
        if (!str)
        {
            write(1, "(null)", 6);
            sc->len += 6;   
        }
        else
        {
            ft_putstr(str);
            sc->len += ft_strlen(str);
        }
    }
    else if (*format == 'x')
    {
        unsigned int x = va_arg(arg, unsigned int);
        ft_printhexa((unsigned long)x);
        sc->len += ft_intlenhex((unsigned long)x, 16);
    }
    else
        return (NULL);
    format++;
    return (format);
}

char *ft_strchr(const char *s)
{
    while (*s)
    {
        if (*s == '%')
            return((char *)s);
        s++;
    }
    if (!s)
        return ((char *)s);
    return (NULL);
}

const char *ft_read_text(t_sc *sc, const char *format)
{
    char *next;

    next = ft_strchr(format);
    if (next)
        sc->widht = next - format; 
    else
        sc->widht = ft_strlen(format);
    write(1, format, sc->widht);
    sc->len += sc->widht;
    while (*format && *format != '%')
        ++format; 
    return (format);
}

int ft_printf(const char *format, ...)
{
    va_list arg;
    va_start(arg, format);
    t_sc sc;
    sc.len = 0;
    sc.widht = 0;

    while (*format)
    {
        if (*format == '%')
            format = ft_search_arg(arg, format + 1, &sc);
        else
            format = ft_read_text(&sc, format);
        if (!format)
        {
            write(1, "(null)", 6);
            va_end(arg);
            return (sc.len);
        }
    }
    va_end(arg);
    return ((int)sc.len);
}

#include <stdio.h>

int main()
{
    int res = ft_printf("coucou %x g\n", INT_MIN); 
    int res2 = printf("coucou %x g\n", INT_MIN);

    printf("res = %d\nres2 = %d\n", res, res2);
    return (0);
}