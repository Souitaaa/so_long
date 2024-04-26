#include "so_long.c"
#include <X11/keysym.h>
int keycode_print(int keycode ,t_data *data)
 {
    (void)data;
    printf("%d\n",keycode);
    return 0 ;
 }