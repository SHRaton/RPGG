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

void apply(struct bin *bin)
{
    bin->video_mode.width = 1920; bin->video_mode.height = 1080;
    bin->video_mode.bitsPerPixel = 32;
    bin->dialogue_coffre = 0;
    bin->pos_ocean.x = -1500; bin->pos_ocean.y = -4000;
    bin->decor.x = 0; bin->decor.y = 0;
    bin->coo_x = bin->pos_ocean.x; bin->coo_y = bin->pos_ocean.y;
    bin->reverse.x = 1; bin->reverse.y = 1;
    bin->centre_sunny.x = 100; bin->centre_sunny.y = 100;
    bin->nb_attack = 0; bin->compt_attack = 0;
    bin->wukong_boule = cat("img/wukong_boule.png");
    bin->rect_boule.left = 0; bin->rect_boule.top = 0;
    bin->rect_boule.width = 55; bin->rect_boule.height = 55;
    bin->rect_boule2.left = 0; bin->rect_boule2.top = 0;
    bin->rect_boule2.width = 55; bin->rect_boule2.height = 55;
    bin->pos_boule.x = 1300; bin->pos_boule.y = 500;
    bin->pos_boule2.x = 500; bin->pos_boule2.y = 0;
    apply2(bin); apply3(bin); apply4(bin);
    apply5(bin); apply6(bin); apply7(bin);
    apply8(bin); apply9(bin); applycrash(bin);
    applycrash2(bin); applycrash3(bin); applycrash4(bin);
}

void apply2(struct bin *bin)
{
    bin->nb_berry = 30;
    bin->stat_vie = 10;
    bin->stat_force = 10;
    bin->stat_mana = 10;
    bin->stat_special = 50;
    bin->compteur_berry = malloc(sizeof(char) * (999));
    inttostr(bin->nb_berry, bin->compteur_berry);
    bin->compteur_vie = malloc(sizeof(char) * (999));
    inttostr(bin->stat_vie, bin->compteur_vie);
    bin->compteur_force = malloc(sizeof(char) * (999));
    inttostr(bin->stat_force, bin->compteur_force);
    bin->compteur_mana = malloc(sizeof(char) * (999));
    inttostr(bin->stat_mana, bin->compteur_mana);
    bin->compteur_special = malloc(sizeof(char) * (999));
    inttostr(bin->stat_special, bin->compteur_special);
}

void apply3(struct bin *bin)
{
    bin->frameRectgauche.width = 60;
    bin->frameRectgauche.height = 100;
    bin->frameRectpoing.left = 0;
    bin->frameRectpoing.top = 0;
    bin->frameRectpoing.width = 85;
    bin->frameRectpoing.height = 100;
    bin->frameRectspell.left = 0;
    bin->frameRectspell.top = 0;
    bin->frameRectspell.width = 100;
    bin->frameRectspell.height = 100;
    bin->frameDuree = 0.14;
    bin->texturewidth = 500; bin->cam = 0;
    bin->clock_course = sfClock_create();
    bin->clock_boule = sfClock_create();
    bin->clock_sol = sfClock_create();
    bin->clock_feu = sfClock_create();
    bin->clock_lance_feu = sfClock_create();
    bin->clock_anim_feu = sfClock_create();
    bin->clock_akainu = sfClock_create();
    bin->lance_feu = 0;
    bin->feu_fini = 0;
    bin->bouin = sfSoundBuffer_createFromFile("img/bouin.ogg");
    bin->sound = sfSound_create();
    bin->evenement = 0; bin->tab = 0;
    bin->carte = cat("img/carte.png");
    bin->vie = cat("img/vie.png"); bin->mana = cat("img/mana.png");
    bin->avancement = 0; bin->opt = 0;
}

void apply4(struct bin *bin)
{
    bin->choose = cat("img/choose.png"); bin->pause = cat("img/pause.png");
    bin->inventaire = cat("img/inventaire.png");
    bin->f = 0; bin->bind_f = 0; bin->fps = 60; bin->bind_escape = 0;
    bin->HUD = cat("img/HUD_LUFFY.png");
    bin->HUD_LUFFY = cat("img/HUD_LUFFY.png");
    bin->HUD_ZORO = cat("img/HUD_ZORO.png");
    bin->HUD_SANJI = cat("img/HUD_SANJI.png");
    bin->HOVER_LUFFY = cat("img/HOVER_LUFFY.png");
    bin->HOVER_ZORO = cat("img/HOVER_ZORO.png");
    bin->HOVER_SANJI = cat("img/HOVER_SANJI.png");
    bin->sunny = cat("img/sunny.png"); bin->ocean = cat("img/ocean_ace.png");
    bin->pick_champ = cat("img/pick_luffy.png");
    bin->pick_luffy = cat("img/pick_luffy.png");
    bin->pick_zoro = cat("img/pick_zoro.png");
    bin->pick_sanji = cat("img/pick_sanji.png");
    bin->luffy = cat("img/luffyz.png"); bin->ile = cat("img/fight.png");
    bin->perso = cat("img/luffy_right.png"); bin->menu = cat("img/menu.png");
    bin->options = cat("img/options.png");
    bin->volume = sfRectangleShape_create();
    bin->size_volume.x = 520; bin->size_volume.y = 39;
}

void apply5(struct bin *bin)
{
    sfRectangleShape_setSize(bin->volume, bin->size_volume);
    sfRectangleShape_setFillColor(bin->volume, sfWhite);
    sfRectangleShape_setPosition(bin->volume, (sfVector2f){777, 438});
    sfSound_setBuffer(bin->sound, bin->bouin);
    sfSprite_setScale(bin->perso, (sfVector2f) {3.7, 3.7});
    sfSprite_setPosition(bin->perso, (sfVector2f) {200, 600});
    sfSprite_setScale(bin->pick_champ, (sfVector2f) {5.4, 5.4});
    sfSprite_setPosition(bin->pick_champ, (sfVector2f) {269, 0});
    sfSprite_setTextureRect(bin->pick_champ, bin->frameRect);
    sfSprite_setOrigin(bin->sunny, bin->centre_sunny);
    sfSprite_setScale(bin->ocean, (sfVector2f){0.5, 0.5});
    sfSprite_setPosition(bin->ocean, bin->pos_ocean);
    sfSprite_setPosition(bin->sunny, (sfVector2f){900, 450});
    sfSprite_setScale(bin->luffy, (sfVector2f){4, 4});
}
