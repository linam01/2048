#include"affichage_jeu.h"
#include"menu.h"

//affiche les element de la fenetre du jeu
void affichage_jeu(int Grille[][NB_COL],char *text,char *score_mlv,char *m_score_mlv,int score,int m_score,Tab_btn tab){
  int i;
  Bouton btn;
  sprintf(score_mlv,"%d \n",score);
  sprintf(m_score_mlv,"%d \n",m_score);
  fond_img();
  MLV_draw_text(380,100, "Joueur", MLV_COLOR_WHITE);
  MLV_draw_text(440,150,text, MLV_COLOR_RED );
  MLV_draw_text(680,100, "Score", MLV_COLOR_WHITE);
  MLV_draw_text(710,150,score_mlv, MLV_COLOR_RED);
  MLV_draw_text(980,100, "Meilleur score", MLV_COLOR_WHITE );
  MLV_draw_text(1100,150,m_score_mlv, MLV_COLOR_RED);
  if(victoire(Grille)==1){
    MLV_draw_text(WINDOW_LARGEUR/6+200,WINDOW_HAUTEUR-350, "Vous avez atteint 2048 !", MLV_COLOR_WHITE );

  }
  for(i=0;i<tab.nb_btn;i++){
    btn=tab.tab_btn[i];
    dessiner_bouton(&btn);
  }
  affiche_matrice_MLV(Grille);
}

//MLV color gerant la couleur des differentes tuiles 
MLV_Color color(int Grille[][NB_COL],int i,int j){
  switch(Grille[i][j]){
  case 0 :
    return MLV_COLOR_WHITE;       
  case 2 :
    return  MLV_rgba(205,51,51,255);
  case 4 : 
    return MLV_rgba(255,140,105,255);     
  case 8 :
    return  MLV_rgba(255,160,122,255);
  case 16 :
    return MLV_rgba(255,165,0,255);     
  case 32 :
    return MLV_rgba(255,127,0,255);
  case 64 :
    return MLV_rgba(255,114,86,255);      
  case 128 : 
    return MLV_rgba(255,99,71,255);
  case 256 :
    return MLV_rgba(255,69,0,255);
  case 1024 :
    return MLV_rgba(238,64,0,255);
  case 2048 :
    return MLV_rgba(255,0,0,255);
  case 4096 :
    return MLV_rgba(255,20,147,255);
  case 8192 :
    return  MLV_rgba(255,110,180,255);
  case 16384 :
    return  MLV_rgba(255,181,197,255);
  case 32768 :
    return MLV_rgba(255,174,185,255);
  default :
    return MLV_rgba(255,130,171,255);
  }
}

//affiche la grille mlv
void affiche_matrice_MLV(int Grille[][NB_COL]){
  int i, j,taille_ligne,taille_colonne;
  char nombre[10];
  for (i=0; i<NB_LIGNE; i++){
    for (j=0; j<NB_COL; j++){
      taille_ligne=i*103+250;
      taille_colonne=j*103+550;
      sprintf(nombre,"%d",Grille[i][j]);
      if(Grille[i][j]!=0){
	MLV_draw_text_box(taille_colonne,
			  taille_ligne,
			  100,
			  100,
			  nombre,
			  35,
			  MLV_COLOR_BLACK,
			  MLV_COLOR_BLACK,
			  color(Grille,i,j),
			  MLV_TEXT_CENTER,
			  MLV_HORIZONTAL_CENTER,
			  MLV_VERTICAL_CENTER );
      }
      else{
	MLV_draw_text_box(taille_colonne,
			  taille_ligne,
			  100,
			  100,
			  "  ",
			  35,
			  MLV_COLOR_BLACK,
			  MLV_COLOR_BLACK,
			  color(Grille,i,j),
			  MLV_TEXT_CENTER,
			  MLV_HORIZONTAL_CENTER,
			  MLV_VERTICAL_CENTER );
      }
      MLV_update_window();    
    }
  }
}

