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

int droite(struct bin *bin)
{
    if (bin->event.type == sfEvtKeyPressed &&
    sfKeyboard_isKeyPressed(sfKeyRight)) {
        sfSprite_setRotation(bin->sunny, 0);
        bin->reverse.x = -1;
        sfSprite_setScale(bin->sunny, bin->reverse);
        if (bin->coo_x - 15 >= -3075) {
            bin->pos_ocean.x -= 20;
        } else {
            bin->border_bug = 1;
        }
    }
}

int gauche(struct bin *bin)
{
    if (bin->event.type == sfEvtKeyPressed &&
    sfKeyboard_isKeyPressed(sfKeyLeft)) {
        sfSprite_setRotation(bin->sunny, 0);
        bin->reverse.x = 1;
        sfSprite_setScale(bin->sunny, bin->reverse);
        if (bin->coo_x + 15 <= 0) {
            bin->pos_ocean.x += 20;
        } else {
            bin->border_bug = 1;
        }
    }
}

int haut(struct bin *bin)
{
    if (bin->event.type == sfEvtKeyPressed &&
    sfKeyboard_isKeyPressed(sfKeyUp)) {
        sfSprite_setRotation(bin->sunny, 90);
        bin->reverse.x = 1;
        sfSprite_setScale(bin->sunny, bin->reverse);
        if (bin->coo_y + 10 <= 0) {
            bin->pos_ocean.y += 20;
        } else {
            bin->border_bug = 1;
        }
    }
}

int bas(struct bin *bin)
{
    if (bin->event.type == sfEvtKeyPressed &&
    (sfKeyboard_isKeyPressed(sfKeyDown))) {
        sfSprite_setRotation(bin->sunny, 270);
        bin->reverse.x = 1;
        sfSprite_setScale(bin->sunny, bin->reverse);
        if (bin->coo_y - 10 >= -3970) {
            bin->pos_ocean.y -= 20;
        } else {
            bin->border_bug = 1;
        }
    }
}

int iles(struct bin *bin)
{
    if (bin->coo_x <= 0 && bin->coo_x >= -920 &&
    bin->coo_y <= -1420 && bin->coo_y >= -1940 && bin->nb_ile == 1) {
        bin->pos_ocean.x = -2000;
        bin->pos_ocean.y = -3900;
        sfSprite_setPosition(bin->ocean, bin->pos_ocean);
        ilealabasta(bin);
    }if (bin->coo_x <= -1580 && bin->coo_x >= -2520 &&
    bin->coo_y <= -2780 && bin->coo_y >= -3220 && bin->nb_ile == 2) {
        bin->pos_ocean.x = -2000;
        bin->pos_ocean.y = -3900;
        sfSprite_setPosition(bin->ocean, bin->pos_ocean);
        ileskypea(bin);
    }if (bin->coo_x <= -2540 && bin->coo_x >= -3080 &&
    bin->coo_y <= -1020 && bin->coo_y >= -1680 && bin->nb_ile == 3) {
        bin->pos_ocean.x = -2000;
        bin->pos_ocean.y = -3900;
        sfSprite_setPosition(bin->ocean, bin->pos_ocean);
        ilemarine(bin);
    }
}
