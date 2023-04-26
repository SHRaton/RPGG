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

sfSprite *cat(char *path)
{
    sfTexture *texture = sfTexture_createFromFile(path, NULL);
    sfSprite *sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    return (sprite);
}

char *reverse(char *str)
{
    char tmp, *src, *dst;
    size_t len;
    if (str != NULL) {
        len = my_strlen(str);
    }
    if (len > 1 && str != NULL) {
        src = str;
        dst = src + len - 1;
        while (src < dst) {
            tmp = *src;
            *src++ = *dst;
            *dst-- = tmp;
        }
    }
    return str;
}

char *inttostr(int n, char s[])
{
    int i = 0, sign = n;
    if (sign < 0)
        n = -n;
    do {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
    return s;
}

int my_strlen(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
    i = i + 1;
    }
    return (i);
}

int my_getnbr(char const *str)
{
    long number = 0;
    int neg = 1;
    int i = 0;

    for (i; str[i] != '\0'; i++) {
        if (str[i] == 45)
            neg = neg * (-1);
        if ((str[i] >= 48 && str[i] <= 57) &&
            (str[i + 1] < 48 || str[i + 1] > 57))
            return ((number * 10 + (str[i] - 48)) * neg);
        if (str[i] >= 48 && str[i] <= 57 && str[i] != 45)
            number = number * 10 + (str[i] - 48);
        number = number * neg;
        if (number < -2147483648 || number > 2147483647)
            return (0);
        number = number * neg;
    }
    return (number * neg);
}
