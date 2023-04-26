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

void fermer_cinematique(struct bin *bin)
{
    if (bin->event.type == sfEvtClosed) {
        exit(0);
    }
}

int cinematique(struct bin *bin)
{
    sfClock *clock = sfClock_create();
    sfClock *clock_zoom = sfClock_create();
    sfSprite *perso;
    if (bin->pick == 1) {
        perso = bin->luffy_pose;
    }
    if (bin->pick == 2) {
        perso = bin->zoro_pose;
    }
    if (bin->pick == 3) {
        perso = bin->sanji_pose;
    }
    sfSprite *credits = cat("img/credits.png");
    sfVector2f zoom = {0.35, 0.35};
    sfVector2f zoom_perso;
    sfVector2f zoom_zoro;
    sfVector2f zoom_sanji;
    if (bin->pick == 1) {
        zoom_perso.x = 0.1; zoom_perso.y = 0.1;
        sfSprite_setOrigin(perso, (sfVector2f) {107, 320});
    }
    if (bin->pick == 2) {
        zoom_zoro.x = 0.1; zoom_zoro.y = 0.1;
        sfSprite_setOrigin(perso, (sfVector2f) {330, 1100});
    }
    if (bin->pick == 3) {
        zoom_sanji.x = 0.1; zoom_sanji.y = 0.1;
        sfSprite_setOrigin(perso, (sfVector2f) {420, 650});
    }
    sfVector2f pos_perso = {1000, 955};
    sfVector2f pos_credits = {500, 1000};
    sfSprite_setOrigin(bin->eau, (sfVector2f) {3250, 2600});
    bin->Cinematique = sfRenderWindow_create(bin->video_mode, "Cinematique",
    sfClose | sfResize, NULL);
    while (sfRenderWindow_isOpen(bin->Cinematique)) {
        while (sfRenderWindow_pollEvent(bin->Cinematique, &bin->event)) {
            fermer_cinematique(bin);
        }
        bin->mouse = sfMouse_getPosition((const sfWindow *)bin->Cinematique);
        if (sfTime_asSeconds(sfClock_getElapsedTime(clock_zoom)) > 0.005) {
            if (zoom.x < 0.7) {
                zoom.x += 0.0001; zoom.y += 0.0001;
                zoom_perso.x += 0.0004; zoom_perso.y += 0.0004;
                zoom_zoro.x += 0.0001; zoom_zoro.y += 0.0001;
                zoom_sanji.x += 0.0002; zoom_sanji.y += 0.0002;
            } else {
                pos_perso.y -= 1;
                pos_credits.y -= 1;
            }
            sfClock_restart(clock_zoom);
        }
        if (sfTime_asSeconds(sfClock_getElapsedTime(clock)) > 53) {
            sfSprite_setScale(bin->winimage, (sfVector2f) {1, 1});
            sfRenderWindow_drawSprite(bin->Cinematique, bin->winimage, NULL);
            bin->mouse = sfMouse_getPosition((const sfWindow *)bin->Cinematique);
            if (bin->event.type == sfEvtMouseButtonPressed &&
            bin->event.mouseButton.button == sfMouseLeft &&
            bin->mouse.x > 0 && bin->mouse.x < 400 &&
            bin->mouse.y > 700 && bin->mouse.y < 850) {
                bin->rect_vie.width = 457; bin->rect_mana.width = 457;
                bin->pos_crocodile.x = 1300; bin->deplacements.x = 200;
                bin->rect_vie_crocodile.width = 457;
                bin->winimage = bin->loading;
                sfSprite_setScale(bin->winimage, (sfVector2f) {0.5, 0.5});
                sfRenderWindow_drawSprite(bin->Cinematique, bin->winimage, NULL);
                sfRenderWindow_display(bin->Cinematique);
                apply(bin);
                sfRenderWindow_close(bin->Cinematique);
                if (menu_funtion(bin) == 69) {
                    return (0);
                }
                game_function(bin);
                return (0);
            }
            if (bin->event.type == sfEvtMouseButtonPressed &&
            bin->event.mouseButton.button == sfMouseLeft &&
            bin->mouse.x > 0 && bin->mouse.x < 400 &&
            bin->mouse.y > 860 && bin->mouse.y < 1010) {
                sfRenderWindow_close(bin->Cinematique);
                sfRenderWindow_close(bin->island);
                sfRenderWindow_close(bin->ILE1);
                sfRenderWindow_close(bin->Boss);
                exit (0);
            }
        } else {
            sfSprite_setScale(bin->eau, zoom);
            if (bin->pick == 1) {
                sfSprite_setScale(perso, zoom_perso);
            }
            if (bin->pick == 2) {
                sfSprite_setScale(perso, zoom_zoro);
            }
            if (bin->pick == 3) {
                sfSprite_setScale(perso, zoom_sanji);
            }
            sfSprite_setPosition(bin->eau, (sfVector2f) {960, 900});
            sfRenderWindow_drawSprite(bin->Cinematique, bin->eau, NULL);
            sfSprite_setPosition(perso, pos_perso);
            sfRenderWindow_drawSprite(bin->Cinematique, perso, NULL);
            sfSprite_setPosition(credits, pos_credits);
            if (zoom.x >= 0.7) {
                sfRenderWindow_drawSprite(bin->Cinematique, credits, NULL);
            }
        }
        sfRenderWindow_display(bin->Cinematique);
    }
    sfRenderWindow_destroy(bin->Cinematique);
}
