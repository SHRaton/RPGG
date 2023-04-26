/*
** EPITECH PROJECT, 2023
** my
** File description:
** my
*/

#ifndef MY_A_
    #define MY_A_
    #include <unistd.h>
    #include <stddef.h>
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/System.h>

    struct bin {
        sfEvent event;
        sfRenderWindow *Menu;
        sfRenderWindow *Option;
        sfRenderWindow *Window;
        sfRenderWindow *Start;
        sfRenderWindow *ILE1;
        sfRenderWindow *island;
        sfRenderWindow *Boss;
        sfRenderWindow *Cinematique;
        sfSprite *ocean;
        sfSprite *HUD;
        sfSprite *HUD_LUFFY;
        sfSprite *HUD_ZORO;
        sfSprite *HUD_SANJI;
        sfSprite *HOVER_LUFFY;
        sfSprite *HOVER_ZORO;
        sfSprite *HOVER_SANJI;
        sfSprite *choose;
        sfSprite *sunny;
        sfSprite *ile;
        sfSprite *pick_champ;
        sfSprite *pick_luffy;
        sfSprite *pick_zoro;
        sfSprite *pick_sanji;
        sfSprite *luffy;
        sfSprite *perso;
        sfSprite *menu;
        sfSprite *options;
        sfSprite *salle_boss;
        sfSprite *carte;
        sfVector2f pos_ocean;
        sfVector2f reverse;
        sfVector2f centre_sunny;
        int coo_x;
        int coo_y;
        sfVideoMode video_mode;
        float elapsed;
        float frameDuration;
        sfIntRect frameRect;
        sfVector2i mouse;
        sfClock* clock;
        int textureWidth;
        int pick;
        int border_bug;
        sfVector2f deplacements;
        sfVector2f deplacements_ile;
        sfVector2f deplacement_chopper;
        sfVector2f decor;
        int jump;
        sfIntRect frameRectpoing;
        sfIntRect frameRectspell;
        sfIntRect frameRectdroite;
        sfIntRect frameRectgauche;
        float frameDuree;
        float elipse;
        float gumgum;
        int texturewidth;
        sfClock* clock_course;
        sfClock *clock_poing;
        int cam;
        int poing;
        int gome;
        sfSoundBuffer* bouin;
        sfSound* sound;
        int evenement;
        sfSprite *dialogue;
        int dialogue_coffre;
        int tab;
        sfSprite *vie;
        sfSprite *mana;
        sfIntRect rect_vie;
        sfIntRect rect_mana;
        sfIntRect rect_chopper;
        sfIntRect rect_vie_crocodile;
        sfSprite *vie_crocodile;
        int coffre_pris;
        sfSprite *map_ile;
        sfSprite *map_dessous;
        sfSprite *press_f;
        sfSprite *chopper;
        sfSprite *choopper_f;
        int f;
        sfSprite *inventaire;
        int bind_f;
        int chopper_f;
        sfSprite *dialogue_chopp;
        sfSprite *skill_tree;
        int t;
        sfClock *moove;
        sfColor couleur;
        sfImage *screenshot;
        sfTexture *colision;
        int x;
        int y;
        sfSprite *crocodile;
        sfVector2f pos_crocodile;
        sfClock *moove_crocodile;
        int in_range;
        int mort;
        sfIntRect rect_auto_croco;
        sfSprite *auto_crocodile;
        sfClock *clock_auto_croco;
        int attack;
        int direction_attack;
        int decale;
        int touche;
        sfSprite *berry;
        int chop;
        int nb_ile;
        sfText *berrys;
        char *compteur_berry;
        int nb_berry;
        sfText *text_vie;
        int stat_vie;
        char *compteur_vie;
        sfText *text_force;
        int stat_force;
        char *compteur_force;
        sfText *text_mana;
        int stat_mana;
        char *compteur_mana;
        sfText *text_special;
        int stat_special;
        char *compteur_special;
        sfFont* font;
        int exit;
        int fps;
        sfSprite *pause;
        int bind_escape;
        int avancement;
        char *save;
        int opt;
        sfRectangleShape *volume;
        sfVector2f size_volume;
        int nb_attack;
        int compt_attack;
        sfSprite *wukong_boule;
        sfIntRect rect_boule;
        sfIntRect rect_boule2;
        sfClock *clock_boule;
        sfVector2f pos_boule;
        sfVector2f pos_boule2;
        sfSprite *menu1;
        sfSprite *menu2;
        sfSprite *menu3;
        sfSprite *luffyfy;
        sfSprite *zororo;
        sfSprite *sanjiji;
        sfSprite *zorogauche;
        sfSprite *zororight;
        sfSprite *zorobas;
        sfSprite *zorotop;
        sfSprite *zoro_gauche;
        sfSprite *zoro_droite;
        sfSprite *zoro_bas;
        sfSprite *zoro_haut;
        sfSprite *luffygauche;
        sfSprite *luffyright;
        sfSprite *luffybas;
        sfSprite *luffytop;
        sfSprite *luffy_gauche;
        sfSprite *luffy_right;
        sfSprite *luffy_bas;
        sfSprite *luffy_haut;
        sfSprite *sanjigauche;
        sfSprite *sanjiright;
        sfSprite *sanjibas;
        sfSprite *sanjitop;
        sfSprite *sanji_gauche;
        sfSprite *sanji_droite;
        sfSprite *sanji_bas;
        sfSprite *sanji_haut;

        sfSprite *poing_c;
        sfSprite *zoroautoattack_c;
        sfSprite *sanjiautoattack_c;
        sfSprite *spell_c;
        sfSprite *zorospecialattack_c;
        sfSprite *sanjispecialattack_c;
        sfSprite *luffyz_c;
        sfSprite *zoroz_c;
        sfSprite *sanjiz_c;
        sfSprite *inventaire1_c;
        sfSprite *ocean1_c;
        sfSprite *skilltree_c;
        sfSprite *skilltree1_c;
        sfSprite *skilltree2_c;
        sfSprite *skilltree3_c;
        sfSprite *skilltree4_c;
        sfSprite *pause_c;
        sfSprite *pause1_c;
        sfSprite *pause2_c;
        sfSprite *pause3_c;
        sfSprite *options_c;
        sfSprite *options2_c;
        sfSprite *choopper_vide_c;
        sfSprite *choopper_f_c;
        sfSprite *choopper_c;
        sfSprite *fightskypea_c;
        sfSprite *crocodile_auto_droite_c;
        sfSprite *crocodile_auto_gauche_c;
        sfSprite *crocodile_mort_c;
        sfSprite *inventaire2_c;
        sfSprite *inventaire3_c;
        sfSprite *map2_c;
        sfSprite *map3_c;
        sfSprite *ocean2_c;
        sfSprite *ocean3_c;
        sfSprite *crocodile_droite_c;
        sfSprite *crocodile_gauche_c;
        sfSprite *Port_c;
        sfSprite *Clouds;
        sfSprite *wukong_auto_gauche_c;
        sfSprite *wukong_auto_droite_c;
        sfSprite *wukong_mort_c;
        sfSprite *wukong_gauche_c;
        sfSprite *wukong_droite_c;
        sfSprite *wukong_gauchenrv_c;
        sfSprite *wukong_droitenrv_c;
        sfSprite *akainu_auto_droite_c;
        sfSprite *akainu_auto_gauche_c;
        sfSprite *akainu_droite_c;
        sfSprite *akainu_gauche_c;
        sfSprite *akainu_flamme;
        sfSprite *akainu_flamme_top;
        sfIntRect rect_flamme;
        sfSprite *akainu_sol;
        sfIntRect rect_sol;
        sfClock *clock_sol;
        sfClock *clock_feu;
        int lance_feu;
        sfSprite *feu;
        sfVector2f pos_feu;
        sfIntRect rect_feu;

        sfRenderWindow *gameover;
        sfSprite *echec;
        sfClock *clock_lance_feu;
        sfClock *clock_anim_feu;
        sfClock *clock_akainu;
        int feu_fini;
        sfSprite *ocean4_c;
        sfSprite *map4_c;
        sfSprite *inventaire4_c;
        int d_croco;
        int d_enel;
        int d_akainu;

        sfSprite *Quete1;
        sfSprite *Quete2;
        sfSprite *Quete3;
        sfSprite *Quete4;
        sfSprite *Quete5;
        sfSprite *Quete6;
        int quete;
        sfSprite *dialogue_croco;
        sfSprite *dialogue_enel;
        sfSprite *dialogue_akainu;

        sfSprite *winimage;
        sfSprite *eau;
        sfSprite *luffy_pose;
        sfSprite *zoro_pose;
        sfSprite *sanji_pose;
    };

    void quetes(struct bin *bin, sfRenderWindow *Window);
    void applycrash(struct bin *bin);
    void applycrash2(struct bin *bin);
    void applycrash3(struct bin *bin);
    void applycrash4(struct bin *bin);
    int game_over_croco(struct bin *bin);
    int game_over_enel(struct bin *bin);
    int game_over_akainu(struct bin *bin);
    int cinematique(struct bin *bin);

    void no_moove(struct bin *bin);
    void no_moovealabasta(struct bin *bin);
    void affichages_ile(struct bin *bin, sfClock *clock, sfClock *gum);
    int boss_skypea(struct bin *bin);
    void auto_crocoskypea(struct bin *bin);
    void clock_deplacements_crocoskypea(struct bin *bin);
    void ia_crocoskypea(struct bin *bin);
    void display_and_manaskypea(struct bin *bin, sfClock *clock,
    sfClock *mana, sfClock *gum);
    void fin_specialskypea(struct bin *bin);
    void fin_attack_crocoskypea(struct bin *bin);
    void clock_croco_tapeskypea(struct bin *bin);
    void droite_gauche_crocoskypea(struct bin *bin);
    int fermer_bossskypea(struct bin *bin);
    int affichage_bossskypea(struct bin *bin);
    void affichages_ile_boss2skypea(struct bin *bin);
    void affichages_ile_bossskypea(struct bin *bin,
    sfClock *clock, sfClock *gum);
    int animation_course_bossskypea(struct bin *bin,
    sfClock *clock, sfClock *gum);
    void init(struct bin *bin);
    int saut_perso_bossskypea(struct bin *bin);
    void moove_right_bossskypea(struct bin *bin);
    void set_hudskypea(struct bin *bin);
    void right_bossskypea(struct bin *bin);
    void left_bossskypea(struct bin *bin);
    void autoattack_bossskypea(struct bin *bin);
    void spell_1_bossskypea(struct bin *bin);
    int deplacement_perso_bossskypea(struct bin *bin);
    int fermer_option(struct bin *bin, sfRenderWindow *Window);
    int my_strlen(char const *str);
    int hud_pause(struct bin *bin);
    int droite(struct bin *bin);
    int gauche(struct bin *bin);
    int haut(struct bin *bin);
    int bas(struct bin *bin);
    int iles(struct bin *bin);
    void droite_gauche_croco(struct bin *bin);
    char *inttostr(int n, char s[]);
    void draw_all(struct bin *bin);
    void clock_chopper(struct bin *bin, sfClock *clock_d);
    void draw_other(struct bin *bin);
    void init(struct bin *bin);
    int deplacement_perso(struct bin *bin);
    int saut_perso(struct bin *bin);
    int collisions(struct bin *bin);
    int saut_perso_boss(struct bin *bin);
    void moove_right_boss(struct bin *bin);
    void set_hud(struct bin *bin);
    int deplacement_perso_boss(struct bin *bin);
    int gestion_mana(struct bin *bin, sfClock *mana);
    void stop_obstacle(struct bin *bin);
    int droite_ile(struct bin *bin);
    int gauche_ile(struct bin *bin);
    int bas_ile(struct bin *bin);
    int haut_ile(struct bin *bin);
    int tab2(struct bin *bin);
    void clock_animations_deplacements_attack(struct bin *bin);
    int saut_perso(struct bin *bin);
    void binds(struct bin *bin, sfRenderWindow *Window);
    int tab(struct bin *bin);
    int animation_course_ile(struct bin *bin);
    int skilltree(struct bin *bin);
    int inventory(struct bin *bin);
    int dialogue_chopper(struct bin *bin);
    int menu_funtion(struct bin *bin);
    int boss_funtion(struct bin *bin);
    int animation_pick(struct bin *bin, int *k);
    sfSprite *cat(char *path);
    int ilealabasta(struct bin *bin);
    int ileskypea(struct bin *bin);
    int ilemarine(struct bin *bin);
    int fermer_ile(struct bin *bin);
    int game_function(struct bin *bin);
    int directions(struct bin *bin);
    int fermer(struct bin *bin);
    void apply(struct bin *bin);
    void apply2(struct bin *bin);
    void apply3(struct bin *bin);
    void apply4(struct bin *bin);
    void apply5(struct bin *bin);
    void apply6(struct bin *bin);
    void apply7(struct bin *bin);
    void apply8(struct bin *bin);
    void apply9(struct bin *bin);
    int boss_function(struct bin *bin);
    void diag_hg(struct bin *bin);
    void diag_hd(struct bin *bin);
    void diag_bg(struct bin *bin);
    void diag_bd(struct bin *bin);
    int ile1(struct bin *bin);
    int options_funtion(struct bin *bin, sfRenderWindow *Window);
    int start_funtion(struct bin *bin);
    int fermer_boss(struct bin *bin);
    void coffre(struct bin *bin);
    int affichage_boss(struct bin *bin);
    void affichages_ile_boss2(struct bin *bin);
    void fin_special(struct bin *bin);
    void clock_croco_tape(struct bin *bin);
    void affichages_ile_boss(struct bin *bin, sfClock *clock, sfClock *gum);
    int animation_course_boss(struct bin *bin, sfClock *clock, sfClock *gum);
    int deplacement_perso(struct bin *bin);
    int animation_course(struct bin *bin, sfClock *clock, sfClock *gum);
    void spell_1(struct bin *bin);
    void autoattack(struct bin *bin);
    void right(struct bin *bin);
    void left(struct bin *bin);
    void hud(struct bin bin, sfRenderWindow *Window);
    void interractions_ile1(struct bin *bin);
    void spell_1skypea(struct bin *bin);
    void autoattackskypea(struct bin *bin);
    int deplacement_persoskypea(struct bin *bin);
    void press_tt(struct bin *bin, sfRenderWindow *Window);
    int press_ttt(struct bin *bin, sfRenderWindow *Window);
    int press_tttt(struct bin *bin, sfRenderWindow *Window);
    int press_ttttt(struct bin *bin, sfRenderWindow *Window);
    void spell_1marine(struct bin *bin);
    void autoattackmarine(struct bin *bin);
    int deplacement_persomarine(struct bin *bin);
    int ilemarine(struct bin *bin);
    int saut_perso_bossmarine(struct bin *bin);
    void moove_right_bossmarine(struct bin *bin);
    void set_hudmarine(struct bin *bin);
    void right_bossmarine(struct bin *bin);
    void left_bossmarine(struct bin *bin);
    void autoattack_bossmarine(struct bin *bin);
    void spell_1_bossmarine(struct bin *bin);
    int deplacement_perso_bossmarine(struct bin *bin);
    int boss_marine(struct bin *bin);
    void auto_crocomarine(struct bin *bin);
    void clock_deplacements_crocomarine(struct bin *bin);
    void ia_crocomarine(struct bin *bin);
    void display_and_manamarine(struct bin *bin, sfClock *clock,
    sfClock *mana, sfClock *gum);
    void fin_specialmarine(struct bin *bin);
    void fin_attack_crocomarine(struct bin *bin);
    void clock_croco_tapemarine(struct bin *bin);
    void droite_gauche_crocomarine(struct bin *bin);
    int fermer_bossmarine(struct bin *bin);
    int affichage_bossmarine(struct bin *bin);
    void affichages_ile_bossmarine2(struct bin *bin);
    void affichages_ile_bossmarine(struct bin *bin,
    sfClock *clock, sfClock *gum);
    int animation_course_bossmarine(struct bin *bin,
    sfClock *clock, sfClock *gum);

#endif /* !MY_A_ */
