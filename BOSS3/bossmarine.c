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

int fermer_bossmarine(struct bin *bin)
{
    if (bin->event.type == sfEvtClosed) {
        exit (0);
    }
    tab2(bin);
    inventory(bin);
    hud_pause(bin);
    skilltree(bin);
}

int affichage_bossmarine(struct bin *bin)
{
    sfRenderWindow_drawSprite(bin->Boss, bin->salle_boss, NULL);
}

void affichages_ile_bossmarine2(struct bin *bin)
{
    sfSprite_setPosition(bin->vie_crocodile, bin->pos_crocodile);
    sfRenderWindow_drawSprite(bin->Boss, bin->crocodile, NULL);
    sfRenderWindow_drawSprite(bin->Boss, bin->vie_crocodile, NULL);
    if (bin->mort == 1) { sfSprite_setPosition(bin->drop_akainu, bin->pos_crocodile);
        sfRenderWindow_drawSprite(bin->Boss, bin->drop_akainu, NULL);
    }sfRenderWindow_drawSprite(bin->Boss, bin->perso, NULL);
    sfSprite_setTextureRect(bin->vie_crocodile, bin->rect_vie_crocodile);
    sfSprite_setTextureRect(bin->vie, bin->rect_vie);
    sfSprite_setTextureRect(bin->mana, bin->rect_mana);
    sfRenderWindow_drawSprite(bin->Boss, bin->vie, NULL);
    sfRenderWindow_drawSprite(bin->Boss, bin->mana, NULL);
    if (bin->nb_attack >= 2) {
        sfSprite_setTextureRect(bin->feu, bin->rect_feu);
        sfSprite_setScale(bin->feu, (sfVector2f) {6, 6});
        sfSprite_setTextureRect(bin->akainu_flamme, bin->rect_flamme);
        sfSprite_setPosition(bin->akainu_flamme, bin->pos_boule);
        sfSprite_setScale(bin->akainu_flamme, (sfVector2f) {5, 5});
        sfRenderWindow_drawSprite(bin->Boss, bin->akainu_flamme, NULL);
        sfSprite_setTextureRect(bin->akainu_flamme_top, bin->rect_flamme);
        sfSprite_setPosition(bin->akainu_flamme_top, bin->pos_boule2);
        sfSprite_setScale(bin->akainu_flamme_top, (sfVector2f) {5, 5});
        sfRenderWindow_drawSprite(bin->Boss, bin->akainu_flamme_top, NULL);
        if (bin->feu_fini == 0) {
            sfSprite_setPosition(bin->feu, bin->pos_feu);
            sfRenderWindow_drawSprite(bin->Boss, bin->feu, NULL);
        }
    }
    quetes(bin, bin->Boss); binds(bin, bin->Boss);
    sfRenderWindow_display(bin->Boss);
}

void affichages_ile_bossmarine(struct bin *bin, sfClock *clock, sfClock *gum)
{
    if (bin->lance_feu == 1) {
        bin->crocodile = bin->akainu_sol;
        sfSprite_setTextureRect(bin->crocodile, bin->rect_sol);
        sfSprite_setScale(bin->crocodile, (sfVector2f) {6, 6});
        bin->pos_crocodile.y = 250;
    }
    sfSprite_setPosition(bin->crocodile, bin->pos_crocodile);
    sfSprite_setPosition(bin->perso, bin->deplacements);
    sfRenderWindow_clear(bin->Boss, sfWhite);
    sfSprite_setPosition(bin->ile, bin->decor);
    sfRenderWindow_drawSprite(bin->Boss, bin->marineford, NULL);
    set_hudskypea(bin);
    animation_course(bin, clock, gum);
    if (bin->decale == 1 && bin->mort == 0) {
        bin->pos_crocodile.x -= 200;
        sfSprite_setPosition(bin->crocodile, bin->pos_crocodile);
        bin->pos_crocodile.x += 200;
    }
    affichages_ile_bossmarine2(bin);
}

int animation_course_bossmarine(struct bin *bin, sfClock *clock, sfClock *gum)
{
    bin->elapsed += sfTime_asSeconds(sfClock_restart(clock));
    bin->elipse += sfTime_asSeconds(sfClock_restart(gum));
    if (bin->elipse > bin->gumgum) {
        bin->elipse -= bin->gumgum;
        if ((sfKeyboard_isKeyPressed(sfKeyR) && bin->press_r == 1)|| bin->gome == 1) {
            bin->frameRectspell.left += 100;
        }
        if (bin->frameRectspell.left >= 1200) {
            fin_specialmarine(bin);
        }
    }
    clock_animations_deplacements_attack(bin);
}
