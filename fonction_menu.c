#include"fonction_menu.h"
#include"jeux.h"
#include"bouton.h"


void go(int j){
  M_score tab_score[10];
  int Grille[NB_LIGNE][NB_COL];
  int score=0;
  int m_score=0;
  char nom[10];
  chargement_m_score(tab_score);
  MLV_clear_window(MLV_COLOR_BLACK);
  switch(j){
  case 0:
    nouvelle_partie(Grille,score,m_score,nom,tab_score);
    break;
  case 1:
    menu_chargement(Grille,score,m_score,nom,tab_score);
    break;
  case 2:
    regles_du_jeux();
    break;
  case 3:
    menu_m_score(tab_score);
    break;
  case 4:
    exit(0);
    break;
  }
}

//initialisation d'une nouvelle partie
void nouvelle_partie(int Grille[NB_LIGNE][NB_COL],int score,int m_score,char nom[10],M_score tab_score[10]){
  MLV_clear_window( MLV_COLOR_BLACK);
  fond_img();
  //demande le nom du joueur
  MLV_wait_input_box(
		     WINDOW_LARGEUR/6,
		     WINDOW_HAUTEUR/3,
		     1000,
		     200,
		     MLV_rgba(0,0,0,MLV_ALPHA_TRANSPARENT),
		     MLV_COLOR_WHITE,
		     MLV_COLOR_BLACK,
		     "Nom du joueur : ",
		     &nom);
  MLV_actualise_window();
  initialiseGrille(Grille);
  aleatoire(Grille);
  m_score=tab_score[0].m_score; // recupere le meilleur score dans le tableau
  jeux(Grille,score,m_score,nom,tab_score);
}

//affiche les regle du jeux
void regles_du_jeux(){
  Bouton btn;
  Tab_btn tab;
  tab.nb_btn =0;
  btn=creer_bouton(WINDOW_LARGEUR/4,WINDOW_HAUTEUR/6+600,500,100,"Menu",&tab,menu);
  MLV_clear_window( MLV_COLOR_BLACK);
  MLV_draw_text(0,50, "Voici les règles de ce jeu : dans le tableau de 4 cases sur 4, des carreaux numérotés à partir de 2 apparaissent.", MLV_COLOR_WHITE );
  MLV_draw_text(0,100, "Il faut ensuite glisser ces éléments avec les flèches du clavier, afin que deux carreaux portant le même montant se percutent et", MLV_COLOR_WHITE );
  MLV_draw_text(0,150, "fusionnent en un, dont le montant est égal à la somme des deux précédents.", MLV_COLOR_WHITE );
  MLV_draw_text(0,200, "2+2=4, 4+4=8, 8+8=16, 16+16=32... jusqu'à atteindre le but ultime, le nombre 2048 dans une des tuiles.", MLV_COLOR_WHITE );
  dessiner_bouton(&btn);
  event2(tab);
  MLV_actualise_window();
}
void choix(int i,int Grille[][NB_COL],int *score,char *nom){
  switch(i){
  case 0:
    chargement_partie(Grille,score,nom,'1');
    break;
  case 1:
    chargement_partie(Grille,score,nom,'2');
    break;
  case 2:
    chargement_partie(Grille,score,nom,'3');
    break;
  case 3:
    chargement_partie(Grille,score,nom,'4');
    break;
  }
}



void choix_sauv(int i,int Grille[NB_LIGNE][NB_COL],int score,char *nom){
  switch(i){
  case 0 :
    sauvegarde_partie(Grille,score,nom,'1');
    break;
  case 1 :
    sauvegarde_partie(Grille,score,nom,'2');
    break;
  case 2 :
    sauvegarde_partie(Grille,score,nom,'3');
    break;
 case 3 :
    sauvegarde_partie(Grille,score,nom,'4');
    break;
  }
}
