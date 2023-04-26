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
#include "../my.h"

int saut_perso_boss(struct bin *bin)
{
    if ((sfKeyboard_isKeyPressed(sfKeySpace) || bin->jump == 1) &&
    bin->jump != 2) {
        bin->deplacements.y -= 10;
        bin->jump = 1;
        if (bin->deplacements.y < 190) {
            bin->jump = 0;
        }
    }
    if (bin->deplacements.y <= 200 || bin->jump == 2) {
        bin->jump = 2;
        bin->deplacements.y += 10;
        if (bin->deplacements.y >= 500) {
            bin->jump = 0;
            bin->deplacements.y = 500;
        }
    }
}

void moove_right_boss(struct bin *bin)
{
    bin->deplacements.x += 10;
}

void set_hud(struct bin *bin)
{
    if (bin->pick == 1) {
        sfSprite_setPosition(bin->HUD_LUFFY, (sfVector2f) {0, -50});
        sfRenderWindow_drawSprite(bin->Boss, bin->HUD_LUFFY, NULL);
    }
    if (bin->pick == 2) {
        sfSprite_setPosition(bin->HUD_ZORO, (sfVector2f) {0, -50});
        sfRenderWindow_drawSprite(bin->Boss, bin->HUD_ZORO, NULL);
    }
    if (bin->pick == 3) {
        sfSprite_setPosition(bin->HUD_SANJI, (sfVector2f) {0, -50});
        sfRenderWindow_drawSprite(bin->Boss, bin->HUD_SANJI, NULL);
    }
}
