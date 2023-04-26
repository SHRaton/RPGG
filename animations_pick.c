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

void cinematique_pick2(struct bin *bin)
{
    sfSprite_setPosition(bin->pick_champ, (sfVector2f) {269, 0});
    sfSprite_setTextureRect(bin->pick_champ, bin->frameRect);
    bin->elapsed += sfTime_asSeconds(sfClock_restart(bin->clock));
    if (bin->elapsed > bin->frameDuration) {
        bin->elapsed -= bin->frameDuration;
        bin->frameRect.left += 256;
        if (bin->frameRect.left >= bin->textureWidth) {
            bin->frameRect.left = 0;
            sfRenderWindow_close(bin->Start);
        }
        sfSprite_setTextureRect(bin->pick_champ, bin->frameRect);
    }
    sfRenderWindow_clear(bin->Start, sfBlack);
    sfRenderWindow_drawSprite(bin->Start, bin->pick_champ, NULL);
}

void cinematique_pick(struct bin *bin, int *k)
{
    if (*k == 0)
        sfClock_restart(bin->clock);
    if (bin->mouse.x >= 0 && bin->mouse.x <= 640 &&
    bin->mouse.y >= 0 && bin->mouse.y <= 1080 && *k == 0) {
        *k = 1; bin->pick = 1;
        bin->pick_champ = bin->pick_luffy;
        sfSprite_setScale(bin->pick_champ, (sfVector2f) {5.4, 5.4});
    }if (bin->mouse.x >= 640 && bin->mouse.x <= 1280 &&
    bin->mouse.y >= 0 && bin->mouse.y <= 1080 && *k == 0) {
        *k = 2; bin->pick = 2;
        bin->pick_champ = bin->pick_zoro;
        sfSprite_setScale(bin->pick_champ, (sfVector2f) {6, 6});
    }if (bin->mouse.x >= 1280 && bin->mouse.x <= 1920 &&
    bin->mouse.y >= 0 && bin->mouse.y <= 1080 && *k == 0) {
        *k = 3; bin->pick = 3;
        bin->pick_champ = bin->pick_sanji;
        sfSprite_setScale(bin->pick_champ, (sfVector2f) {5.4, 5.4});
    }
    cinematique_pick2(bin);
}

int animation_pick(struct bin *bin, int *k)
{
    sfRenderWindow_drawSprite(bin->Start, bin->choose, NULL);
    if (bin->mouse.x >= 0 && bin->mouse.x <= 640 &&
        bin->mouse.y >= 0 && bin->mouse.y <= 1080) {
        sfRenderWindow_drawSprite(bin->Start, bin->HOVER_LUFFY, NULL);
    }
    if (bin->mouse.x >= 640 && bin->mouse.x <= 1280 &&
        bin->mouse.y >= 0 && bin->mouse.y <= 1080) {
        sfRenderWindow_drawSprite(bin->Start, bin->HOVER_ZORO, NULL);
    }
    if (bin->mouse.x >= 1280 && bin->mouse.x <= 1920 &&
        bin->mouse.y >= 0 && bin->mouse.y <= 1080) {
        sfRenderWindow_drawSprite(bin->Start, bin->HOVER_SANJI, NULL);
    }
    if ((bin->event.type == sfEvtMouseButtonPressed &&
    bin->event.mouseButton.button == sfMouseLeft) || *k >= 1) {
        cinematique_pick(bin, k);
    }
}
