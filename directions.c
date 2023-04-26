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

int directions(struct bin *bin)
{
    bin->mouse = sfMouse_getPosition((const sfWindow *)bin->Window);
    bin->coo_x = bin->pos_ocean.x; bin->coo_y = bin->pos_ocean.y;
    if (bin->evenement == 0) {
        gauche(bin); bas(bin); droite(bin); haut(bin);
        diag_hg(bin); diag_hd(bin); diag_bg(bin); diag_bd(bin);
    }
    bin->border_bug = 0;
    iles(bin);
    if (bin->coo_x <= -1300 && bin->coo_x >= -1400 &&
    bin->coo_y <= -3800 && bin->coo_y >= -4200 && bin->dialogue_coffre == 0) {
        coffre(bin);
    }
    if (bin->coo_x <= -1300 && bin->coo_x >= -1400 &&
    bin->coo_y <= -3800 && bin->coo_y >= -4200 && bin->nb_ile == 2) {
        ace2(bin);
    }
    if (bin->coo_x <= -1300 && bin->coo_x >= -1400 &&
    bin->coo_y <= -3800 && bin->coo_y >= -4200 && bin->nb_ile == 3) {
        ace3(bin);
    }
    if (bin->coo_x <= -1300 && bin->coo_x >= -1400 &&
    bin->coo_y <= -3800 && bin->coo_y >= -4200 && bin->nb_ile == 4) {
        ace4(bin);
        cinematique(bin);
    }
    tab(bin);
    inventory(bin);
    hud_pause(bin);
    skilltree(bin);
}
