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

int fermer_bossskypea(struct bin *bin)
{
    if (bin->event.type == sfEvtClosed) {
        exit (0);
    }
    tab2(bin);
    inventory(bin);
    hud_pause(bin);
    skilltree(bin);
}

int affichage_bossskypea(struct bin *bin)
{
    sfRenderWindow_drawSprite(bin->Boss, bin->salle_boss, NULL);
}

void affichages_ile_boss2skypea(struct bin *bin)
{
    sfSprite_setPosition(bin->vie_crocodile, bin->pos_crocodile);
    sfRenderWindow_drawSprite(bin->Boss, bin->crocodile, NULL);
    sfRenderWindow_drawSprite(bin->Boss, bin->vie_crocodile, NULL);
    if (bin->mort == 1) { sfSprite_setPosition(bin->drop_enel, bin->pos_crocodile);
        sfRenderWindow_drawSprite(bin->Boss, bin->drop_enel, NULL);
    }sfRenderWindow_drawSprite(bin->Boss, bin->perso, NULL);
    sfSprite_setTextureRect(bin->vie_crocodile, bin->rect_vie_crocodile);
    sfSprite_setTextureRect(bin->vie, bin->rect_vie);
    sfSprite_setTextureRect(bin->mana, bin->rect_mana);
    sfRenderWindow_drawSprite(bin->Boss, bin->vie, NULL);
    sfRenderWindow_drawSprite(bin->Boss, bin->mana, NULL);
    if (bin->nb_attack >= 2) {
        sfSprite_setTextureRect(bin->wukong_boule, bin->rect_boule);
        sfSprite_setPosition(bin->wukong_boule, bin->pos_boule);
        sfSprite_setScale(bin->wukong_boule, (sfVector2f) {2.5, 2.5});
        sfRenderWindow_drawSprite(bin->Boss, bin->wukong_boule, NULL);
        sfSprite_setTextureRect(bin->wukong_boule, bin->rect_boule2);
        sfSprite_setPosition(bin->wukong_boule, bin->pos_boule2);
        sfRenderWindow_drawSprite(bin->Boss, bin->wukong_boule, NULL);
    }quetes(bin, bin->Boss); binds(bin, bin->Boss);
    sfRenderWindow_display(bin->Boss);
}

void affichages_ile_bossskypea(struct bin *bin, sfClock *clock, sfClock *gum)
{
    sfSprite_setPosition(bin->perso, bin->deplacements);
    sfRenderWindow_clear(bin->Boss, sfWhite);
    sfSprite_setPosition(bin->ile, bin->decor);
    sfRenderWindow_drawSprite(bin->Boss, bin->Clouds, NULL);
    set_hudskypea(bin);
    animation_course(bin, clock, gum);
    sfSprite_setPosition(bin->crocodile, bin->pos_crocodile);
    if (bin->decale == 1 && bin->mort == 0) {
        bin->pos_crocodile.x -= 200;
        sfSprite_setPosition(bin->crocodile, bin->pos_crocodile);
        bin->pos_crocodile.x += 200;
    }
    affichages_ile_boss2skypea(bin);
}

int animation_course_bossskypea(struct bin *bin, sfClock *clock, sfClock *gum)
{
    bin->elapsed += sfTime_asSeconds(sfClock_restart(clock));
    bin->elipse += sfTime_asSeconds(sfClock_restart(gum));
    if (bin->elipse > bin->gumgum) {
        bin->elipse -= bin->gumgum;
        if ((sfKeyboard_isKeyPressed(sfKeyR) && bin->press_r == 1)|| bin->gome == 1) {
            bin->frameRectspell.left += 100;
        }
        if (bin->frameRectspell.left >= 1200) {
            fin_specialskypea(bin);
        }
    }
    clock_animations_deplacements_attack(bin);
}
