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

void resume1(struct bin *bin)
{
    if (recup_perso(bin) == 1) {
        bin->pick = 1;
        bin->luffy = bin->luffyz_c;
        sfSprite_setScale(bin->luffy, (sfVector2f){4, 4});
        sfSprite_setPosition(bin->luffy, (sfVector2f) {900, 500});
    }
    if (recup_perso(bin) == 2) {
        bin->pick = 2;
        bin->luffy = bin->zoroz_c;
        sfSprite_setScale(bin->luffy, (sfVector2f){4, 4});
        sfSprite_setPosition(bin->luffy, (sfVector2f) {900, 470});
    }
    if (recup_perso(bin) == 3) {
        bin->pick = 3;
        bin->luffy = bin->sanjiz_c;
        sfSprite_setScale(bin->luffy, (sfVector2f){4, 4});
        sfSprite_setPosition(bin->luffy, (sfVector2f) {900, 470});
    }
    bin->nb_berry = 30;
    inttostr(bin->nb_berry, bin->compteur_berry);
    bin->nb_ile = 1;
    bin->coffre_pris = 1;
    bin->dialogue_coffre = 1;
    bin->inventaire = bin->inventaire1_c;
    bin->ocean = bin->ocean1_c;
    sfSprite_setScale(bin->ocean, (sfVector2f){0.5, 0.5});
    sfSprite_setPosition(bin->ocean, bin->pos_ocean);
}

void resume2(struct bin *bin)
{
    if (recup_perso(bin) == 1) {
        bin->pick = 1;
        bin->luffy = bin->luffyz_c;
        sfSprite_setScale(bin->luffy, (sfVector2f){4, 4});
        sfSprite_setPosition(bin->luffy, (sfVector2f) {900, 500});
    }
    if (recup_perso(bin) == 2) {
        bin->pick = 2;
        bin->luffy = bin->zoroz_c;
        sfSprite_setScale(bin->luffy, (sfVector2f){4, 4});
        sfSprite_setPosition(bin->luffy, (sfVector2f) {900, 470});
    }
    if (recup_perso(bin) == 3) {
        bin->pick = 3;
        bin->luffy = bin->sanjiz_c;
        sfSprite_setScale(bin->luffy, (sfVector2f){4, 4});
        sfSprite_setPosition(bin->luffy, (sfVector2f) {900, 470});
    }
    bin->nb_berry = 80;
    inttostr(bin->nb_berry, bin->compteur_berry);
    bin->nb_ile = 2;
    bin->coffre_pris = 1;
    bin->dialogue_coffre = 1;
    bin->inventaire = bin->inventaire2_c;
    bin->ocean = bin->ocean2_c;
    sfSprite_setScale(bin->ocean, (sfVector2f){0.5, 0.5});
    sfSprite_setPosition(bin->ocean, bin->pos_ocean);
}

void resume3(struct bin *bin)
{
    if (recup_perso(bin) == 1) {
        bin->pick = 1;
        bin->luffy = bin->luffyz_c;
        sfSprite_setScale(bin->luffy, (sfVector2f){4, 4});
        sfSprite_setPosition(bin->luffy, (sfVector2f) {900, 500});
    }
    if (recup_perso(bin) == 2) {
        bin->pick = 2;
        bin->luffy = bin->zoroz_c;
        sfSprite_setScale(bin->luffy, (sfVector2f){4, 4});
        sfSprite_setPosition(bin->luffy, (sfVector2f) {900, 470});
    }
    if (recup_perso(bin) == 3) {
        bin->pick = 3;
        bin->luffy = bin->sanjiz_c;
        sfSprite_setScale(bin->luffy, (sfVector2f){4, 4});
        sfSprite_setPosition(bin->luffy, (sfVector2f) {900, 470});
    }
    bin->nb_berry = 130;
    inttostr(bin->nb_berry, bin->compteur_berry);
    bin->nb_ile = 3;
    bin->coffre_pris = 1;
    bin->dialogue_coffre = 1;
    bin->inventaire = bin->inventaire3_c;
    bin->ocean = bin->ocean3_c;
    sfSprite_setScale(bin->ocean, (sfVector2f){0.5, 0.5});
    sfSprite_setPosition(bin->ocean, bin->pos_ocean);
}

int fermer_menu(struct bin *bin)
{
    if (bin->event.type == sfEvtClosed) {
        exit(0);
    }
    if (bin->mouse.x > 600 && bin->mouse.x < 1350 &&
        bin->mouse.y > 650 && bin->mouse.y < 875 &&
        bin->event.type == sfEvtMouseButtonPressed &&
        bin->event.mouseButton.button == sfMouseLeft) {
        sfRenderWindow_close(bin->Menu);
        start_funtion(bin);
    }
    if (bin->mouse.x > 24 && bin->mouse.x < 140 &&
        bin->mouse.y > 915 && bin->mouse.y < 1020 &&
        bin->event.type == sfEvtMouseButtonPressed &&
        bin->event.mouseButton.button == sfMouseLeft) {
        if (recup_log(bin) == 0) {
            sfRenderWindow_close(bin->Menu);
            start_funtion(bin);
        }
        if (recup_log(bin) == 1) {
            resume1(bin);
            sfRenderWindow_close(bin->Menu);
            boss_function(bin);
        }
        if (recup_log(bin) == 2) {
            resume2(bin);
            sfRenderWindow_close(bin->Menu);
            boss_skypea(bin);
        }
        if (recup_log(bin) == 3) {
            resume3(bin);
            sfRenderWindow_close(bin->Menu);
            boss_marine(bin);
        }
    }
}

int affichage_menu(struct bin *bin)
{
    if (bin->mouse.x > 600 && bin->mouse.x < 1350 &&
    bin->mouse.y > 650 && bin->mouse.y < 875) {
        bin->menu = bin->menu1;
    } else if (bin->mouse.x > 1720 && bin->mouse.x < 1920 &&
    bin->mouse.y > 880 && bin->mouse.y < 1080) {
        bin->menu = bin->menu2;
    } else if (bin->mouse.x > 24 && bin->mouse.x < 140 &&
    bin->mouse.y > 915 && bin->mouse.y < 1020) {
        bin->menu = bin->menu4;
    } else {
        bin->menu = bin->menu3;
    }
    sfRenderWindow_drawSprite(bin->Menu, bin->menu, NULL);
    if (bin->mouse.x > 1720 && bin->mouse.x < 1920 &&
        bin->mouse.y > 880 && bin->mouse.y < 1080 &&
        bin->event.type == sfEvtMouseButtonPressed &&
        bin->event.mouseButton.button == sfMouseLeft || bin->opt == 1) {
        options_funtion(bin, bin->Menu);
    }
}

int menu_funtion(struct bin *bin)
{
    bin->Menu = sfRenderWindow_create(bin->video_mode, "Menu",
    sfClose | sfResize, NULL);
    bin->mouse = sfMouse_getPosition((const sfWindow *)bin->Menu);
    sfSound_play(bin->sound);
    while (sfRenderWindow_isOpen(bin->Menu)) {
        while (sfRenderWindow_pollEvent(bin->Menu, &bin->event)) {
            fermer_menu(bin);
        }
        bin->mouse = sfMouse_getPosition((const sfWindow *)bin->Menu);
        affichage_menu(bin);
        sfRenderWindow_display(bin->Menu);
    }
    sfRenderWindow_destroy(bin->Menu);
}
