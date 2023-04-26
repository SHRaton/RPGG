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

void press_tt(struct bin *bin, sfRenderWindow *Window)
{
    bin->skill_tree = bin->skilltree_c;
    if (bin->mouse.x > 520 && bin->mouse.x < 590 &&
    bin->mouse.y > 645 && bin->mouse.y < 720) {
        if (bin->event.type == sfEvtMouseButtonPressed &&
        bin->event.mouseButton.button == sfMouseLeft &&
        bin->nb_berry >= bin->stat_vie) {
            bin->nb_berry -= bin->stat_vie; bin->stat_vie += 10;
            inttostr(bin->nb_berry, bin->compteur_berry);
            inttostr(bin->stat_vie, bin->compteur_vie);
        }bin->skill_tree = bin->skilltree1_c;
    }if (bin->mouse.x > 790 && bin->mouse.x < 860 &&
    bin->mouse.y > 645 && bin->mouse.y < 720) {
        if (bin->event.type == sfEvtMouseButtonPressed &&
        bin->event.mouseButton.button == sfMouseLeft &&
        bin->nb_berry >= bin->stat_force) {
            bin->nb_berry -= bin->stat_force; bin->stat_force += 10;
            inttostr(bin->nb_berry, bin->compteur_berry);
            inttostr(bin->stat_force, bin->compteur_force);
        }bin->skill_tree = bin->skilltree2_c;
    }
}

int press_ttt(struct bin *bin, sfRenderWindow *Window)
{
    if (bin->mouse.x > 1060 && bin->mouse.x < 1140 &&
    bin->mouse.y > 645 && bin->mouse.y < 720) {
        if (bin->event.type == sfEvtMouseButtonPressed &&
        bin->event.mouseButton.button == sfMouseLeft &&
        bin->nb_berry >= bin->stat_mana) {
            bin->nb_berry -= bin->stat_mana;
            bin->stat_mana += 10;
            inttostr(bin->nb_berry, bin->compteur_berry);
            inttostr(bin->stat_mana, bin->compteur_mana);
        }
        bin->skill_tree = bin->skilltree3_c;
    }
}

int press_tttt(struct bin *bin, sfRenderWindow *Window)
{
    if (bin->mouse.x > 1355 && bin->mouse.x < 1415 &&
    bin->mouse.y > 645 && bin->mouse.y < 720) {
        if (bin->event.type == sfEvtMouseButtonPressed &&
        bin->event.mouseButton.button == sfMouseLeft &&
        bin->nb_berry >= bin->stat_special) {
            bin->nb_berry -= bin->stat_special; bin->stat_special += 99999;
            inttostr(bin->nb_berry, bin->compteur_berry);
            sfText_setCharacterSize(bin->text_special, 80);
            sfColor rouge;
            rouge.r = 255; rouge.g = 0; rouge.b = 70; rouge.a = 255;
            sfText_setFillColor(bin->text_special, rouge);
            bin->compteur_special = "X";
            bin->press_r = 1;
        }
        bin->skill_tree = bin->skilltree4_c;
    }
}

int press_ttttt(struct bin *bin, sfRenderWindow *Window)
{
    sfRenderWindow_drawSprite(Window, bin->skill_tree, NULL);
    sfText_setString(bin->berrys, bin->compteur_berry);
    sfText_setString(bin->text_vie, bin->compteur_vie);
    sfText_setString(bin->text_force, bin->compteur_force);
    sfText_setString(bin->text_mana, bin->compteur_mana);
    sfText_setString(bin->text_special, bin->compteur_special);
    sfRenderWindow_drawText(Window, bin->berrys, NULL);
    sfRenderWindow_drawText(Window, bin->text_vie, NULL);
    sfRenderWindow_drawText(Window, bin->text_force, NULL);
    sfRenderWindow_drawText(Window, bin->text_mana, NULL);
    sfRenderWindow_drawText(Window, bin->text_special, NULL);
}
