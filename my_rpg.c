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
        exit(0);
    }
}

int fermer_start(struct bin *bin)
{
    if (bin->event.type == sfEvtClosed) {
        exit (0);
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
        while (sfRenderWindow_pollEvent(bin->Start, &bin->event)) {
            fermer_start(bin);
        }
        bin->mouse = sfMouse_getPosition((const sfWindow *)bin->Start);
        animation_pick(bin, &k);
        sfRenderWindow_display(bin->Start);
    }
    sfRenderWindow_destroy(bin->Start);
}

int recup_log(struct bin *bin)
{
    int fd = open("log.txt", O_RDONLY);
    if (fd == -1) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        exit(EXIT_FAILURE);
    }
    char buffer[10000];
    ssize_t nb_lus = read(fd, buffer, sizeof(buffer) - 1);
    if (nb_lus == -1) {
        printf("Erreur lors de la lecture du fichier.\n");
        close(fd);
        exit(EXIT_FAILURE);
    }
    buffer[nb_lus] = '\0';
    close(fd);
    if (buffer[0] == '0') {
        return (0);
    }
    if (buffer[0] == '1') {
        return (1);
    }
    if (buffer[0] == '2') {
        return (2);
    }
    if (buffer[0] == '3') {
        return (3);
    }
    return (0);
}

int recup_perso(struct bin *bin)
{
    int fd = open("perso.txt", O_RDONLY);
    if (fd == -1) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        exit(EXIT_FAILURE);
    }
    char buffer[10000];
    ssize_t nb_lus = read(fd, buffer, sizeof(buffer) - 1);
    if (nb_lus == -1) {
        printf("Erreur lors de la lecture du fichier.\n");
        close(fd);
        exit(EXIT_FAILURE);
    }
    buffer[nb_lus] = '\0';
    close(fd);
    if (buffer[0] == '1') {
        return (1);
    }
    if (buffer[0] == '2') {
        return (2);
    }
    if (buffer[0] == '3') {
        return (3);
    }
    return (1);
}

void my_putstr(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        write(1, &str[i], 1); i++;
    }
}

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    while (s1[i] != 0 && s2[i] != 0) {
        if (s1[i] != s2[i]) {
            return (s1[i] - s2[i]);
        }
        i++;
    }
    return (0);
}

int main(int ac, char **av)
{
    if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
        my_putstr("Attaque : E/R\nDéplacement personnage : Q/D");
        my_putstr("\nDéplacement bateau : Flèches directionnelles");
        my_putstr("\nIntéragir : F\nPause : Echap\nSkill Tree : T");
        my_putstr("\nInventaire : I\nSkip dialogue : Enter\nMap : Tab\n");
        return (0);
    }
    struct bin bin;
    apply(&bin);
    if (menu_funtion(&bin) == 69) {
        return (0);
    }
    game_function(&bin);
}
