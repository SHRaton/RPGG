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

void auto_croco(struct bin *bin)
{
    if (bin->pos_crocodile.x <= bin->deplacements.x + 100 &&
    bin->pos_crocodile.x >= bin->deplacements.x - 500 &&
    bin->direction_attack == 1 ||
    (bin->attack == 1 && bin->direction_attack == 1)) {
        bin->in_range = 1; bin->attack = 1;
        bin->crocodile = bin->crocodile_auto_droite_c;
        bin->pos_crocodile.y = 100;
        sfSprite_setTextureRect(bin->crocodile, bin->rect_auto_croco);
    } else if (bin->pos_crocodile.x <= bin->deplacements.x + 100 &&
    bin->pos_crocodile.x >= bin->deplacements.x - 500 &&
    bin->direction_attack == 0 ||
    (bin->attack == 1 && bin->direction_attack == 0)) {
        bin->in_range = 1; bin->attack = 1;
        bin->crocodile = bin->crocodile_auto_gauche_c;
        bin->pos_crocodile.y = 100; bin->decale = 1;
        sfSprite_setTextureRect(bin->crocodile, bin->rect_auto_croco);
    } else {
        bin->decale = 0; bin->pos_crocodile.y = 170;
        bin->rect_auto_croco.left = 0; bin->in_range = 0;
    }
}

void clock_deplacements_croco(struct bin *bin)
{
    if (sfTime_asSeconds(sfClock_getElapsedTime(bin->moove_crocodile)) > 0.01) {
        droite_gauche_croco(bin);
        if (bin->pos_crocodile.x <= bin->deplacements.x + 300 &&
        bin->pos_crocodile.x >= bin->deplacements.x - 800) {
            bin->touche = 1;
        } else {
            bin->touche = 0;
        }
        auto_croco(bin);
        if (bin->rect_vie_crocodile.width <= 0) {
            bin->rect_vie_crocodile.width = 0;
            bin->mort = 1;
            bin->pos_crocodile.y = 600;
            bin->crocodile = bin->crocodile_mort_c;
        }
        if (bin->rect_vie.width <= 0) {
            game_over_croco(bin);
        }
        sfClock_restart(bin->moove_crocodile);
    }
}

void ia_croco(struct bin *bin)
{
    clock_croco_tape(bin);
    clock_deplacements_croco(bin);
    if (bin->mort == 1 && bin->deplacements.x >= bin->pos_crocodile.x - 100 &&
    bin->deplacements.x <= bin->pos_crocodile.x - 80) {
        bin->rect_vie.width = 457;
        bin->inventaire = bin->inventaire2_c;
        bin->carte = bin->map2_c; bin->rect_mana.width = 457;
        bin->ocean = bin->ocean2_c;
        sfSprite_setScale(bin->ocean, (sfVector2f){0.5, 0.5});
        sfSprite_setPosition(bin->ocean, bin->pos_ocean);
        sfRenderWindow_close(bin->Boss);
        bin->nb_ile = 2;
        bin->evenement = 1;
        bin->nb_berry += 50;
        inttostr(bin->nb_berry, bin->compteur_berry);
        game_function(bin);
    }
}

void display_and_mana(struct bin *bin, sfClock *clock,
sfClock *mana, sfClock *gum)
{
    if (sfTime_asSeconds(sfClock_getElapsedTime(mana)) > 0.1) {
        if (bin->rect_mana.width <= 457) {
            bin->rect_mana.width += 2;
        }
        sfClock_restart(mana);
    }
    affichages_ile_boss(bin, clock, gum);
}

int boss_function(struct bin *bin)
{
    bin->deplacements.x = 200; bin->deplacements.y = 500;
    sfClock *clock = sfClock_create(); sfClock *gum = sfClock_create();
    sfClock *mana = sfClock_create();
    bin->moove_crocodile = sfClock_create();
    bin->clock_auto_croco = sfClock_create();
    bin->quete = 5;
    bin->Boss = sfRenderWindow_create(bin->video_mode, "BOSS",
    sfClose | sfResize, NULL);
    bin->avancement = 1;
    sfRenderWindow_setFramerateLimit(bin->Boss, bin->fps);
    while (sfRenderWindow_isOpen(bin->Boss)) {
        while (sfRenderWindow_pollEvent(bin->Boss, &bin->event)) {
            fermer_boss(bin);
        }
        ia_croco(bin); display_and_mana(bin, clock, mana, gum);
    }
    sfRenderWindow_destroy(bin->Boss);
}
