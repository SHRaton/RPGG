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

void auto_crocoskypea(struct bin *bin)
{
    if (bin->pos_crocodile.x <= bin->deplacements.x + 100 &&
    bin->pos_crocodile.x >= bin->deplacements.x - 500 &&
    bin->direction_attack == 1 ||
    (bin->attack == 1 && bin->direction_attack == 1)) {
        bin->crocodile = bin->wukong_auto_droite_c; bin->attack = 1;
        sfSprite_setScale(bin->crocodile, (sfVector2f) {5, 5});
        bin->pos_crocodile.y = 50; bin->in_range = 1;
        sfSprite_setTextureRect(bin->crocodile, bin->rect_auto_croco);
    } else if (bin->pos_crocodile.x <= bin->deplacements.x + 100 &&
    bin->pos_crocodile.x >= bin->deplacements.x - 500 &&
    bin->direction_attack == 0 ||
    (bin->attack == 1 && bin->direction_attack == 0)) {
        bin->in_range = 1; bin->crocodile = bin->wukong_auto_gauche_c;
        sfSprite_setScale(bin->crocodile, (sfVector2f) {5, 5});
        bin->pos_crocodile.y = 50; bin->decale = 1; bin->attack = 1;
        sfSprite_setTextureRect(bin->crocodile, bin->rect_auto_croco);
    } else {
        bin->decale = 0; bin->pos_crocodile.y = 270;
        bin->rect_auto_croco.left = 0; bin->in_range = 0;
    }
}

void lance_boule2(struct bin *bin)
{
    if (bin->pos_boule.y >= 900) {
        bin->pos_boule.y = 0;
    }
    if (bin->pos_boule2.y >= 1080) {
        bin->pos_boule2.y = 0;
    }
    if (bin->pos_boule.x <= 0) {
        srand(time(NULL));
        bin->pos_boule.y = (rand() % 501) + 200;
        bin->pos_boule.x = 1300;
        bin->rect_boule.left = 0;
    }
    if (bin->pos_boule2.x <= 0) {
        srand(time(NULL));
        bin->pos_boule2.y = 0;
        bin->pos_boule2.x = (rand() % 1000) + 200;
        bin->rect_boule2.left = 0;
    }
}

void clock_anim_boule(struct bin *bin)
{
    if (sfTime_asSeconds(sfClock_getElapsedTime(bin->clock_boule)) > 0.4) {
        bin->rect_boule.left += 55;
        if (bin->rect_boule.left >= 450) {
            bin->rect_boule.left = 0;
        }
        bin->rect_boule2.left += 55;
        if (bin->rect_boule2.left >= 450) {
            bin->rect_boule2.left = 0;
        }
        sfClock_restart(bin->clock_boule);
    }
}

void lance_boule(struct bin *bin)
{
    if ((bin->pos_boule.x > bin->deplacements.x - 100 &&
    bin->pos_boule.x < bin->deplacements.x + 100 &&
    bin->pos_boule.y > bin->deplacements.y - 100 &&
    bin->pos_boule.y < bin->deplacements.y + 120) ||
    (bin->pos_boule2.x > bin->deplacements.x - 100 &&
    bin->pos_boule2.x < bin->deplacements.x + 100 &&
    bin->pos_boule2.y > bin->deplacements.y - 70 &&
    bin->pos_boule2.y < bin->deplacements.y + 70)) {
        bin->rect_vie.width -= 40;
        bin->nb_attack = 0;
        bin->pos_boule.x = 1300;
        bin->pos_boule2.y = 0;
    }
    bin->pos_crocodile.x = 1500; bin->pos_crocodile.y = 320;
    bin->pos_boule.x -= 10; bin->pos_boule.y -= 2;
    bin->pos_boule2.y += 10;
    lance_boule2(bin);
    clock_anim_boule(bin);
}

void clock_deplacements_crocoskypea(struct bin *bin)
{
    if (sfTime_asSeconds(sfClock_getElapsedTime(bin->moove_crocodile)) > 0.01) {
        droite_gauche_crocoskypea(bin);
        if (bin->pos_crocodile.x <= bin->deplacements.x + 300 &&
        bin->pos_crocodile.x >= bin->deplacements.x - 800) {
            bin->touche = 1;
        } else {
            bin->touche = 0;
        }if (bin->nb_attack >= 2 && bin->mort == 0) {
            lance_boule(bin);
        } else {
            auto_crocoskypea(bin);
        }if (bin->rect_vie_crocodile.width <= 0) {
            bin->rect_vie_crocodile.width = 0;
            bin->mort = 1; bin->pos_crocodile.y = 700;
            bin->crocodile = bin->wukong_mort_c;
            sfSprite_setScale(bin->crocodile, (sfVector2f) {6, 6});
        }if (bin->rect_vie.width <= 0) {
            game_over_enel(bin);
        }sfClock_restart(bin->moove_crocodile);
    }
}
