#include "so_long.h"

void check_path(char *path)
{
    char *str ;
    int res ;
    
    str = ft_strrchr(path,'.');
    if (str == NULL)
    {
        write(1,"no .ber file",13);
        exit(1);
    }
    res = ft_strncmp(".ber",str,4);
    if (res != 0)
    {
        write(1,"no .ber file",13);
        exit(1);
    }
}



// void	path_check(char *path)
// {
// 	char	*extention;

// 	extention = ft_strrchr(path, '.');
// 	if (extention == NULL)
// 	{
// 		write(1,"do not have extention",22);
// 		exit(1);
// 	}
// 	if (strcmp(extention, ".ber") != 0)
// 	{
// 		write(1,"extention False",16);
// 		exit(1);
// 	}
// }
