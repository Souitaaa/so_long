#include "so_long.h"

void map_check(char *path, t_data *data)
{
    int fd;
    int i;
    char *line;

    i = 0;
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
    // free(line);
    data->height = i;
    close(fd);
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
    size_t w;
    size_t i;
    i = 0;

    w = 0;
    fd = open(path, O_RDONLY);
    if (fd < 0)
    {
        write(1, "map file does not exist", 24);
        exit(1);
    }
    line = get_next_line(fd);
    w = ft_strlen2(line);
    free(line);
    while (line != NULL)
    {
        if (w != ft_strlen2(line))
        {
            write(1, "map width is not equal", 23);
            free(line);
            exit(1);
        }
        free(line);
        line = get_next_line(fd);
    }
    data->width = w;
    close(fd);
}

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
    map_arr2(path, data);
}
void map_arr2(char *path, t_data *data)
{
    int fd;
    int i;

    i = 0;
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
        data->map2[i] = get_next_line(fd);
        i++;
    }
    data->map2[i] = NULL;
    close(fd);
}

void check_map_border(t_data *data)
{
    int i;
    int j;

    i = 0;

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
}
void freefun(char **ptr)
{
    int i;

    i = 0;
    while (ptr[i])
    {
        free(ptr[i++]);
    }
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
