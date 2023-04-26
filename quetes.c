/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** rpg
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "my.h"

void quetes(struct bin *bin, sfRenderWindow *Window)
{
    if (bin->quete == 1) {
        sfRenderWindow_drawSprite(Window, bin->Quete1, NULL);
    }
    if (bin->quete == 2) {
        sfRenderWindow_drawSprite(Window, bin->Quete2, NULL);
    }
    if (bin->quete == 3) {
        sfRenderWindow_drawSprite(Window, bin->Quete3, NULL);
    }
    if (bin->quete == 4) {
        sfRenderWindow_drawSprite(Window, bin->Quete4, NULL);
    }
    if (bin->quete == 5) {
        sfRenderWindow_drawSprite(Window, bin->Quete5, NULL);
    }
    if (bin->quete == 6) {
        sfRenderWindow_drawSprite(Window, bin->Quete6, NULL);
    }
}
