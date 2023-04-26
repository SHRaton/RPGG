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

void moove_rightskypea(struct bin *bin)
{
    if (bin->decor.x <= -3800) {
        boss_skypea(bin);
    }
    if (bin->deplacements.x > 1500 && bin->decor.x > -3800) {
        bin->decor.x -= 10;
    } else if (bin->deplacements.x <= 1500) {
        bin->deplacements.x += 10;
    }
}

void rightskypea(struct bin *bin)
{
    if (sfKeyboard_isKeyPressed(sfKeyRight) ||
    sfKeyboard_isKeyPressed(sfKeyD)) {
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
        if (bin->deplacements.x < 2000) {
            moove_rightskypea(bin);
        }
    } else {
        bin->frameRectdroite.left = 0;
    }
}

void moove_leftskypea(struct bin *bin)
{
    if (bin->deplacements.x < 4050 && bin->decor.x < 0) {
        bin->decor.x += 10;
    } else {
        bin->deplacements.x -= 10;
    }
}

void leftskypea(struct bin *bin)
{
    if (sfKeyboard_isKeyPressed(sfKeyLeft) ||
    sfKeyboard_isKeyPressed(sfKeyQ)) {
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
        if (bin->deplacements.x > 0) {
            moove_leftskypea(bin);
        }
    } else
        bin->frameRectgauche.left = 440;
}

int deplacement_persoskypea(struct bin *bin)
{
    if (bin->deplacements.x <= 0) {
        sfRenderWindow_close(bin->ILE1);
    }
    if (bin->evenement == 0) {
        rightskypea(bin);
        leftskypea(bin);
        autoattackskypea(bin);
        spell_1skypea(bin);
    }
}
