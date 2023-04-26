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

int fermer(struct bin *bin)
{
    if (bin->event.type == sfEvtClosed) {
        sfRenderWindow_close(bin->Window);
    }
}

int fermer_start(struct bin *bin)
{
    if (bin->event.type == sfEvtClosed) {
        sfRenderWindow_close(bin->Start);
        bin->exit = 69;
    }
}

int game_function(struct bin *bin)
{
    bin->Window = sfRenderWindow_create(bin->video_mode, "RPG",
    sfClose | sfResize, NULL);
    sfRenderWindow_clear(bin->Window, sfWhite);
    sfRenderWindow_setFramerateLimit(bin->Window, bin->fps);
    bin->quete = 1;
    while (sfRenderWindow_isOpen(bin->Window)) {
        while (sfRenderWindow_pollEvent(bin->Window, &bin->event)) {
            fermer(bin); directions(bin);
        }
        sfSprite_setPosition(bin->ocean, bin->pos_ocean);
        sfRenderWindow_clear(bin->Window, sfWhite);
        sfRenderWindow_drawSprite(bin->Window, bin->ocean, NULL);
        sfRenderWindow_drawSprite(bin->Window, bin->sunny, NULL);
        hud(*bin, bin->Window);
        sfSprite_setTextureRect(bin->vie, bin->rect_vie);
        sfSprite_setTextureRect(bin->mana, bin->rect_mana);
        sfRenderWindow_drawSprite(bin->Window, bin->vie, NULL);
        sfRenderWindow_drawSprite(bin->Window, bin->mana, NULL);
        quetes(bin, bin->Window); binds(bin, bin->Window);
        if (bin->nb_ile == 2 && bin->evenement == 1 && bin->d_croco == 0) {
            if (sfKeyboard_isKeyPressed(sfKeyEnter)) {
                bin->evenement = 0;
                bin->d_croco = 69;
            }
            sfRenderWindow_drawSprite(bin->Window, bin->dialogue_croco, NULL);
        }
        if (bin->nb_ile == 3 && bin->evenement == 1 && bin->d_enel == 0) {
            if (sfKeyboard_isKeyPressed(sfKeyEnter)) {
                bin->evenement = 0;
                bin->d_enel = 69;
            }
            sfRenderWindow_drawSprite(bin->Window, bin->dialogue_enel, NULL);
        }
        if (bin->nb_ile == 4 && bin->evenement == 1 && bin->d_akainu == 0) {
            if (sfKeyboard_isKeyPressed(sfKeyEnter)) {
                bin->evenement = 0;
                bin->d_akainu = 69;
            }
            sfRenderWindow_drawSprite(bin->Window, bin->dialogue_akainu, NULL);
        }
        sfRenderWindow_display(bin->Window);
    }sfRenderWindow_destroy(bin->Window); return 0;
}

int start_funtion(struct bin *bin)
{
    int k = 0;
    bin->Start = sfRenderWindow_create(bin->video_mode, "Start",
    sfClose | sfResize, NULL);
    bin->mouse = sfMouse_getPosition((const sfWindow *)bin->Start);
    while (sfRenderWindow_isOpen(bin->Start)) {
        if (bin->exit == 69) {
            return (69);
        }
        while (sfRenderWindow_pollEvent(bin->Start, &bin->event)) {
            fermer_start(bin);
        }
        bin->mouse = sfMouse_getPosition((const sfWindow *)bin->Start);
        animation_pick(bin, &k);
        sfRenderWindow_display(bin->Start);
    }
    sfRenderWindow_destroy(bin->Start);
}

int main(int ac, char **av)
{
    struct bin bin;
    apply(&bin);
    //boss_marine(&bin);
    //exit (0);
    if (menu_funtion(&bin) == 69) {
        return (0);
    }
    game_function(&bin);
}
