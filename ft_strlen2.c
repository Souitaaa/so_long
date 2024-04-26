#include "so_long.h"

size_t ft_strlen2(char *str)
{
    size_t i = 0;
    while (str[i] != '\0' && str[i] != '\n')
        i++;
    return i;
}