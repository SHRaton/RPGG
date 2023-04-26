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

int fermer_ilemarine(struct bin *bin)
{
    if (bin->event.type == sfEvtClosed) {
        exit (0);
    }
    tab2(bin);
    inventory(bin);
    hud_pause(bin);
    skilltree(bin);
}

void autoattackmarine(struct bin *bin)
{
    if ((sfKeyboard_isKeyPressed(sfKeyE) || bin->poing == 1 ) &&
    (bin->rect_mana.width >= 50)) {
        bin->poing = 1;
        if (bin->pick == 1) {
            bin->perso = bin->poing_c;
        }
        if (bin->pick == 2) {
            bin->perso = bin->zoroautoattack_c;
            bin->deplacements.x += 3;
        }
        if (bin->pick == 3) {
            bin->perso = bin->sanjiautoattack_c;
        }
        sfSprite_setScale(bin->perso, (sfVector2f) {3.7, 3.7});
        sfSprite_setTextureRect(bin->vie, bin->rect_vie);
        sfSprite_setTextureRect(bin->vie, bin->rect_mana);
        sfSprite_setTextureRect(bin->perso, bin->frameRectpoing);
    } else {
        bin->frameRectpoing.left = 0; bin->poing = 0;
    }
}

void spell_1marine(struct bin *bin)
{
    if ((sfKeyboard_isKeyPressed(sfKeyR) || bin->gome == 1 ) &&
    (bin->rect_mana.width >= 100) && bin->press_r == 1) {
        bin->gome = 1;
        if (bin->pick == 1) {
            bin->perso = bin->spell_c;
            bin->deplacements.x += 5;
        }if (bin->pick == 2) {
            bin->perso = bin->zorospecialattack_c;
            bin->deplacements.x += 5;
        }if (bin->pick == 3) {
            bin->perso = bin->sanjispecialattack_c;
            bin->deplacements.x += 5;
        }
        sfSprite_setScale(bin->perso, (sfVector2f) {3.7, 3.7});
        sfSprite_setTextureRect(bin->vie, bin->rect_vie);
        sfSprite_setTextureRect(bin->vie, bin->rect_mana);
        sfSprite_setTextureRect(bin->perso, bin->frameRectspell);
    } else {
        bin->frameRectspell.left = 0; bin->gome = 0;
    }
}

void affichages_ilemarine(struct bin *bin, sfClock *clock, sfClock *gum)
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

int ilemarine(struct bin *bin)
{
    bin->ile = bin->fight_marine_c; bin->decor.x = 0; bin->decor.y = 0;
    bin->deplacements.x = 200; bin->deplacements.y = 500;
    sfClock *clock = sfClock_create(); sfClock *gum = sfClock_create();
    sfClock *mana = sfClock_create();
    bin->ILE1 = sfRenderWindow_create(bin->video_mode, "Passage",
    sfClose | sfResize, NULL);
    sfRenderWindow_setFramerateLimit(bin->ILE1, bin->fps);
    while (sfRenderWindow_isOpen(bin->ILE1)) {
        while (sfRenderWindow_pollEvent(bin->ILE1, &bin->event)) {
            fermer_ilemarine(bin);
        }bin->mouse = sfMouse_getPosition((const sfWindow *)bin->ILE1);
        if (bin->event.type != sfEvtKeyPressed) {
            bin->perso = bin->luffy;
        }deplacement_persomarine(bin);saut_perso(bin);
        gestion_mana(bin, mana);
        affichages_ilemarine(bin, clock, gum);
    }sfRenderWindow_destroy(bin->ILE1);
}
