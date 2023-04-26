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

void fermer_option2(struct bin *bin, sfRenderWindow *Window)
{
    if (bin->mouse.x > 810 && bin->mouse.x < 880 &&
        bin->mouse.y > 350 && bin->mouse.y < 400 &&
        bin->event.type == sfEvtMouseButtonPressed &&
        bin->event.mouseButton.button == sfMouseLeft) {
        bin->fps = 120;
        bin->options = bin->options2_c;
        sfRenderWindow_setFramerateLimit(Window, bin->fps);
    }
    if (bin->mouse.x > 777 && bin->mouse.x < 1300 &&
        bin->mouse.y > 435 && bin->mouse.y < 478 &&
        bin->event.type == sfEvtMouseButtonPressed &&
        bin->event.mouseButton.button == sfMouseLeft) {
        bin->size_volume.x = bin->mouse.x - 777;
        sfSound_setVolume(bin->sound, bin->size_volume.x / 5);
        sfRectangleShape_setSize(bin->volume, bin->size_volume);
    }
}

int fermer_option(struct bin *bin, sfRenderWindow *Window)
{
    if (bin->mouse.x > 500 && bin->mouse.x < 600 &&
        bin->mouse.y > 150 && bin->mouse.y < 250 &&
        bin->event.type == sfEvtMouseButtonPressed &&
        bin->event.mouseButton.button == sfMouseLeft) {
        bin->opt = 0;
    }
    if (bin->mouse.x > 670 && bin->mouse.x < 750 &&
        bin->mouse.y > 350 && bin->mouse.y < 400 &&
        bin->event.type == sfEvtMouseButtonPressed &&
        bin->event.mouseButton.button == sfMouseLeft) {
        bin->fps = 60;
        bin->options = bin->options_c;
        sfRenderWindow_setFramerateLimit(Window, bin->fps);
    }
    fermer_option2(bin, Window);
}

int affichage_options(struct bin *bin, sfRenderWindow *Window)
{
    sfRenderWindow_drawSprite(Window, bin->options, NULL);
    sfRenderWindow_drawRectangleShape(Window, bin->volume, NULL);
}

int options_funtion(struct bin *bin, sfRenderWindow *Window)
{
    bin->opt = 1;
    bin->mouse = sfMouse_getPosition((const sfWindow *)Window);
    fermer_option(bin, Window);
    affichage_options(bin, Window);
}
