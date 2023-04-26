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

int fermer_boss(struct bin *bin)
{
    if (bin->event.type == sfEvtClosed) {
        exit (0);
    }
    tab2(bin);
    inventory(bin);
    hud_pause(bin);
    skilltree(bin);
}

int affichage_boss(struct bin *bin)
{
    sfRenderWindow_drawSprite(bin->Boss, bin->salle_boss, NULL);
}

void affichages_ile_boss2(struct bin *bin)
{
    sfSprite_setPosition(bin->vie_crocodile, bin->pos_crocodile);
    sfSprite_setScale(bin->crocodile, (sfVector2f) {8, 8});
    sfRenderWindow_drawSprite(bin->Boss, bin->crocodile, NULL);
    sfRenderWindow_drawSprite(bin->Boss, bin->vie_crocodile, NULL);
    if (bin->mort == 1) {
        sfSprite_setPosition(bin->drop_croco, bin->pos_crocodile);
        sfRenderWindow_drawSprite(bin->Boss, bin->drop_croco, NULL);
    }
    sfRenderWindow_drawSprite(bin->Boss, bin->perso, NULL);
    sfSprite_setTextureRect(bin->vie_crocodile, bin->rect_vie_crocodile);
    sfSprite_setTextureRect(bin->vie, bin->rect_vie);
    sfSprite_setTextureRect(bin->mana, bin->rect_mana);
    sfRenderWindow_drawSprite(bin->Boss, bin->vie, NULL);
    sfRenderWindow_drawSprite(bin->Boss, bin->mana, NULL);
    quetes(bin, bin->Boss); binds(bin, bin->Boss);
    sfRenderWindow_display(bin->Boss);
}

void affichages_ile_boss(struct bin *bin, sfClock *clock, sfClock *gum)
{
    sfSprite_setPosition(bin->perso, bin->deplacements);
    sfRenderWindow_clear(bin->Boss, sfWhite);
    sfSprite_setPosition(bin->ile, bin->decor);
    sfSprite_setScale(bin->Port_c, (sfVector2f) {2, 2});
    sfRenderWindow_drawSprite(bin->Boss, bin->Port_c, NULL);
    set_hud(bin);
    animation_course(bin, clock, gum);
    sfSprite_setPosition(bin->crocodile, bin->pos_crocodile);
    if (bin->decale == 1 && bin->mort == 0) {
        bin->pos_crocodile.x -= 200;
        sfSprite_setPosition(bin->crocodile, bin->pos_crocodile);
        bin->pos_crocodile.x += 200;
    }
    affichages_ile_boss2(bin);
}

int animation_course_boss(struct bin *bin, sfClock *clock, sfClock *gum)
{
    bin->elapsed += sfTime_asSeconds(sfClock_restart(clock));
    bin->elipse += sfTime_asSeconds(sfClock_restart(gum));
    if (bin->elipse > bin->gumgum) {
        bin->elipse -= bin->gumgum;
        if ((sfKeyboard_isKeyPressed(sfKeyR) && bin->press_r == 1)|| bin->gome == 1) {
            bin->frameRectspell.left += 100;
        }
        if (bin->frameRectspell.left >= 1200) {
            fin_special(bin);
        }
    }
    clock_animations_deplacements_attack(bin);
}
