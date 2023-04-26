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

void fermer_gameover(struct bin *bin)
{
    if (bin->event.type == sfEvtClosed) {
        exit(0);
    }
}

int game_over_croco(struct bin *bin)
{
    bin->gameover = sfRenderWindow_create(bin->video_mode, "Game Over",
    sfClose | sfResize, NULL);
    sfRenderWindow_setFramerateLimit(bin->gameover, bin->fps);
    while (sfRenderWindow_isOpen(bin->gameover)) {
        while (sfRenderWindow_pollEvent(bin->gameover, &bin->event)) {
            fermer_gameover(bin);
        }
        bin->mouse = sfMouse_getPosition((const sfWindow *)bin->gameover);
        if (bin->event.type == sfEvtMouseButtonPressed &&
        bin->event.mouseButton.button == sfMouseLeft &&
        bin->mouse.x > 0 && bin->mouse.x < 400 &&
        bin->mouse.y > 700 && bin->mouse.y < 850) {
            bin->rect_vie.width = 457; bin->rect_mana.width = 457;
            bin->pos_crocodile.x = 1300; bin->deplacements.x = 200;
            bin->rect_vie_crocodile.width = 457;
            sfRenderWindow_close(bin->gameover);
            return (0);
        }
        if (bin->event.type == sfEvtMouseButtonPressed &&
        bin->event.mouseButton.button == sfMouseLeft &&
        bin->mouse.x > 0 && bin->mouse.x < 400 &&
        bin->mouse.y > 860 && bin->mouse.y < 1010) {
            sfRenderWindow_close(bin->gameover);
            sfRenderWindow_close(bin->Boss);
        }
        sfRenderWindow_drawSprite(bin->gameover, bin->echec, NULL);
        sfRenderWindow_display(bin->gameover);
    }
    sfRenderWindow_destroy(bin->gameover);
}

int game_over_enel(struct bin *bin)
{
    bin->gameover = sfRenderWindow_create(bin->video_mode, "Game Over",
    sfClose | sfResize, NULL);
    sfRenderWindow_setFramerateLimit(bin->gameover, bin->fps);
    while (sfRenderWindow_isOpen(bin->gameover)) {
        while (sfRenderWindow_pollEvent(bin->gameover, &bin->event)) {
            fermer_gameover(bin);
        }
        bin->mouse = sfMouse_getPosition((const sfWindow *)bin->gameover);
        if (bin->event.type == sfEvtMouseButtonPressed &&
        bin->event.mouseButton.button == sfMouseLeft &&
        bin->mouse.x > 0 && bin->mouse.x < 400 &&
        bin->mouse.y > 700 && bin->mouse.y < 850) {
            bin->rect_vie.width = 457; bin->rect_mana.width = 457;
            bin->pos_crocodile.x = 1300; bin->deplacements.x = 200;
            bin->rect_vie_crocodile.width = 457;
            sfRenderWindow_close(bin->gameover);
            return (0);
        }
        if (bin->event.type == sfEvtMouseButtonPressed &&
        bin->event.mouseButton.button == sfMouseLeft &&
        bin->mouse.x > 0 && bin->mouse.x < 400 &&
        bin->mouse.y > 860 && bin->mouse.y < 1010) {
            sfRenderWindow_close(bin->gameover);
            sfRenderWindow_close(bin->ILE1);
            sfRenderWindow_close(bin->Window);
            sfRenderWindow_close(bin->Boss);
        }
        sfRenderWindow_drawSprite(bin->gameover, bin->echec, NULL);
        sfRenderWindow_display(bin->gameover);
    }
    sfRenderWindow_destroy(bin->gameover);
}

int game_over_akainu(struct bin *bin)
{
    bin->gameover = sfRenderWindow_create(bin->video_mode, "Game Over",
    sfClose | sfResize, NULL);
    sfRenderWindow_setFramerateLimit(bin->gameover, bin->fps);
    while (sfRenderWindow_isOpen(bin->gameover)) {
        while (sfRenderWindow_pollEvent(bin->gameover, &bin->event)) {
            fermer_gameover(bin);
        }
        bin->mouse = sfMouse_getPosition((const sfWindow *)bin->gameover);
        if (bin->event.type == sfEvtMouseButtonPressed &&
        bin->event.mouseButton.button == sfMouseLeft &&
        bin->mouse.x > 0 && bin->mouse.x < 400 &&
        bin->mouse.y > 700 && bin->mouse.y < 850) {
            bin->rect_vie.width = 457; bin->rect_mana.width = 457;
            bin->pos_crocodile.x = 1300; bin->deplacements.x = 200;
            bin->rect_vie_crocodile.width = 457;
            sfRenderWindow_close(bin->gameover);
            return (0);
        }
        if (bin->event.type == sfEvtMouseButtonPressed &&
        bin->event.mouseButton.button == sfMouseLeft &&
        bin->mouse.x > 0 && bin->mouse.x < 400 &&
        bin->mouse.y > 860 && bin->mouse.y < 1010) {
            sfRenderWindow_close(bin->gameover);
            sfRenderWindow_close(bin->Boss);
        }
        sfRenderWindow_drawSprite(bin->gameover, bin->echec, NULL);
        sfRenderWindow_display(bin->gameover);
    }
    sfRenderWindow_destroy(bin->gameover);
}
