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

int save_quit(struct bin *bin)
{
    if (bin->avancement == 0) {
        bin->save = "0";
    }if (bin->avancement == 1) {
        bin->save = "1";
    }if (bin->avancement == 2) {
        bin->save = "2";
    }if (bin->avancement == 3) {
        bin->save = "3";
    }if (bin->avancement == 4) {
        bin->save = "4";
    }
    int fd = open("log.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    size_t taille = my_strlen(bin->save);
    if (write(fd, bin->save, taille) != taille) {
        close(fd);
    }
    close(fd);
    return (69);
}

void bouttons_escape(struct bin *bin, sfRenderWindow *Window)
{
    bin->pause = bin->pause_c;
    if (bin->mouse.x > 700 && bin->mouse.x < 1200 &&
    bin->mouse.y > 220 && bin->mouse.y < 320 && bin->opt == 0) {
        bin->pause = bin->pause1_c;
        if (bin->event.type == sfEvtMouseButtonPressed &&
        bin->event.mouseButton.button == sfMouseLeft) {
            bin->bind_escape = 0;
            bin->evenement = 0;
        }
    }
    if (bin->mouse.x > 800 && bin->mouse.x < 1100 &&
    bin->mouse.y > 380 && bin->mouse.y < 470 && bin->opt == 0) {
        bin->pause = bin->pause2_c;
        if (bin->event.type == sfEvtMouseButtonPressed &&
        bin->event.mouseButton.button == sfMouseLeft) {
            options_funtion(bin, Window);
        }
    }
}

void press_escape(struct bin *bin, sfRenderWindow *Window)
{
    fermer_option(bin, Window);
    bouttons_escape(bin, Window);
    if (bin->mouse.x > 700 && bin->mouse.x < 1200 &&
    bin->mouse.y > 550 && bin->mouse.y < 720 && bin->opt == 0) {
        bin->pause = bin->pause3_c;
        if (bin->event.type == sfEvtMouseButtonPressed &&
        bin->event.mouseButton.button == sfMouseLeft) {
            save_quit(bin);
        }
    }
    sfRenderWindow_drawSprite(Window, bin->pause, NULL);
    if (bin->opt == 1) {
        sfRenderWindow_drawSprite(Window, bin->options, NULL);
        sfRenderWindow_drawRectangleShape(Window, bin->volume, NULL);
    }
}

void binds(struct bin *bin, sfRenderWindow *Window)
{
    if (bin->bind_escape == 1) {
        press_escape(bin, Window);
    }
    if (bin->bind_f == 1) {
        sfRenderWindow_drawSprite(Window, bin->inventaire, NULL);
    }
    if (bin->tab == 1) {
        sfRenderWindow_drawSprite(Window, bin->carte, NULL);
    }
    if (bin->t == 1) {
        press_tt(bin, Window);
        press_ttt(bin, Window);
        press_tttt(bin, Window);
        press_ttttt(bin, Window);
    }
}
