#include"menu.h"
#include"affichage_jeu.h"

//boucle du jeu
void jeux(int Grille[NB_LIGNE][NB_COL],int score,int m_score,char *nom,M_score tab_score[10]){
  MLV_Event event = MLV_NONE;
  MLV_Button_state state;
  MLV_Keyboard_button sym;
  int x,y,Grille_tmp[NB_LIGNE][NB_COL];
  char m_score_mlv[20],score_mlv[20];
  Bouton btn,btn2,btn3;
  Tab_btn tab;
  tab.nb_btn=0;
  //crée et dessine les bouton du jeux
  btn=creer_bouton(WINDOW_LARGEUR/6,WINDOW_HAUTEUR/6+600,300,100,"Menu",&tab,menu);
  btn2=creer_bouton(WINDOW_LARGEUR/6+620,WINDOW_HAUTEUR/6+600,300,100,"Quitter",&tab,quitter);
  btn3=creer_bouton(WINDOW_LARGEUR/6+310,WINDOW_HAUTEUR/6+600,300,100,"Sauvegarder",&tab,NULL);
  dessiner_bouton(&btn);
  dessiner_bouton(&btn2);
  dessiner_bouton(&btn3);
  fond_img();
  affichage_jeu(Grille,nom,score_mlv,m_score_mlv,score,m_score,tab);
  MLV_actualise_window();
  //boucle de jeux
  while(defaite(Grille)==1){
    event =MLV_get_event(&sym,NULL,NULL,NULL,NULL,&x,&y,NULL,&state);
    switch(event){
      //evenement du clavier
    case MLV_KEY :
      if(state==MLV_PRESSED){
	copierGrille(Grille,Grille_tmp);
	f_direction(Grille,sym);
	addition(Grille,sym,&score,&m_score);
      	if(comparaison(Grille,Grille_tmp)==0){
	  aleatoire(Grille);
	}
	affichage_jeu(Grille,nom,score_mlv,m_score_mlv,score,m_score,tab);;
      }
      break;
      //evenment de la souris
    case MLV_MOUSE_BUTTON :
      meilleur_score(tab_score,score,nom);
      sauvegarde_m_score(tab_score);
      if (state == MLV_PRESSED){	
	clicke(x,y,tab);
      }
      else if(x >= tab.tab_btn[2].x && y >= tab.tab_btn[2].y &&(x<=tab.tab_btn[2].x +tab.tab_btn[2].largeur) &&(y <=tab.tab_btn[2].y + tab.tab_btn[2].hauteur)){
	menu_sauv(Grille,score,m_score,nom,tab_score);
      }
      break;
    default:
      break;
    } 
  }
  //sauvegarde des meilleur score
  meilleur_score(tab_score,score,nom);
  menu_defaite(Grille,score);
}

//quiter le programme
void quitter(int j){
  exit(0);
}
