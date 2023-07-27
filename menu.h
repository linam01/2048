#include"config.h"
#include"sauvegarde.h"
#include "jeux.h"

void fond_img();
void go(int j);
void menu_defaite(int Grille[][NB_COL],int score);
void menu();
void menu_m_score(M_score tab_score[10]);
void init();
void nouvelle_partie(int Grille[NB_LIGNE][NB_COL],int score,int m_score,char nom[10],M_score tab_score[10]);
void menu_regles_du_jeux();
void menu_chargement(int Grille[][NB_COL],int score,int m_score,char nom[10],M_score tab_score[10]);
void menu_sauv(int Grille[NB_LIGNE][NB_COL],int score,int m_score,char *nom,M_score tab_score[10]);
void choix_sauv(int i,int Grille[NB_LIGNE][NB_COL],int score,char *nom);
void choix(int i,int Grille[][NB_COL],int *score,char *nom);
