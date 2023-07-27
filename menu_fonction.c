#include"menu_fonction.h"
#include"bouton.h"

void nouvelle_partie(int Grille[NB_LIGNE][NB_COL],int score,int m_score,char nom[10],M_score tab_score[10]){
  MLV_clear_window( MLV_COLOR_BLACK);
  fond_img();
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
  m_score=tab_score[0].m_score;
  jeux(Grille,score,m_score,nom);
}

void regles_du_jeux(){
  Bouton btn;
  Tab_btn tab;
  tab.nb_btn =0;
  btn=creer_bouton(WINDOW_LARGEUR/4,WINDOW_HAUTEUR/6+600,500,100,"Menu",&tab,menu);
  MLV_clear_window( MLV_COLOR_BLACK);
  MLV_draw_text(0,50, "Voici les règles de cejeu : dans le tableau de 4 cases sur 4, des carreaux numérotés à partir de 2 apparaissent.", MLV_COLOR_WHITE );
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


int menu_chargement(int Grille[][NB_COL],int score,int m_score,char nom[10]){
  Bouton btn,btn4,btn2,btn3;
  Tab_btn tab;
  MLV_Event event = MLV_NONE;
  MLV_Button_state state;
  int i=-1,x,y;
  tab.nb_btn=0;
  MLV_clear_window(MLV_COLOR_BLACK);
  btn=creer_bouton(WINDOW_LARGEUR/3,WINDOW_HAUTEUR/6,300,100,"Partie 1",&tab,NULL);
  btn2=creer_bouton(WINDOW_LARGEUR/3,WINDOW_HAUTEUR/6+150,300,100,"Partie 2",&tab,NULL);
  btn3=creer_bouton(WINDOW_LARGEUR/3,WINDOW_HAUTEUR/6+300,300,100,"Partie 3",&tab,NULL);
  btn4=creer_bouton(WINDOW_LARGEUR/3,WINDOW_HAUTEUR/6+450,300,100,"Partie 4",&tab,NULL);
  dessiner_bouton(&btn);
  dessiner_bouton(&btn2);
  dessiner_bouton(&btn3);
  dessiner_bouton(&btn4);
  MLV_actualise_window();
  
  while(i>tab.nb_btn || i<0){
    event =MLV_get_event(NULL,NULL,NULL,NULL,NULL,&x,&y,NULL,&state);
    if(event==MLV_MOUSE_BUTTON){ 
      if (state == MLV_PRESSED){	
	i=clicke(x,y,tab);
	printf("i = %d \n",i);
      }
    }
  }
  choix(i,Grille,&score,nom);
  jeux(Grille,score,m_score,nom);
}

