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

int fermer_ile1(struct bin *bin)
{
    if (bin->event.type == sfEvtClosed) {
        sfRenderWindow_close(bin->ILE1);
        sfRenderWindow_close(bin->island);
        sfRenderWindow_close(bin->Window);
    }
    tab2(bin);
    inventory(bin);
    hud_pause(bin);
    skilltree(bin);
}

int fermer_ile(struct bin *bin)
{
    if (bin->event.type == sfEvtClosed) {
        sfRenderWindow_close(bin->island);
        sfRenderWindow_close(bin->Window);
    }
    interractions_ile1(bin);
    tab2(bin);
    inventory(bin);
    hud_pause(bin);
    skilltree(bin);
}

void affichages_ile(struct bin *bin, sfClock *clock, sfClock *gum)
{
    sfSprite_setPosition(bin->perso, bin->deplacements);
    sfRenderWindow_clear(bin->ILE1, sfBlack);
    sfSprite_setPosition(bin->ile, bin->decor);
    sfRenderWindow_drawSprite(bin->ILE1, bin->ile, NULL);
    if (bin->pick == 1) {
        sfSprite_setPosition(bin->HUD_LUFFY, (sfVector2f) {0, -50});
        sfRenderWindow_drawSprite(bin->ILE1, bin->HUD_LUFFY, NULL);
    }if (bin->pick == 2) {
        sfSprite_setPosition(bin->HUD_ZORO, (sfVector2f) {0, -50});
        sfRenderWindow_drawSprite(bin->ILE1, bin->HUD_ZORO, NULL);
    }if (bin->pick == 3) {
        sfSprite_setPosition(bin->HUD_SANJI, (sfVector2f) {0, -50});
        sfRenderWindow_drawSprite(bin->ILE1, bin->HUD_SANJI, NULL);
    }animation_course(bin, clock, gum);
    sfRenderWindow_drawSprite(bin->ILE1, bin->perso, NULL);
    sfSprite_setTextureRect(bin->vie, bin->rect_vie);
    sfSprite_setTextureRect(bin->mana, bin->rect_mana);
    sfRenderWindow_drawSprite(bin->ILE1, bin->vie, NULL);
    sfRenderWindow_drawSprite(bin->ILE1, bin->mana, NULL);
    quetes(bin, bin->ILE1); binds(bin, bin->ILE1);
    sfRenderWindow_display(bin->ILE1);
}

int ilealabasta(struct bin *bin)
{
    bin->deplacements_ile.x = -3000; bin->deplacements_ile.y = -4000;
    bin->island = sfRenderWindow_create(bin->video_mode, "ILE",
    sfClose | sfResize, NULL);
    bin->quete = 3;
    sfClock *clock_d = sfClock_create(); init(bin);
    while (sfRenderWindow_isOpen(bin->island)) {
        if (bin->exit == 69)
            return (69);
        while (sfRenderWindow_pollEvent(bin->island, &bin->event)) {
            fermer_ile(bin);
        }collisions(bin);
        bin->mouse = sfMouse_getPosition((const sfWindow *)bin->island);
        if (bin->evenement == 0) {
            animation_course_ile(bin); droite_ile(bin); gauche_ile(bin);
            bas_ile(bin); haut_ile(bin); no_moovealabasta(bin);
        }
        clock_chopper(bin, clock_d);
        draw_all(bin); hud(*bin, bin->island); draw_other(bin);
        quetes(bin, bin->island); binds(bin, bin->island);
        sfRenderWindow_display(bin->island);
    }
}

int ile1(struct bin *bin)
{
    bin->deplacements.x = 200; bin->deplacements.y = 500;
    sfClock *clock = sfClock_create(); sfClock *gum = sfClock_create();
    sfClock *mana = sfClock_create();
    bin->ILE1 = sfRenderWindow_create(bin->video_mode, "ILE",
    sfClose | sfResize, NULL);
    sfRenderWindow_setFramerateLimit(bin->ILE1, bin->fps);
    while (sfRenderWindow_isOpen(bin->ILE1)) {
        if (bin->exit == 69) {
            return (69);
        }
        while (sfRenderWindow_pollEvent(bin->ILE1, &bin->event)) {
            fermer_ile1(bin);
        }bin->mouse = sfMouse_getPosition((const sfWindow *)bin->ILE1);
        if (bin->event.type != sfEvtKeyPressed) {
            no_moove(bin);
            bin->perso = bin->luffy;
        }deplacement_perso(bin);saut_perso(bin);
        gestion_mana(bin, mana);
        affichages_ile(bin, clock, gum);
    }
}
