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

void fin_specialskypea(struct bin *bin)
{
    if (bin->rect_mana.width > 100) {
        bin->rect_mana.width -= 100 - (bin->stat_mana / 2);
    }
    bin->gome = 0;
    bin->frameRectspell.left = 0;
}

void fin_attack_crocoskypea(struct bin *bin)
{
    if (bin->touche == 1 && bin->mort == 0) {
        bin->rect_vie.width -= 40 / (bin->stat_vie / 5) + 20;
    }
    bin->nb_attack += 1;
    bin->attack = 0;
    bin->rect_auto_croco.left = 0;
}

void clock_croco_tapeskypea(struct bin *bin)
{
    bin->mouse = sfMouse_getPosition((const sfWindow *)bin->Boss);
    if (bin->event.type != sfEvtKeyPressed) {
        bin->perso = bin->luffy;
    }
    deplacement_perso_bossskypea(bin);saut_perso_bossskypea(bin);
    if (sfTime_asSeconds(sfClock_getElapsedTime(bin->clock_auto_croco)) > 0.1) {
        bin->rect_auto_croco.left += 200;
        if (bin->touche == 1 && bin->mort == 0 && bin->attack == 1) {
            bin->rect_vie.width -= 5 - (bin->stat_vie / 5);
        }
        if (bin->rect_auto_croco.left > 3600) {
            fin_attack_crocoskypea(bin);
        }
        sfClock_restart(bin->clock_auto_croco);
    }
}

void droite_gauche_crocoskypea(struct bin *bin)
{
    if (bin->pos_crocodile.x <= bin->deplacements.x + 100 && bin->mort == 0) {
    } else {
        bin->crocodile = bin->wukong_gauche_c;
        if (bin->rect_vie_crocodile.width <= 200)
            bin->crocodile = bin->wukong_gauchenrv_c;
        sfSprite_setScale(bin->crocodile, (sfVector2f) {6, 6});
        bin->direction_attack = 0;
        if (bin->attack == 0)
            bin->pos_crocodile.x -= 2;
    }if (bin->pos_crocodile.x >= bin->deplacements.x - 500 && bin->mort == 0) {
    } else {
        bin->crocodile = bin->wukong_droite_c;
        if (bin->rect_vie_crocodile.width <= 200)
            bin->crocodile = bin->wukong_droitenrv_c;
        sfSprite_setScale(bin->crocodile, (sfVector2f) {6, 6});
        bin->direction_attack = 1;
        if (bin->attack == 0)
            bin->pos_crocodile.x += 2;
    }
}
