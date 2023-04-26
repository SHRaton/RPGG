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

void right_bossmarine(struct bin *bin)
{
    if (sfKeyboard_isKeyPressed(sfKeyRight) ||
    sfKeyboard_isKeyPressed(sfKeyD) && (bin->deplacements.x < 1720)) {
        if (bin->pick == 1) {
            bin->perso = bin->luffy_right;
        }
        if (bin->pick == 2) {
            bin->perso = bin->zoro_droite;
        }
        if (bin->pick == 3) {
            bin->perso = bin->sanji_droite;
        }
        sfSprite_setScale(bin->perso, (sfVector2f) {3.7, 3.7});
        sfSprite_setTextureRect(bin->perso, bin->frameRectdroite);
        if (bin->deplacements.x < 1720) {
            moove_right_bossskypea(bin);
        }
    } else {
        bin->frameRectdroite.left = 0;
    }
}

void left_bossmarine(struct bin *bin)
{
    if ((sfKeyboard_isKeyPressed(sfKeyLeft) ||
    sfKeyboard_isKeyPressed(sfKeyQ)) && (bin->deplacements.x > 0)) {
        if (bin->pick == 1) {
            bin->perso = bin->luffy_gauche;
        }
        if (bin->pick == 2) {
            bin->perso = bin->zoro_gauche;
        }
        if (bin->pick == 3) {
            bin->perso = bin->sanji_gauche;
        }
        sfSprite_setScale(bin->perso, (sfVector2f) {3.7, 3.7});
        sfSprite_setTextureRect(bin->perso, bin->frameRectgauche);
        bin->deplacements.x -= 10;
    } else
        bin->frameRectgauche.left = 440;
}

void autoattack_bossmarine(struct bin *bin)
{
    if ((sfKeyboard_isKeyPressed(sfKeyE) || bin->poing == 1 ) &&
    (bin->rect_mana.width >= 50)) {
        bin->poing = 1;
        if (bin->pick == 1) {
            bin->perso = bin->poing_c;
        }if (bin->pick == 2) {
            bin->perso = bin->zoroautoattack_c;
            bin->deplacements.x += 3;
        }if (bin->pick == 3) {
            bin->perso = bin->sanjiautoattack_c;
        }
        sfSprite_setScale(bin->perso, (sfVector2f) {3.7, 3.7});
        sfSprite_setTextureRect(bin->vie, bin->rect_vie);
        sfSprite_setTextureRect(bin->vie, bin->rect_mana);
        sfSprite_setTextureRect(bin->perso, bin->frameRectpoing);
    } else {
        bin->frameRectpoing.left = 0;
        bin->poing = 0;
    }
}

void spell_1_bossmarine(struct bin *bin)
{
    if ((sfKeyboard_isKeyPressed(sfKeyR) || bin->gome == 1) &&
    (bin->rect_mana.width >= 100) && bin->press_r == 1) {
        bin->gome = 1;
        if (bin->pick == 1) {
            bin->perso = bin->spell_c;
            bin->deplacements.x += 5;
        }if (bin->pick == 2) {
            bin->perso = bin->zorospecialattack_c;
            bin->deplacements.x += 5;
        }if (bin->pick == 3) {
            bin->perso = bin->sanjispecialattack_c;
            bin->deplacements.x += 5;
        }
        sfSprite_setScale(bin->perso, (sfVector2f) {3.7, 3.7});
        sfSprite_setTextureRect(bin->vie, bin->rect_vie);
        sfSprite_setTextureRect(bin->vie, bin->rect_mana);
        sfSprite_setTextureRect(bin->perso, bin->frameRectspell);
    } else {
        bin->frameRectspell.left = 0; bin->gome = 0;
    }
}

int deplacement_perso_bossmarine(struct bin *bin)
{
    if (bin->evenement == 0) {
        right_bossmarine(bin);
        left_bossmarine(bin);
        autoattack_bossmarine(bin);
        spell_1_bossmarine(bin);
    }
}
