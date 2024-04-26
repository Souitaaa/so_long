#include "so_long.h"
#include <string.h>

char *ft_strrchr(const char *s, int c)
{
	int i;
	char *str;

	str = (char *)s;
	i = 0;
	while (str[i])
		i++;
	if (str[i] == c)
		return (str + i);
	while (str[i] != c && i > 0)
		i--;
	if (str[i] == str[0] && str[i] != c)
		return (NULL);
	return (str + i);
}
// int main()
// {
// 	char *result ;
// 	char *result2 ;
// 	result = ft_strrchr("souita",'i');
// 	result2 = strrchr("souita",'i');
// 	printf("%s",result) ;
// 	printf("%s-",result2) ;

// 	return (0);
// }
