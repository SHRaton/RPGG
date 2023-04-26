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

void apply6(struct bin *bin)
{
    bin->chopper = cat("img/choopper.png");
    bin->choopper_f = cat("img/choopper_f.png");
    bin->dialogue_chopp = cat("img/dialogue_chopp.png");
    bin->rect_vie.left = 0; bin->rect_vie.top = 0;
    bin->rect_vie.width = 457; bin->rect_vie.height = 23;
    bin->rect_mana.left = 0; bin->rect_mana.top = 0;
    bin->rect_mana.width = 457; bin->rect_mana.height = 23;
    bin->rect_chopper.left = 0; bin->rect_chopper.top = 0;
    bin->rect_chopper.width = 450; bin->rect_chopper.height = 450;
    sfSprite_setPosition(bin->vie, (sfVector2f) {273, 850});
    sfSprite_setPosition(bin->mana, (sfVector2f) {273, 944});
    bin->coffre_pris = 0; bin->deplacement_chopper.x = 870;
    bin->deplacement_chopper.y = -100;
    bin->font = sfFont_createFromFile("img/ArialNoir.ttf");
    bin->berrys = sfText_create();
    sfText_setString(bin->berrys, bin->compteur_berry);
    sfText_setFont(bin->berrys, bin->font);
    sfText_setCharacterSize(bin->berrys, 50);
    sfText_setFillColor(bin->berrys, sfBlack);
    sfText_setPosition(bin->berrys, (sfVector2f){1370, 160});
}

void apply7(struct bin *bin)
{
    bin->text_vie = sfText_create();
    sfText_setString(bin->text_vie, bin->compteur_vie);
    sfText_setFont(bin->text_vie, bin->font);
    sfText_setCharacterSize(bin->text_vie, 50);
    sfText_setFillColor(bin->text_vie, sfBlack);
    sfText_setPosition(bin->text_vie, (sfVector2f){525, 750});
    bin->text_force = sfText_create();
    sfText_setString(bin->text_force, bin->compteur_force);
    sfText_setFont(bin->text_force, bin->font);
    sfText_setCharacterSize(bin->text_force, 50);
    sfText_setFillColor(bin->text_force, sfBlack);
    sfText_setPosition(bin->text_force, (sfVector2f){790, 750});
    bin->text_mana = sfText_create();
    sfText_setString(bin->text_mana, bin->compteur_mana);
    sfText_setFont(bin->text_mana, bin->font);
    sfText_setCharacterSize(bin->text_mana, 50);
    sfText_setFillColor(bin->text_mana, sfBlack);
    sfText_setPosition(bin->text_mana, (sfVector2f){1060, 750});
}

void apply8(struct bin *bin)
{
    bin->text_special = sfText_create();
    sfText_setString(bin->text_special, bin->compteur_special);
    sfText_setFont(bin->text_special, bin->font);
    sfText_setCharacterSize(bin->text_special, 50);
    sfText_setFillColor(bin->text_special, sfBlack);
    sfText_setPosition(bin->text_special, (sfVector2f){1360, 750});
    bin->rect_vie_crocodile.left = 0; bin->rect_vie_crocodile.top = 0;
    bin->rect_vie_crocodile.width = 457; bin->rect_vie_crocodile.height = 23;
    bin->rect_auto_croco.left = 0; bin->rect_auto_croco.top = 0;
    bin->rect_auto_croco.width = 100; bin->rect_auto_croco.height = 100;
    bin->attack = 0; bin->direction_attack = 0; bin->in_range = 0;
    bin->mort = 0; bin->crocodile = cat("img/crocodile_gauche.png");
    bin->vie_crocodile = cat("img/vie.png");
    bin->auto_crocodile = cat("img/crocodile_auto_gauche.png");
    bin->decale = 0; bin->touche = 0;
    bin->berry = cat("img/berry.png");
    bin->chop = 0; bin->pos_crocodile.x = 1400;
    bin->exit = 667;
}

void apply9(struct bin *bin)
{
    bin->pos_crocodile.y = 170;
    bin->skill_tree = cat("img/skilltree.png");
    bin->t = 0; bin->nb_ile = 0;
    bin->salle_boss = cat("img/bosss.jpg");
    bin->dialogue = cat("img/dialogue_ace.png");
    bin->map_ile = cat("img/ile.png");
    bin->map_dessous = cat("img/map_dessous.png");
    bin->press_f = cat("img/PRESS_F.png");
    bin->colision = sfTexture_createFromFile("img/colision.png", NULL);
    bin->screenshot = sfTexture_copyToImage(bin->colision);
    bin->elapsed = 0.1; bin->frameDuration = 0.1;
    bin->elipse = 0.1; bin->gumgum = 0.09; bin->frameRect.left = 0;
    bin->frameRect.top = 0; bin->frameRect.width = 256;
    bin->frameRect.height = 192; bin->clock = sfClock_create();
    bin->textureWidth = 5376; bin->border_bug = 0;
    bin->deplacements.x = 200; bin->deplacements.y = 600;
    bin->jump = 0;
    bin->frameRectdroite.left = 0; bin->frameRectdroite.top = 0;
    bin->frameRectdroite.width = 60; bin->frameRectdroite.height = 100;
    bin->frameRectgauche.left = 440; bin->frameRectgauche.top = 0;
}
