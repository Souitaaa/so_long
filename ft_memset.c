#include "so_long.h"

void *ft_memset(void *b, int c, size_t len)
{
	size_t i;
	char *str;

	i = 0;
	str = (char *)b;
	while (i < len)
	{
		str[i] = c;
		i++;
	}
	return (b);
}