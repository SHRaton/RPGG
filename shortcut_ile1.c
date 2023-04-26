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

void no_moove(struct bin *bin)
{
    if (bin->event.type != sfEvtKeyPressed) {
    if (bin->pick == 1) {
        bin->luffy = bin->luffyz_c;
        sfSprite_setScale(bin->luffy, (sfVector2f){4, 4});
        sfSprite_setPosition(bin->luffy, (sfVector2f) {900, 500});
    }
    if (bin->pick == 2) {
        bin->luffy = bin->zoroz_c;
        sfSprite_setScale(bin->luffy, (sfVector2f){4, 4});
        sfSprite_setPosition(bin->luffy, (sfVector2f) {900, 470});
    }
    if (bin->pick == 3) {
        bin->luffy = bin->sanjiz_c;
        sfSprite_setScale(bin->luffy, (sfVector2f){4, 4});
        sfSprite_setPosition(bin->luffy, (sfVector2f) {900, 470});
    }
    }
}

void no_moovealabasta(struct bin *bin)
{
    if (bin->event.type != sfEvtKeyPressed) {
    if (bin->pick == 1) {
        bin->luffy = bin->luffyfy;
        sfSprite_setScale(bin->luffy, (sfVector2f){3.5, 3.5});
        sfSprite_setPosition(bin->luffy, (sfVector2f) {900, 500});
    }
    if (bin->pick == 2) {
        bin->luffy = bin->zororo;
        sfSprite_setScale(bin->luffy, (sfVector2f){4, 4});
        sfSprite_setPosition(bin->luffy, (sfVector2f) {900, 470});
    }
    if (bin->pick == 3) {
        bin->luffy = bin->sanjiji;
        sfSprite_setScale(bin->luffy, (sfVector2f){4, 4});
        sfSprite_setPosition(bin->luffy, (sfVector2f) {900, 470});
    }
    }
}

void draw_all(struct bin *bin)
{
    sfSprite_setPosition(bin->map_ile, bin->deplacements_ile);
    sfSprite_setPosition(bin->chopper, bin->deplacement_chopper);
    sfSprite_setPosition(bin->map_dessous, bin->deplacements_ile);
    sfSprite_setPosition(bin->press_f, bin->deplacements_ile);
    sfSprite_setPosition(bin->choopper_f, bin->deplacements_ile);
    sfRenderWindow_drawSprite(bin->island, bin->map_ile, NULL);
    sfSprite_setTextureRect(bin->chopper, bin->rect_chopper);
    sfSprite_setScale(bin->chopper, (sfVector2f){0.6, 0.6});
    sfRenderWindow_drawSprite(bin->island, bin->chopper, NULL);
    if (bin->pick == 1) {
        sfRenderWindow_drawSprite(bin->island, bin->luffy, NULL);
    }if (bin->pick == 2) {
        sfSprite_setScale(bin->luffy, (sfVector2f){4, 4});
        sfRenderWindow_drawSprite(bin->island, bin->luffy, NULL);
    }if (bin->pick == 3) {
        sfSprite_setScale(bin->luffy, (sfVector2f){4, 4});
        sfRenderWindow_drawSprite(bin->island, bin->luffy, NULL);
    }
    sfRenderWindow_drawSprite(bin->island, bin->map_dessous, NULL);
}

void clock_chopper(struct bin *bin, sfClock *clock_d)
{
    if (sfTime_asSeconds(sfClock_getElapsedTime(clock_d)) > 0.5) {
    if (bin->rect_chopper.left <= 3600) {
        bin->rect_chopper.left += 450;
    }
    if (bin->rect_chopper.left > 3550) {
        bin->rect_chopper.left = 0;
    }
    sfClock_restart(clock_d);
    }
}

void draw_other(struct bin *bin)
{
    if (bin->f == 1) {
        sfRenderWindow_drawSprite(bin->island, bin->press_f, NULL);
    }
    if (bin->chop == 2) {
        bin->chopper = bin->choopper_vide_c;
    } else if (bin->chopper_f == 1) {
        bin->chopper = bin->choopper_f_c;
    } else {
        bin->chopper = bin->choopper_c;
    }
    sfSprite_setTextureRect(bin->vie, bin->rect_vie);
    sfSprite_setTextureRect(bin->mana, bin->rect_mana);
    sfRenderWindow_drawSprite(bin->island, bin->vie, NULL);
    sfRenderWindow_drawSprite(bin->island, bin->mana, NULL);
}
