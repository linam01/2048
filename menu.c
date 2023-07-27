#include"menu.h"
#include"jeux.h"
#include"affichage_jeu.h"

//initialisation de la fenetre mlv
void init(){
  MLV_create_window_with_default_font("beginner -2 -2048","2048",
				      WINDOW_LARGEUR,
				      WINDOW_HAUTEUR,
				      "zorque.regular.otf",
				      40);
  fond_img();
  MLV_actualise_window();
  menu();
  MLV_free_window();
}

//initalisation du fond du jeu et menu
void fond_img(){
  MLV_Image *image= MLV_load_image("pexels-gradienta-6985265.jpg");
  int image_width, image_height;
  MLV_resize_image_with_proportions(image,WINDOW_LARGEUR,WINDOW_HAUTEUR);
  MLV_get_image_size( image, &image_width, &image_height);
  MLV_change_window_size( image_width, image_height );
  MLV_draw_image(image,0,0);
}

//fonction du menu d'entrée
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
    menu_regles_du_jeux();
    break;
  case 3:
    menu_m_score(tab_score);
    break;
  case 4:
    exit(0);
    break;
  }
}

//menu affiche le tableau des score
void menu_m_score(M_score tab_score[10]){
  MLV_clear_window(MLV_COLOR_BLACK);
  Tab_btn tab;
  Bouton btn;
  char m_score_mlv[10];
  int i;
  tab.nb_btn=0;
  btn=creer_bouton(WINDOW_LARGEUR/4+30,WINDOW_HAUTEUR/6+600,500,100,"MENU",&tab,menu);
  for(i=0;i<10;i++){
    sprintf(m_score_mlv,"%d",tab_score[i].m_score);
    MLV_draw_text(WINDOW_LARGEUR/4+70,i*70+50,tab_score[i].nom,MLV_COLOR_WHITE);
    MLV_draw_text(WINDOW_LARGEUR/4+470,i*70+50,m_score_mlv,MLV_COLOR_WHITE);
  }
  dessiner_bouton(&btn);
  MLV_actualise_window();
  event2(tab);
}

//menu qui affiche la defaite
void menu_defaite(int Grille[][NB_COL],int score){
  Bouton btn;
  Tab_btn tab;
  char score_mlv[20];
  tab.nb_btn =0;
  MLV_clear_window(MLV_COLOR_BLACK);
  fond_img();
  affiche_matrice_MLV(Grille);
  sprintf(score_mlv,"%d \n",score);
  MLV_draw_text(680,100,"Score", MLV_COLOR_WHITE);
  MLV_draw_text(710,150,score_mlv, MLV_COLOR_RED);
  MLV_draw_text(WINDOW_LARGEUR/6+250,WINDOW_HAUTEUR-350, "Vous avez perdu !",MLV_COLOR_RED);
  btn=creer_bouton(WINDOW_LARGEUR/4+30,WINDOW_HAUTEUR/6+600,500,100,"MENU",&tab,menu);
  dessiner_bouton(&btn);
  MLV_actualise_window();
  event2(tab);
}

//menu d'entrrée
void menu(){
  MLV_clear_window(MLV_COLOR_BLACK);
  fond_img();
  Bouton btn,btn2,btn3,btn4,btn5;
  Tab_btn tab;
  tab.nb_btn =0;
  btn  = creer_bouton(WINDOW_LARGEUR/4+50,WINDOW_HAUTEUR/6,500,100,"JOUER",&tab,go); 
  btn2 = creer_bouton(WINDOW_LARGEUR/4+50,WINDOW_HAUTEUR/6+150,500,100,"CONTINUER",&tab,go);
  btn3 = creer_bouton(WINDOW_LARGEUR/4+50,WINDOW_HAUTEUR/6+300,500,100,"INSTRUCTION",&tab,go);
  btn4 = creer_bouton(WINDOW_LARGEUR/4+50,WINDOW_HAUTEUR/6+450,500,100,"MEILLEUR SCORE",&tab,go);
  btn5 = creer_bouton(WINDOW_LARGEUR/4+50,WINDOW_HAUTEUR/6+600,500,100,"QUITTER",&tab,go);
  dessiner_bouton(&btn);
  dessiner_bouton(&btn2);
  dessiner_bouton(&btn3);
  dessiner_bouton(&btn4);
  dessiner_bouton(&btn5);
  MLV_actualise_window();
  event2(tab);
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
void menu_regles_du_jeux(){
  Bouton btn;
  Tab_btn tab;
  tab.nb_btn =0;
  btn=creer_bouton(WINDOW_LARGEUR/4+50,WINDOW_HAUTEUR/6+600,500,100,"MENU",&tab,menu);
  MLV_clear_window( MLV_COLOR_BLACK);
  MLV_draw_text(0,50, "Voici les règles de ce jeu : dans le tableau de 4 cases sur 4, des carreaux numérotés à partir de 2 apparaissent.", MLV_COLOR_WHITE );
  MLV_draw_text(0,100, "Il faut ensuite glisser ces éléments avec les flèches du clavier, afin que deux carreaux portant le même montant se percutent et", MLV_COLOR_WHITE );
  MLV_draw_text(0,150, "fusionnent en un, dont le montant est égal à la somme des deux précédents.", MLV_COLOR_WHITE );
  MLV_draw_text(0,200, "2+2=4, 4+4=8, 8+8=16, 16+16=32... jusqu'à atteindre le but ultime, le nombre 2048 dans une des tuiles.", MLV_COLOR_WHITE );
  dessiner_bouton(&btn);
  event2(tab);
  MLV_actualise_window();
}

//chox du fichier dans le quelle on sauvegarder notre partie
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

//menu proposant les differente partie sauvegarder
void menu_chargement(int Grille[][NB_COL],int score,int m_score,char nom[10],M_score tab_score[10]){
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
  btn4=creer_bouton(WINDOW_LARGEUR/3,WINDOW_HAUTEUR/6+450,300,100,"Retour",&tab,menu);
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
      }
    }
  }
  choix(i,Grille,&score,nom);
  m_score=tab_score[0].m_score;
  jeux(Grille,score,m_score,nom,tab_score);
}

//menu proposant les different fichier dans les quelle on peut sauvegarder sa partie
void menu_sauv(int Grille[NB_LIGNE][NB_COL],int score,int m_score,char *nom,M_score tab_score[10]){
  Bouton btn,btn2,btn3,btn4;
  Tab_btn tab;
  MLV_Event event = MLV_NONE;
  MLV_Button_state state;
  int i=-1,x,y;
  tab.nb_btn =0;
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
      }
    }
  }
  choix_sauv(i,Grille,score,nom);
  MLV_clear_window(MLV_COLOR_BLACK);
  MLV_draw_text(WINDOW_LARGEUR/5,WINDOW_HAUTEUR/6, "Votre partie a été sauvegardée.", MLV_COLOR_WHITE );
  MLV_draw_text(WINDOW_LARGEUR/8,WINDOW_HAUTEUR/6+150, "Retour dans le jeux dans quelques secondes", MLV_COLOR_WHITE );
  MLV_actualise_window();
  MLV_wait_seconds(3);
  jeux(Grille,score,m_score,nom,tab_score);
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
