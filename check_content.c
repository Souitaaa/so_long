#include "so_long.h"

void check_exist_items(t_data *data)
{
    int i = 0 ;
    int j = 0 ;
    
    while (i < data->height)
    {
        j = 0 ;
        while (j > data->width)
        {
            if (data->map[i][j] != 'P' || data->map != 'C' || data->map != 'E')
            {
                write(1,"error in items , double check them please !",44);
                exit(1);
            }
            j++;
        }
        i++;
    }
    store_content(data);
}
void store_content(t_data *data)
{
    int i = 0 ;
    int j = 0 ;
    while(i < data->height)
    {
        j = 0 ;
        while (j < data->width)
        {
            if (data->map[i][j] == 'E')
                data->exit1++;
            else if (data->map[i][j] == 'P')
                data->player++;
            else if (data->map[i][j] == 'C')
                data->collectables++;
        }
        i++;
    }
    if (data->player != '1' || data->collectables < 1 || data->exit1 != 1)
    {
        write(1,"map is not valid",17);
        exit(1);
    }
}
