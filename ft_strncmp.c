#include "so_long.h"

int ft_strcmp(char *s1, char *s2)
{
	size_t i;
	unsigned char *us1;
	unsigned char *us2;

	i = 0;
	us1 = (unsigned char *)(s1);
	us2 = (unsigned char *)(s2);
	while ((us1[i] || us2[i]))
	{
		if (us1[i] != us2[i])
		{
			return (us1[i] - us2[i]);
		}
		i++;
	}
	return (0);
}
// int main ()
// {
//     printf("%c",ft_strncmp("souita0","sou",7));
// }