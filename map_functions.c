#include "so_long.h"

void map_check(char *path, t_data *data)
{
    int fd;
    int i = 0;
    char *line;
    fd = open(path, O_RDONLY);
    if (fd < 0)
    {
        write(1, "map file does not exist", 24);
        exit(1);
    }
    line = get_next_line(fd);
    if (!line)
    {
        write(1, "map is empty", 13);
        close(fd);
        exit(1);
    }
    while (line)
    {
        i++;
        free(line);
        line = get_next_line(fd);
    }
    free(line);
    data->height = i;
    close(fd);
    // printf("%d\n",i);
    // printf("%d\n",data->height);
}
// int main (int ac, char * av[])
// {
//     t_data data;
//     data.height = 0;
//     map_check(av[1],&data);
// }
void map_width(char *path, t_data *data)
{
    int fd;
    char *line;
    size_t w = 0;

    fd = open(path, O_RDONLY);
    if (fd < 0)
    {
        write(1, "map file does not exist", 24);
        exit(1);
    }
    line = get_next_line(fd);
    w = ft_strlen2(line);
    while (line != NULL)
    {
        // printf("%s\n",line);
        if (w != ft_strlen2(line))
        {
            // printf("%s\n",line);
            write(1, "map width is not equal", 23);
            free(line);
            close(fd);
            exit(1);
        }
        free(line);
        line = get_next_line(fd);
    }
    free(line);
    data->width = w;
    close(fd);
    // printf("%d",w);
}
// int main(int argc, char *argv[])
// {
//     (void)argc;
//     t_data data;
//     map_width(argv[1],&data);
//     return 0;
// }
void map_arr(char *path, t_data *data)
{
    int fd;
    int i = 0;

    fd = open(path, O_RDONLY);
    if (fd < 0)
    {
        write(1, "map file does not exist", 24);
        close(fd);
        exit(1);
    }
    data->map = malloc((data->height + 1) * sizeof(char *));
    if (!data->map)
        return;
    while (i < data->height)
    {
        data->map[i] = get_next_line(fd);
        i++;
    }
    data->map[i] = NULL;
    close(fd);
    map_arr2(path,data);
}
void map_arr2(char *path, t_data *data)
{
        int fd;
    int i = 0;

    fd = open(path, O_RDONLY);
    if (fd < 0)
    {
        write(1, "map file does not exist", 24);
        close(fd);
        exit(1);
    }
    data->map2 = malloc((data->height + 1) * sizeof(char *));
    if (!data->map2)
        return;
    while (i < data->height)
    {
        // printf("%d\n",data->height);
        // printf("%d",i);
        data->map2[i] = get_next_line(fd);
       // printf("%s",data->map2[i]);
        i++;
    }
    data->map2[i] = NULL;
    close(fd);
}

void check_map_border(t_data *data)
{
    int i = 0;
    int j = 0;

    while (i < data->height)
    {
        j = 0;
        while (j < data->width)
        {
            if (data->map[0][j] != '1' || data->map[data->height - 1][j] != '1')
            {
                write(1, "map border is not correct", 26);
                exit(1);
            }
            if (data->map[i][0] != '1' || data->map[i][data->width - 1] != '1')
            {
                write(1, "map border is not correct", 26);
                exit(1);
            }
            j++;
        }

        i++;
    }

    // int	i;
    // int	j;

    // i = 0;
    // j = 0;
    // while (i < data->height)
    // {
    // 	j = 0;
    // 	while (j < data->width)
    // 	{
    // 		if ((data->map[0][j] != '1' || data->map[data->height - 1][j] != '1'))
    // 		{
    // 			write(1, "map border is not correct", 26);
    // 			exit(1);
    // 		}
    // 		if (data->map[i][0] != '1' || data->map[i][data->width - 1] != '1')
    // 		{
    // 			 write(1, "map border is not correct", 26);
    // 			exit(1);
    // 		}
    // 		j++;
    // 	}
    // 	i++;
    // }
}
void freefun(char **ptr)
{
    int i;

    i = 0;
    while (ptr[i])
    {
        free(ptr[i++]);
    }
    // printf("%d", r);
    free(ptr);
}
// int main(int argc, char *argv[])
// {
//     t_data data;
//     //data.width = 0;

//     (void)argc;
//     map_check(argv[1], &data);
//     map_width(argv[1], &data);
//     map_arr(argv[1], &data);
//     check_map_border(&data);
//     // printf("%d", data.height);
//     // printf("%d", data.width);
//     freefun(data.map);
//     return 0;
// }
