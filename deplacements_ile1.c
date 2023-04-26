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

void stop_obstacle(struct bin *bin)
{
    if (bin->pick == 1) {
        bin->luffy = bin->luffyfy;
        sfSprite_setPosition(bin->luffy, (sfVector2f) {900, 500});
    }if (bin->pick == 2) {
        bin->luffy = bin->zororo;
        sfSprite_setPosition(bin->luffy, (sfVector2f) {900, 470});
    }if (bin->pick == 3) {
        bin->luffy = bin->sanjiji;
        sfSprite_setPosition(bin->luffy, (sfVector2f) {900, 470});
    }
    sfSprite_setScale(bin->luffy, (sfVector2f){4, 4});
}

int droite_ile(struct bin *bin)
{
    bin->couleur = sfImage_getPixel(bin->screenshot, bin->x + 10, bin->y);
    if (bin->event.type == sfEvtKeyPressed &&
    sfKeyboard_isKeyPressed(sfKeyRight)) {
        if (bin->couleur.r == 255 && bin->couleur.g == 0 &&
        bin->couleur.b == 255) {
            stop_obstacle(bin); return (0);
        }bin->deplacements_ile.x -= 10;
        bin->deplacement_chopper.x -= 10;
        if (bin->pick == 1) {
            bin->luffy = bin->luffyright;
            sfSprite_setPosition(bin->luffy, (sfVector2f) {900, 500});
        }if (bin->pick == 2) {
            bin->luffy = bin->zororight;
            sfSprite_setPosition(bin->luffy, (sfVector2f) {900, 450});
        }if (bin->pick == 3) {
            bin->luffy = bin->sanjiright;
            sfSprite_setPosition(bin->luffy, (sfVector2f) {900, 470});
        }sfSprite_setScale(bin->luffy, (sfVector2f){3.5, 3.5});
        sfSprite_setTextureRect(bin->luffy, bin->frameRectdroite);
    }
}

int gauche_ile(struct bin *bin)
{
    bin->couleur = sfImage_getPixel(bin->screenshot, bin->x - 10, bin->y);
    if (bin->event.type == sfEvtKeyPressed &&
    sfKeyboard_isKeyPressed(sfKeyLeft)) {
        if (bin->couleur.r == 255 && bin->couleur.g == 0 &&
        bin->couleur.b == 255) {
            stop_obstacle(bin); return (0);
        }bin->deplacements_ile.x += 10;
        bin->deplacement_chopper.x += 10;
        if (bin->pick == 1) {
            bin->luffy = bin->luffygauche;
            sfSprite_setPosition(bin->luffy, (sfVector2f) {900, 500});
        }if (bin->pick == 2) {
            bin->luffy = bin->zorogauche;
            sfSprite_setPosition(bin->luffy, (sfVector2f) {900, 450});
        }if (bin->pick == 3) {
            bin->luffy = bin->sanjigauche;
            sfSprite_setPosition(bin->luffy, (sfVector2f) {900, 470});
        }sfSprite_setScale(bin->luffy, (sfVector2f){3.5, 3.5});
        sfSprite_setTextureRect(bin->luffy, bin->frameRectgauche);
    }
}

int haut_ile(struct bin *bin)
{
    bin->couleur = sfImage_getPixel(bin->screenshot, bin->x, bin->y - 10);
    if (bin->event.type == sfEvtKeyPressed &&
    sfKeyboard_isKeyPressed(sfKeyUp)) {
        if (bin->couleur.r == 255 && bin->couleur.g == 0 &&
        bin->couleur.b == 255) {
            stop_obstacle(bin);
            return (0);
        }bin->deplacements_ile.y += 10; bin->deplacement_chopper.y += 10;
        if (bin->pick == 1) {
            bin->luffy = bin->luffytop;
            sfSprite_setPosition(bin->luffy, (sfVector2f) {900, 450});
        }if (bin->pick == 2) {
            bin->luffy = bin->zorotop;
            sfSprite_setPosition(bin->luffy, (sfVector2f) {900, 450});
        }if (bin->pick == 3) {
            bin->luffy = bin->sanjitop;
            sfSprite_setPosition(bin->luffy, (sfVector2f) {900, 450});
        }sfSprite_setScale(bin->luffy, (sfVector2f){3.5, 3.5});
        sfSprite_setTextureRect(bin->luffy, bin->frameRectgauche);
    }
}

int bas_ile(struct bin *bin)
{
    bin->couleur = sfImage_getPixel(bin->screenshot, bin->x, bin->y + 10);
    if (bin->event.type == sfEvtKeyPressed &&
    sfKeyboard_isKeyPressed(sfKeyDown)) {
        if (bin->couleur.r == 255 && bin->couleur.g == 0 &&
        bin->couleur.b == 255) {
            stop_obstacle(bin);
            return (0);
        }bin->deplacements_ile.y -= 10; bin->deplacement_chopper.y -= 10;
        if (bin->pick == 1) {
            bin->luffy = bin->luffybas;
            sfSprite_setPosition(bin->luffy, (sfVector2f) {900, 450});
        }if (bin->pick == 2) {
            bin->luffy = bin->zorobas;
            sfSprite_setPosition(bin->luffy, (sfVector2f) {900, 450});
        }if (bin->pick == 3) {
            bin->luffy = bin->sanjibas;
            sfSprite_setPosition(bin->luffy, (sfVector2f) {900, 450});
        }sfSprite_setScale(bin->luffy, (sfVector2f){3.5, 3.5});
        sfSprite_setTextureRect(bin->luffy, bin->frameRectgauche);
    }
}
