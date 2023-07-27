#include"fonction.h"
#include "config.h"

void sauvegarde_m_score(M_score tab_score[10]);
void chargement_m_score(M_score tab_score[10]);
void sauvegarde_partie(int tab[][NB_COL],int score,char *nom,char x);
void chargement_partie(int tab[][NB_COL],int *score,char *nom,char x);
