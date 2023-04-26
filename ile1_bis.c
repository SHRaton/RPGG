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

int deplacement_perso(struct bin *bin)
{
    if (bin->deplacements.x <= 0) {
        sfRenderWindow_close(bin->ILE1);
    }
    if (bin->evenement == 0) {
        right(bin);
        left(bin);
        autoattack(bin);
        spell_1(bin);
    }
}

int saut_perso(struct bin *bin)
{
    if ((sfKeyboard_isKeyPressed(sfKeySpace) || bin->jump == 1) &&
    bin->jump != 2) {
        bin->deplacements.y -= 10;
        bin->jump = 1;
        if (bin->deplacements.y < 290) {
            bin->jump = 0;
        }
    }
    if (bin->deplacements.y <= 300 || bin->jump == 2) {
        bin->jump = 2;
        bin->deplacements.y += 10;
        if (bin->deplacements.y >= 500) {
            bin->jump = 0;
            bin->deplacements.y = 500;
        }
    }
}

int collisions(struct bin *bin)
{
    bin->x = (bin->deplacements_ile.x * -1) / 5 + 206;
    bin->y = (bin->deplacements_ile.y * -1) / 5 + 150;
}

int gestion_mana(struct bin *bin, sfClock *mana)
{
    if (sfTime_asSeconds(sfClock_getElapsedTime(mana)) > 0.1) {
    if (bin->rect_mana.width <= 457) {
        bin->rect_mana.width += 1;
    }sfClock_restart(mana);
    }
}
