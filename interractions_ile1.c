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

int hud_pause(struct bin *bin)
{
    if (bin->event.type == sfEvtKeyPressed &&
    sfKeyboard_isKeyPressed(sfKeyEscape)) {
        if (bin->bind_escape == 0) {
            bin->bind_escape = 1;
            bin->evenement = 1;
            return (0);
        }
        if (bin->bind_escape == 1) {
            bin->bind_escape = 0;
            bin->evenement = 0;
            return (0);
        }
    }
}

int inventory(struct bin *bin)
{
    if (bin->event.type == sfEvtKeyPressed &&
    sfKeyboard_isKeyPressed(sfKeyI) ||
        (bin->event.type == sfEvtMouseButtonPressed &&
        bin->event.mouseButton.button == sfMouseLeft &&
        bin->mouse.x > 1720 && bin->mouse.x < 1920 &&
        bin->mouse.y > 880 && bin->mouse.y < 1080)) {
        if (bin->bind_f == 0) {
            bin->bind_f = 1;
            bin->evenement = 1;
            return (0);
        }
        if (bin->bind_f == 1) {
            bin->bind_f = 0;
            bin->evenement = 0;
            return (0);
        }
    }
}

int skilltree(struct bin *bin)
{
    if (bin->event.type == sfEvtKeyPressed &&
        sfKeyboard_isKeyPressed(sfKeyT) ||
        (bin->event.type == sfEvtMouseButtonPressed &&
        bin->event.mouseButton.button == sfMouseLeft &&
        bin->mouse.x > 1520 && bin->mouse.x < 1720 &&
        bin->mouse.y > 800 && bin->mouse.y < 1080)) {
        if (bin->t == 0) {
            bin->t = 1;
            bin->evenement = 1;
            return (0);
        }
        if (bin->t == 1) {
            bin->t = 0;
            bin->evenement = 0;
            return (0);
        }
    }
}

int tab(struct bin *bin)
{
    if (bin->event.type == sfEvtKeyPressed &&
        sfKeyboard_isKeyPressed(sfKeyTab) && bin->coffre_pris == 1) {
        if (bin->tab == 0) {
            bin->tab = 1;
            bin->evenement = 1;
            return (0);
        }
        if (bin->tab == 1) {
            bin->tab = 0;
            bin->evenement = 0;
            return (0);
        }
    }
}

int tab2(struct bin *bin)
{
    if (bin->event.type == sfEvtKeyPressed &&
        sfKeyboard_isKeyPressed(sfKeyTab)) {
        if (bin->tab == 0) {
            bin->tab = 1;
            bin->evenement = 1;
            return (0);
        }
        if (bin->tab == 1) {
            bin->tab = 0;
            bin->evenement = 0;
            return (0);
        }
    }
}
