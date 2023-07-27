//#include"sauvegarde.h"
#include"config.h"
#include"menu.h"
#include"sauvegarde.h"
void go(int j);
void nouvelle_partie(int Grille[NB_LIGNE][NB_COL],int score,int m_score,char nom[10],M_score tab_score[10]);
void regles_du_jeux();
void choix_sauv(int i,int Grille[NB_LIGNE][NB_COL],int score,char *nom);
void choix(int i,int Grille[][NB_COL],int *score,char *nom);
