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

void coffre(struct bin *bin)
{
    bin->evenement = 1;
    while (bin->dialogue_coffre < 1) {
        sfRenderWindow_pollEvent(bin->Window, &bin->event);
        if (bin->event.type == sfEvtKeyPressed &&
        sfKeyboard_isKeyPressed(sfKeyEnter)) {
            bin->quete = 2;
            bin->dialogue_coffre += 1;
        }
        sfRenderWindow_drawSprite(bin->Window, bin->ocean, NULL);
        sfRenderWindow_drawSprite(bin->Window, bin->sunny, NULL);
        sfRenderWindow_drawSprite(bin->Window, bin->dialogue, NULL);
        sfRenderWindow_display(bin->Window);
    }
    bin->nb_ile = 1;
    bin->coffre_pris = 1;
    bin->evenement = 0;
    bin->inventaire = bin->inventaire1_c;
    bin->ocean = bin->ocean1_c;
    sfSprite_setScale(bin->ocean, (sfVector2f){0.5, 0.5});
}

void coffre_dialogue(struct bin *bin)
{
    int i = 0;
    while (i < 1) {
        if (sfKeyboard_isKeyPressed(sfKeyEnter)) {
            i += 1;
        }
        sfRenderWindow_drawSprite(bin->island, bin->map_ile, NULL);
        sfRenderWindow_drawSprite(bin->island, bin->chopper, NULL);
        sfRenderWindow_drawSprite(bin->island, bin->luffy, NULL);
        sfRenderWindow_drawSprite(bin->island, bin->coffre_berry, NULL);
        sfRenderWindow_drawSprite(bin->island, bin->map_dessous, NULL);
        sfRenderWindow_display(bin->island);
    }
}

void ace2(struct bin *bin)
{
    bin->evenement = 1;
    while (bin->dialogue_ace2 < 1) {
        sfRenderWindow_pollEvent(bin->Window, &bin->event);
        if (bin->event.type == sfEvtKeyPressed &&
        sfKeyboard_isKeyPressed(sfKeyEnter)) {
            bin->quete = 2;
            bin->dialogue_ace2 += 1;
        }
        sfRenderWindow_drawSprite(bin->Window, bin->ocean, NULL);
        sfRenderWindow_drawSprite(bin->Window, bin->sunny, NULL);
        sfRenderWindow_drawSprite(bin->Window, bin->d_ace2, NULL);
        sfRenderWindow_display(bin->Window);
    }
    bin->evenement = 0;
}

void ace3(struct bin *bin)
{
    bin->evenement = 1;
    while (bin->dialogue_ace3 < 1) {
        sfRenderWindow_pollEvent(bin->Window, &bin->event);
        if (bin->event.type == sfEvtKeyPressed &&
        sfKeyboard_isKeyPressed(sfKeyEnter)) {
            bin->quete = 2;
            bin->dialogue_ace3 += 1;
        }
        sfRenderWindow_drawSprite(bin->Window, bin->ocean, NULL);
        sfRenderWindow_drawSprite(bin->Window, bin->sunny, NULL);
        sfRenderWindow_drawSprite(bin->Window, bin->d_ace3, NULL);
        sfRenderWindow_display(bin->Window);
    }
    bin->evenement = 0;
}

void ace4(struct bin *bin)
{
    bin->evenement = 1;
    while (bin->dialogue_ace4 < 1) {
        sfRenderWindow_pollEvent(bin->Window, &bin->event);
        if (bin->event.type == sfEvtKeyPressed &&
        sfKeyboard_isKeyPressed(sfKeyEnter)) {
            bin->quete = 2;
            bin->dialogue_ace4 += 1;
        }
        sfRenderWindow_drawSprite(bin->Window, bin->ocean, NULL);
        sfRenderWindow_drawSprite(bin->Window, bin->sunny, NULL);
        sfRenderWindow_drawSprite(bin->Window, bin->d_ace4, NULL);
        sfRenderWindow_display(bin->Window);
    }
    bin->evenement = 0;
}

int dialogue_chopper(struct bin *bin)
{
    bin->evenement = 1;
    while (1) {
        sfRenderWindow_pollEvent(bin->island, &bin->event);
        if (bin->event.type == sfEvtKeyPressed &&
        sfKeyboard_isKeyPressed(sfKeyEnter)) {
            bin->colision = sfTexture_createFromFile("img/colision2.png", NULL);
            bin->chop = 2;
            bin->quete = 4;
            bin->screenshot = sfTexture_copyToImage(bin->colision);
            bin->evenement = 0;
            return (0);
        }
        sfRenderWindow_drawSprite(bin->island, bin->dialogue_chopp, NULL);
        sfRenderWindow_display(bin->island);
    }
}

int friendly_function(void)
{
    sfRenderWindow *Window;
    sfRectangleShape *rect = sfRectangleShape_create();
    sfRenderWindow_drawRectangleShape(Window, rect, NULL);
    sfRectangleShape_destroy(rect);
    sfSprite *sprite;
    sfSprite_destroy(sprite);
    sfTexture *texture;
    sfTexture_destroy(texture);
    sfClock *clock = sfClock_create();
    sfClock_destroy(clock);
}
