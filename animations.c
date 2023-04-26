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

int animation_course_ile(struct bin *bin)
{
    if (sfTime_asSeconds(sfClock_getElapsedTime(bin->moove)) > 0.2) {
        if (sfKeyboard_isKeyPressed(sfKeyUp) ||
        sfKeyboard_isKeyPressed(sfKeyZ)) {
            bin->frameRectgauche.left -= 63;
        }if (sfKeyboard_isKeyPressed(sfKeyDown) ||
        sfKeyboard_isKeyPressed(sfKeyS)) {
            bin->frameRectgauche.left -= 63;
        }if (sfKeyboard_isKeyPressed(sfKeyRight) ||
        sfKeyboard_isKeyPressed(sfKeyD)) {
            bin->frameRectdroite.left += 63;
        }if (sfKeyboard_isKeyPressed(sfKeyLeft) ||
        sfKeyboard_isKeyPressed(sfKeyQ)) {
            bin->frameRectgauche.left -= 63;
        }
        if (bin->frameRectgauche.left < 0) {
            bin->frameRectgauche.left = 440;
        }if (bin->frameRectdroite.left >= bin->texturewidth) {
            bin->frameRectdroite.left = 0;
        }sfClock_restart(bin->moove);
    }
}

void auto_attack_finished(struct bin *bin)
{
    if (bin->in_range == 1 && bin->mort == 0 && bin->poing == 1 && bin->nb_ile == 1) {
        bin->rect_vie_crocodile.width -= 30 + (bin->stat_force / 2);
    }
    if (bin->in_range == 1 && bin->mort == 0 && bin->poing == 1 && bin->nb_ile == 2) {
        bin->rect_vie_crocodile.width -= 20 + (bin->stat_force / 2);
    }
    if (bin->in_range == 1 && bin->mort == 0 && bin->poing == 1 && bin->nb_ile == 3) {
        bin->rect_vie_crocodile.width -= 7 + (bin->stat_force / 10);
    }
    if (bin->rect_mana.width > 50) {
        bin->rect_mana.width -= 50 - (bin->stat_mana / 2);
    }
    bin->frameRectpoing.left = 0; bin->poing = 0;
}

void clock_animations_deplacements_attack(struct bin *bin)
{
    if (bin->elapsed > bin->frameDuree) {
        bin->elapsed -= bin->frameDuree;
        if (sfKeyboard_isKeyPressed(sfKeyRight) ||
        sfKeyboard_isKeyPressed(sfKeyD)) {
            bin->frameRectdroite.left += 63;
        }if (sfKeyboard_isKeyPressed(sfKeyLeft) ||
        sfKeyboard_isKeyPressed(sfKeyQ)) {
            bin->frameRectgauche.left -= 63;
        }if (sfKeyboard_isKeyPressed(sfKeyE) || bin->poing == 1) {
            bin->frameRectpoing.left += 85;
        }if (bin->frameRectgauche.left < 0) {
            bin->frameRectgauche.left = 440;
        }if (bin->frameRectdroite.left >= bin->texturewidth) {
            bin->frameRectdroite.left = 0;
        }if (bin->frameRectpoing.left >= 400) {
            auto_attack_finished(bin);
        }
    }
}

void attack_finished(struct bin *bin)
{
    if (bin->in_range == 1 && bin->mort == 0 && bin->gome == 1) {
        bin->rect_vie_crocodile.width -= 40 + (bin->stat_force);
    }
    if (bin->rect_mana.width > 100) {
        bin->rect_mana.width -= 100;
    }
    bin->gome = 0;
    bin->frameRectspell.left = 0;
}

int animation_course(struct bin *bin, sfClock *clock, sfClock *gum)
{
    bin->elapsed += sfTime_asSeconds(sfClock_restart(clock));
    bin->elipse += sfTime_asSeconds(sfClock_restart(gum));
    if (bin->elipse > bin->gumgum) {
        bin->elipse -= bin->gumgum;
        if ((sfKeyboard_isKeyPressed(sfKeyR) && bin->press_r == 1)|| bin->gome == 1) {
            bin->frameRectspell.left += 100;
        }
        if (bin->frameRectspell.left >= 1200) {
            attack_finished(bin);
        }
    }
    clock_animations_deplacements_attack(bin);
}
