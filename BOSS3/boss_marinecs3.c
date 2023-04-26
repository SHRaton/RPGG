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

void auto_crocomarine(struct bin *bin)
{
    if (bin->pos_crocodile.x <= bin->deplacements.x + 100 &&
    bin->pos_crocodile.x >= bin->deplacements.x - 500 &&
    bin->direction_attack == 1 ||
    (bin->attack == 1 && bin->direction_attack == 1)) {
        bin->crocodile = bin->akainu_auto_droite_c; bin->attack = 1;
        sfSprite_setScale(bin->crocodile, (sfVector2f) {5, 5});
        bin->pos_crocodile.y = 50; bin->in_range = 1;
        sfSprite_setTextureRect(bin->crocodile, bin->rect_auto_croco);
    } else if (bin->pos_crocodile.x <= bin->deplacements.x + 100 &&
    bin->pos_crocodile.x >= bin->deplacements.x - 500 &&
    bin->direction_attack == 0 ||
    (bin->attack == 1 && bin->direction_attack == 0)) {
        bin->in_range = 1; bin->crocodile = bin->akainu_auto_gauche_c;
        sfSprite_setScale(bin->crocodile, (sfVector2f) {5, 5});
        bin->pos_crocodile.y = 50; bin->decale = 1; bin->attack = 1;
        sfSprite_setTextureRect(bin->crocodile, bin->rect_auto_croco);
    } else {
        bin->decale = 0; bin->pos_crocodile.y = 270;
        bin->rect_auto_croco.left = 0; bin->in_range = 0;
    }
}

void lance_boulemarine2(struct bin *bin)
{
    bin->pos_boule.y = 400;
    bin->pos_boule2.y = -80;
}

void clock_anim_boulemarine(struct bin *bin)
{
    if ((bin->pos_feu.x + 350 < bin->deplacements.x &&
    bin->pos_feu.x + 500 > bin->deplacements.x &&
    bin->deplacements.y > 450)) {
        bin->rect_flamme.left = 0;
        bin->rect_vie.width -= 40;
        if (bin->rect_vie_crocodile.width < 437) {
            bin->rect_vie_crocodile.width += 20;
        }
        bin->nb_attack = 0;
        bin->rect_sol.left = 0;
        bin->lance_feu = 0;
        bin->pos_feu.x = 700;
    }
    if (sfTime_asSeconds(sfClock_getElapsedTime(bin->clock_boule)) > 0.15) {
        bin->rect_flamme.left += 75;
        if (bin->rect_flamme.left >= 375 && bin->rect_flamme.left <= 1000) {
            if ((bin->pos_boule.x > bin->deplacements.x - 120 &&
            bin->pos_boule.x < bin->deplacements.x + 120 &&
            bin->pos_boule.y > bin->deplacements.y - 170 &&
            bin->pos_boule.y < bin->deplacements.y + 170) ||
            (bin->pos_boule2.x > bin->deplacements.x - 120 &&
            bin->pos_boule2.x < bin->deplacements.x + 120 &&
            bin->pos_boule2.y > bin->deplacements.y - 400 &&
            bin->pos_boule2.y < bin->deplacements.y + 400)) {
                bin->rect_flamme.left = 0;
                bin->rect_vie.width -= 40;
                if (bin->rect_vie_crocodile.width < 437) {
                    bin->rect_vie_crocodile.width += 20;
                }
                bin->nb_attack = 0;
                bin->rect_sol.left = 0;
                bin->lance_feu = 0;
                bin->pos_feu.x = 700;
            }
        }
        if (bin->rect_flamme.left >= 1275) {
            bin->rect_flamme.left = 0;
            bin->pos_boule.x = (rand() % 1000);
            bin->pos_boule2.x = (rand() % 1000);
        }
        sfClock_restart(bin->clock_boule);
    }
    if (sfTime_asSeconds(sfClock_getElapsedTime(bin->clock_feu)) > 5 || bin->lance_feu == 1) {
        bin->lance_feu = 1;
        bin->feu_fini = 0;
        if (sfTime_asSeconds(sfClock_getElapsedTime(bin->clock_sol)) > 0.1) {
            bin->rect_sol.left += 100;
            if (bin->rect_sol.left >= 1000) {
                bin->rect_sol.left = 0;
                bin->lance_feu = 0;
                bin->pos_feu.x = 700;
                sfClock_restart(bin->clock_feu);
            }
            sfClock_restart(bin->clock_sol);
        }
    }
    if (sfTime_asSeconds(sfClock_getElapsedTime(bin->clock_lance_feu)) > 0.0001 && bin->feu_fini == 0 && bin->lance_feu == 0) {
        bin->pos_feu.x -= 15;
        if (bin->pos_feu.x <= -1400) {
            bin->pos_feu.x = 700;
            bin->feu_fini = 1;
            bin->rect_feu.left = 0;
        }
        sfClock_restart(bin->clock_lance_feu);
    }
    if (sfTime_asSeconds(sfClock_getElapsedTime(bin->clock_anim_feu)) > 0.14) {
        bin->rect_feu.left += 210;
        if (bin->rect_feu.left >= 3780) {
            bin->rect_feu.left = 0;
        }
        sfClock_restart(bin->clock_anim_feu);
    }
}

void lance_boulemarine(struct bin *bin)
{
    if (sfTime_asSeconds(sfClock_getElapsedTime(bin->clock_akainu)) > 15) {
        bin->rect_flamme.left = 0;
        if (bin->rect_vie.width <= 377) {
            bin->rect_vie.width += 80;
        }
        bin->nb_attack = 0;
        bin->rect_sol.left = 0;
        bin->lance_feu = 0;
        bin->pos_feu.x = 700;
        sfClock_restart(bin->clock_akainu);
    } else {
        bin->pos_crocodile.x = 1500; bin->pos_crocodile.y = 320;
        lance_boulemarine2(bin);
        clock_anim_boulemarine(bin);
    }
}

void clock_deplacements_crocomarine(struct bin *bin)
{
    if (sfTime_asSeconds(sfClock_getElapsedTime(bin->moove_crocodile)) > 0.01) {
        droite_gauche_crocomarine(bin);
        if (bin->pos_crocodile.x <= bin->deplacements.x + 300 &&
        bin->pos_crocodile.x >= bin->deplacements.x - 800) {
            bin->touche = 1;
        } else {
            bin->touche = 0;
        }if (bin->nb_attack >= 2 && bin->mort == 0) {
            lance_boulemarine(bin);
        } else {
            bin->rect_flamme.left = 0;
            bin->rect_sol.left = 0;
            bin->lance_feu = 0;
            bin->pos_feu.x = 700;
            bin->rect_feu.left = 0;
            sfClock_restart(bin->clock_akainu);
            auto_crocomarine(bin);
        }if (bin->rect_vie_crocodile.width <= 0) {
            bin->rect_vie_crocodile.width = 0;
            bin->mort = 1; bin->pos_crocodile.y = 700;
            bin->crocodile = bin->akainu_mort;
            sfSprite_setScale(bin->crocodile, (sfVector2f) {6, 6});
        }if (bin->rect_vie.width <= 0) {
            game_over_akainu(bin);
        }sfClock_restart(bin->moove_crocodile);
    }
}
