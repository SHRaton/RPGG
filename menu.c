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

int fermer_menu(struct bin *bin)
{
    if (bin->event.type == sfEvtClosed) {
        bin->exit = 69;
        sfRenderWindow_close(bin->Menu);
    }
    if (bin->mouse.x > 600 && bin->mouse.x < 1350 &&
        bin->mouse.y > 650 && bin->mouse.y < 875 &&
        bin->event.type == sfEvtMouseButtonPressed &&
        bin->event.mouseButton.button == sfMouseLeft) {
        sfRenderWindow_close(bin->Menu);
        start_funtion(bin);
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
        if (bin->exit == 69) {
            return (69);
        }
        while (sfRenderWindow_pollEvent(bin->Menu, &bin->event)) {
            fermer_menu(bin);
        }
        bin->mouse = sfMouse_getPosition((const sfWindow *)bin->Menu);
        affichage_menu(bin);
        sfRenderWindow_display(bin->Menu);
    }
    if (bin->exit == 69) {
        return (69);
    }
    sfRenderWindow_destroy(bin->Menu);
}
