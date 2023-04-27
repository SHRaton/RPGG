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

void init(struct bin *bin)
{
    sfRenderWindow_setFramerateLimit(bin->island, bin->fps);
    sfSprite_setScale(bin->map_ile, (sfVector2f) {5, 5});
    sfSprite_setScale(bin->map_dessous, (sfVector2f) {5, 5});
    sfSprite_setScale(bin->press_f, (sfVector2f) {5, 5});
    sfSprite_setScale(bin->choopper_f, (sfVector2f) {5, 5});
    bin->moove = sfClock_create();
}

void applycrash(struct bin *bin)
{
    bin->menu1 = cat("img/menu_play.png");
    bin->menu2 = cat("img/menu_option.png");
    bin->menu3 = cat("img/menu.png");
    bin->luffyfy = cat("img/luffyfy.png");
    bin->zororo = cat("img/zororo.png");
    bin->sanjiji = cat("img/sanjiji.png");
    bin->zorogauche = cat("img/zorogauche.png");
    bin->zororight = cat("img/zororight.png");
    bin->zorobas = cat("img/zorobas.png");
    bin->zorotop = cat("img/zorotop.png");
    bin->zoro_gauche = cat("img/zoro_gauche.png");
    bin->zoro_droite = cat("img/zoro_droite.png");
    bin->luffygauche = cat("img/luffygauche.png");
    bin->luffyright = cat("img/luffyright.png");
    bin->luffybas = cat("img/luffybas.png");
    bin->luffytop = cat("img/luffytop.png");
    bin->luffy_gauche = cat("img/luffy_gauche.png");
    bin->luffy_right = cat("img/luffy_right.png");
    bin->sanjigauche = cat("img/sanjigauche.png");
    bin->sanjiright = cat("img/sanjiright.png");
    bin->drop_croco = cat("img/drop_croco.png");
    bin->drop_enel = cat("img/drop_enel.png");
    bin->drop_akainu = cat("img/drop_akainu.png");
}

void applycrash2(struct bin *bin)
{
    bin->sanjibas = cat("img/sanjibas.png");
    bin->sanjitop = cat("img/sanjitop.png");
    bin->sanji_gauche = cat("img/sanji_gauche.png");
    bin->sanji_droite = cat("img/sanji_droite.png");
    bin->poing_c = cat("img/poing.png");
    bin->zoroautoattack_c = cat("img/zoroautoattack.png");
    bin->sanjiautoattack_c = cat("img/sanjiautoattack.png");
    bin->spell_c = cat("img/spell.png"); bin->zoroz_c = cat("img/zoroz.png");
    bin->zorospecialattack_c = cat("img/zorospecialattack.png");
    bin->sanjispecialattack_c = cat("img/sanjispecialattack.png");
    bin->luffyz_c = cat("img/luffyz.png");
    bin->sanjiz_c = cat("img/sanjiz.png");
    bin->inventaire1_c = cat("img/inventaire1.png");
    bin->ocean1_c = cat("img/ocean1.png");
    bin->winimage = cat("img/winimage.png");
    bin->skilltree_c = cat("img/skilltree.png");
    bin->skilltree1_c = cat("img/skilltree1.png");
    bin->skilltree2_c = cat("img/skilltree2.png");
    bin->skilltree3_c = cat("img/skilltree3.png");
    bin->skilltree4_c = cat("img/skilltree4.png");
}

void applycrash3(struct bin *bin)
{
    bin->pause_c = cat("img/pause.png");
    bin->pause1_c = cat("img/pause1.png");
    bin->pause2_c = cat("img/pause2.png");
    bin->pause3_c = cat("img/pause3.png");
    bin->options_c = cat("img/options.png");
    bin->options2_c = cat("img/options2.png");
    bin->choopper_vide_c = cat("img/choopper_vide.png");
    bin->choopper_f_c = cat("img/choopper_f.png");
    bin->choopper_c = cat("img/choopper.png");
    bin->fightskypea_c = cat("img/fightskypea.png");
    bin->crocodile_auto_droite_c = cat("img/crocodile_auto_droite.png");
    bin->crocodile_auto_gauche_c = cat("img/crocodile_auto_gauche.png");
    bin->crocodile_mort_c = cat("img/crocodile_mort.png");
    bin->inventaire2_c = cat("img/inventaire2.png");
    bin->inventaire3_c = cat("img/inventaire3.png");
    bin->inventaire4_c = cat("img/inventaire4.png");
    bin->map2_c = cat("img/map2.png");
    bin->ocean2_c = cat("img/ocean2.png");
    bin->crocodile_gauche_c = cat("img/crocodile_gauche.png");
    bin->crocodile_droite_c = cat("img/crocodile_droite.png");
    bin->eau = cat("img/fin.jpg");
    bin->luffy_pose = cat("img/luffy_pose.png");
    bin->zoro_pose = cat("img/zoro_pose.png");
    bin->sanji_pose = cat("img/sanji_pose.png");
    bin->loading = cat("img/loading.jpg");
}

void applycrash4(struct bin *bin)
{
    bin->Port_c = cat("img/Port.png"); bin->Clouds = cat("img/cloud.jpg");
    bin->wukong_auto_droite_c = cat("img/wukong_auto_droite.png");
    bin->wukong_auto_gauche_c = cat("img/wukong_auto_droite.png");
    bin->wukong_mort_c = cat("img/wukong_mort.png");
    bin->wukong_gauche_c = cat("img/wukong_gauche.png");
    bin->wukong_droite_c = cat("img/wukong_droite.png");
    bin->wukong_gauchenrv_c = cat("img/wukong_gauchenrv.png");
    bin->wukong_droitenrv_c = cat("img/wukong_droitenrv.png");
    bin->map3_c = cat("img/map3.png");
    bin->ocean3_c = cat("img/ocean3.png");
    bin->akainu_mort = cat("img/akainu_mort.png");
    bin->marineford = cat("img/marineford.png");
    bin->fight_marine_c = cat("img/fightmarine.png");
    bin->press_r = 0;
    bin->d_croco = 0;
    bin->d_enel = 0;
    bin->d_akainu = 0;
    bin->dialogue_ace2 = 0;
    bin->dialogue_ace3 = 0;
    bin->dialogue_ace4 = 0;
    bin->d_ace2 = cat("img/ace2.png");
    bin->d_ace3 = cat("img/ace3.png");
    bin->d_ace4 = cat("img/ace4.png");
    bin->echec = cat("img/deadimage.png");
    bin->Quete1 = cat("img/Quete1.png");
    bin->Quete2 = cat("img/Quete2.png");
    bin->Quete3 = cat("img/Quete3.png");
    bin->Quete4 = cat("img/Quete4.png");
    bin->Quete5 = cat("img/Quete5.png");
    bin->Quete6 = cat("img/Quete6.png"); bin->quete = 0;
    bin->dialogue_croco = cat("img/dialogue3.png");
    bin->dialogue_enel = cat("img/dialogue5.png");
    bin->dialogue_akainu = cat("img/dialogue4.png");
    bin->akainu_auto_droite_c = cat("img/akainu_auto_droite.png");
    bin->akainu_auto_gauche_c = cat("img/akainu_auto_gauche.png");
    bin->akainu_droite_c = cat("img/akainu_droite.png");
    bin->akainu_gauche_c = cat("img/akainu_gauche.png");
    bin->akainu_flamme = cat("img/akainu_flamme.png");
    bin->akainu_sol = cat("img/akainu_sol.png");
    bin->akainu_flamme_top = cat("img/akainu_flamme_top.png");
    bin->rect_flamme.left = 0; bin->rect_flamme.top = 0;
    bin->rect_flamme.width = 75; bin->rect_flamme.height = 98;
    bin->rect_sol.left = 0; bin->rect_sol.top = 0;
    bin->rect_sol.width = 100; bin->rect_sol.height = 100;
    bin->feu = cat("img/feu.png");
    bin->pos_feu.x = 400; bin->pos_feu.y = 300;
    bin->rect_feu.left = 0; bin->rect_feu.top = 0;
    bin->rect_feu.width = 210; bin->rect_feu.height = 100;
    bin->coffre1 = 0;
    bin->coffre2 = 0;
    bin->coffre3 = 0;
    bin->coffre4 = 0;
    bin->coffre5 = 0;
    bin->coffre_berry = cat("img/coffre_berry.png");
    bin->menu4 = cat("img/menu_resume.png");
}
