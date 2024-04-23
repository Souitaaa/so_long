#include "so_long.h"

size_t ft_count_digits(int number)
{
    int i;
    i = 0;
    while (number)
    {
        number /= 10;
        i++;
    }
    return i;
}

char *ft_itoa(int number)
{
    size_t len;
    char *str;
    long int n;

    n = number;
    len = ft_count_digits(n);
    if (n < 0)
    {
        number *= -1;
        len++;
    }
    str = malloc(sizeof(char) * (len + 1));
    if (!str)
        return NULL;
    *(str + len) = '\0';
    while (len--)
    {
        *(str + len) = (number % 10) + 48;
        number /= 10;
    }
    if (n < 0)
        *(str) = '-';
    return str;
}
// int main(int argc, char const *argv[])
// {
//     printf("%s",ft_itoa(762));
//     return 0;
// }