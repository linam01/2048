#include <MLV/MLV_all.h>
#include"config.h"

typedef struct M_score{
  char nom[10];
  int m_score;
}M_score;

void initialiseGrille(int Grille[][NB_COL]);
void afficheGrille(int Grille[][NB_COL]);
int debut_jeux(int Grille[][NB_COL]);
void aleatoire(int Grille[][NB_COL]);
void copierGrille(int Grille[][NB_COL],int Grille_tmp[][NB_COL]);
int comparaison(int Grille[][NB_COL],int Grille_tmp[][NB_COL]);

void droite(int Grille[][NB_COL]);
void gauche(int Grille[][NB_COL]);
void haut(int Grille[][NB_COL]);
void bas(int Grille[][NB_COL]);

void f_direction(int Grille[][NB_COL],MLV_Keyboard_button direction);
void addition(int tab[][NB_COL],MLV_Keyboard_button direction,int *somme,int *m_score);

int deplace_ligne(int Grille[][NB_COL]);
int deplace_colonne(int Grille[][NB_COL]);
int  case_vide(int Grille[][NB_COL]);

int victoire(int Grille[][NB_COL]);
int defaite(int Grille[][NB_COL]);

void score(int *somme,int *m_score,int tab[][NB_COL],int i,int j);
void meilleur_score(M_score tab_m_score[10],int scr,char nom_j[10]);
