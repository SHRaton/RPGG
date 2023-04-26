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

void diag_hg(struct bin *bin)
{
    if (bin->event.type == sfEvtKeyPressed &&
    (sfKeyboard_isKeyPressed(sfKeyUp) || sfKeyboard_isKeyPressed(sfKeyZ))
    && (sfKeyboard_isKeyPressed(sfKeyLeft) || sfKeyboard_isKeyPressed(sfKeyQ))
    && bin->border_bug == 0) {
        sfSprite_setRotation(bin->sunny, 45);
    }
}

void diag_hd(struct bin *bin)
{
    if (bin->event.type == sfEvtKeyPressed &&
    (sfKeyboard_isKeyPressed(sfKeyUp) || sfKeyboard_isKeyPressed(sfKeyZ))
    && (sfKeyboard_isKeyPressed(sfKeyRight) || sfKeyboard_isKeyPressed(sfKeyD))
    && bin->border_bug == 0) {
        sfSprite_setRotation(bin->sunny, 125);
    }
}

void diag_bg(struct bin *bin)
{
    if (bin->event.type == sfEvtKeyPressed &&
    (sfKeyboard_isKeyPressed(sfKeyDown) || sfKeyboard_isKeyPressed(sfKeyS))
    && (sfKeyboard_isKeyPressed(sfKeyLeft) || sfKeyboard_isKeyPressed(sfKeyQ))
    && bin->border_bug == 0) {
        sfSprite_setRotation(bin->sunny, -45);
    }
}

void diag_bd(struct bin *bin)
{
    if (bin->event.type == sfEvtKeyPressed &&
    (sfKeyboard_isKeyPressed(sfKeyDown) || sfKeyboard_isKeyPressed(sfKeyS))
    && (sfKeyboard_isKeyPressed(sfKeyRight) || sfKeyboard_isKeyPressed(sfKeyD))
    && bin->border_bug == 0) {
        sfSprite_setRotation(bin->sunny, 45);
    }
}
