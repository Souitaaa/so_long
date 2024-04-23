#include "so_long.h"
int r;
void check_path(char *path)
{
    // int res;
    char *str;

    str = ft_strrchr(path, '.');
    // printf("%s\n",str);
    if (str == NULL)
    {
        write(1, "no .ber file", 13);
        exit(1);
    }
        // res = ;
        // printf("%d",res);
    if (ft_strcmp(".ber", str) != 0)
    {
        write(1, "no .ber file", 13);
        exit(1);
    }
}
void player_position(t_data *data)
{
    int i = 0;
    int j = 0;

    while (i < data->height)
    {
        j = 0;
        while (j < data->width)
        {
            if (data->map[i][j] != 'P')
                j++;
            else if (data->map[i][j] == 'P')
            {
                data->player_height = i;
                data->player_width = j;
                return;
            }
        }
        i++;
    }
    // printf("%d\n",data->player_height);
    // printf("%d",data->player_width);
}  
void check_file(t_data *xcheck)
{
    if (xcheck == NULL)
    {
        write(1,".xpm doesn't exist",19);
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

int main(int ac, char *av[])
{
    (void)ac;
    t_data data;
    data.height = 0;
    map_check(av[1], &data);
    map_width(av[1], &data);
    check_path(av[1]);
    map_arr(av[1],&data);
    check_map_border(&data);
    store_content(&data);
    check_exist_items(&data);
    player_position(&data);
    // printf("%d",data.height);
}
