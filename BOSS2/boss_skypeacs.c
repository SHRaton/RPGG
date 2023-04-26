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

void ia_crocoskypea(struct bin *bin)
{
    clock_croco_tapeskypea(bin);
    clock_deplacements_crocoskypea(bin);
    if (bin->mort == 1 && bin->deplacements.x >= bin->pos_crocodile.x - 100 &&
    bin->deplacements.x <= bin->pos_crocodile.x - 80) {
        bin->rect_vie.width = 457;
        bin->inventaire = bin->inventaire3_c;
        bin->carte = bin->map3_c; bin->rect_mana.width = 457;
        bin->ocean = bin->ocean3_c;
        sfSprite_setScale(bin->ocean, (sfVector2f){0.5, 0.5});
        sfSprite_setPosition(bin->ocean, bin->pos_ocean);
        sfRenderWindow_close(bin->Boss);
        bin->nb_ile = 3;
        bin->evenement = 1;
        bin->nb_berry += 50;
        inttostr(bin->nb_berry, bin->compteur_berry);
        game_function(bin);
    }
}

void display_and_manaskypea(struct bin *bin, sfClock *clock, sfClock *mana, sfClock *gum)
{
    if (sfTime_asSeconds(sfClock_getElapsedTime(mana)) > 0.1) {
        if (bin->rect_mana.width <= 457) {
            bin->rect_mana.width += 2;
        }
        sfClock_restart(mana);
    }
    affichages_ile_bossskypea(bin, clock, gum);
}

void init_skypea(struct bin *bin)
{
    bin->rect_vie_crocodile.width = 457; bin->mort = 0;
    bin->rect_auto_croco.left = 0;
    bin->rect_auto_croco.top = 0;
    bin->rect_auto_croco.width = 200;
    bin->rect_auto_croco.height = 152;
    bin->crocodile = bin->wukong_gauche_c;
    bin->deplacements.x = 200; bin->deplacements.y = 500;
    bin->moove_crocodile = sfClock_create();
    bin->clock_auto_croco = sfClock_create();
    bin->pos_crocodile.x = 1300;
}

int boss_skypea(struct bin *bin)
{
    init_skypea(bin);
    sfClock *clock = sfClock_create(); sfClock *gum = sfClock_create();
    sfClock *mana = sfClock_create();
    bin->Boss = sfRenderWindow_create(bin->video_mode, "BOSS",
    sfClose | sfResize, NULL);
    bin->quete = 6;
    bin->avancement = 2;
    sfRenderWindow_setFramerateLimit(bin->Boss, bin->fps);
    while (sfRenderWindow_isOpen(bin->Boss)) {
        while (sfRenderWindow_pollEvent(bin->Boss, &bin->event)) {
            fermer_bossskypea(bin);
        }
        ia_crocoskypea(bin);
        display_and_manaskypea(bin, clock, mana, gum);
    }
    sfRenderWindow_destroy(bin->Boss);
}
