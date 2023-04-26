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

void hud(struct bin bin, sfRenderWindow *Window)
{
    if (bin.pick == 1) {
        sfSprite_setPosition(bin.HUD_LUFFY, (sfVector2f) {0, -50});
        sfRenderWindow_drawSprite(Window, bin.HUD_LUFFY, NULL);
    }
    if (bin.pick == 2) {
        sfSprite_setPosition(bin.HUD_ZORO, (sfVector2f) {0, -50});
        sfRenderWindow_drawSprite(Window, bin.HUD_ZORO, NULL);
    }
    if (bin.pick == 3) {
        sfSprite_setPosition(bin.HUD_SANJI, (sfVector2f) {0, -50});
        sfRenderWindow_drawSprite(Window, bin.HUD_SANJI, NULL);
    }
}
