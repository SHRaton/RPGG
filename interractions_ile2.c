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

void interractions_ile1(struct bin *bin)
{
    if (bin->deplacements_ile.x > -5210 && bin->deplacements_ile.x < -4760 &&
    bin->deplacements_ile.y > -1530 && bin->deplacements_ile.y < -1020) {
        bin->f = 1;
        if (sfKeyboard_isKeyPressed(sfKeyF)) {
            ile1(bin);
        }
    } else {
        bin->f = 0;
    }
    if (bin->deplacements_ile.x > -3150 && bin->deplacements_ile.x < -2700 &&
    bin->deplacements_ile.y > -3650 && bin->deplacements_ile.y < -3450) {
        bin->chopper_f = 1;
        if (sfKeyboard_isKeyPressed(sfKeyF)) {
            dialogue_chopper(bin);
        }
    } else {
        bin->chopper_f = 0;
    }
}
