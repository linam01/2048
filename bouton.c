#include"bouton.h"
#include"config.h"

//verifie que les coordonée de la  souris sont dans un bouton via un tableau de bouton
int clicke(int x,int y,Tab_btn tab){
  int i;
  for(i=0;i<tab.nb_btn;i++){
    if((x>=tab.tab_btn[i].x && y>=tab.tab_btn[i].y) && (x<=tab.tab_btn[i].x+tab.tab_btn[i].largeur) && (y<=tab.tab_btn[i].y+tab.tab_btn[i].hauteur)){
      //va a la fonction associer au bouton
      if(tab.tab_btn[i].fonction!=NULL){
	tab.tab_btn[i].fonction(i);
      }
      //si fonction == NULL alors return l'entier du bouton
      else if(tab.tab_btn[i].fonction==NULL){
	return i;
      }
    }
  }
  return -1;
}

//Gére les evenements du clavier et de la souris 
void event2(Tab_btn tab){
  MLV_Event event;
  MLV_Button_state state;
  MLV_Keyboard_button sym;
  int sortie=0;
  int x,y;
  while(sortie==0){ 
    event=MLV_get_event(&sym, NULL, NULL, NULL, NULL, &x, &y, NULL, &state);
    switch(event){
    case MLV_KEY :
      if (state==MLV_PRESSED)
	if(sym==MLV_KEYBOARD_q){
	  exit(0);
	}
      break;
    case MLV_MOUSE_BUTTON :
      if(state==MLV_PRESSED){
	clicke(x,y,tab);
	break;
      default:
	break;
      }
    }
  }
}

//Creer un bouton en recuperant les argument de la fonction MLV_draw_text_box
//Affecte un bouton a un tableau de bouton
Bouton creer_bouton(int x, int y,int largeur,int hauteur,char *texte,Tab_btn *tab,void *fonction){
  Bouton btn;
  btn.x =x;
  btn.y =y;
  btn.hauteur=hauteur;
  btn.largeur=largeur;
  btn.text = texte;
  btn.fonction = fonction;
  tab->tab_btn[tab->nb_btn]=btn;
  tab->nb_btn++;
  return btn;
}

//dessine un bouton 
void dessiner_bouton(Bouton *btn){
  MLV_draw_text_box(btn->x,
		    btn->y,
		    btn->largeur,
		    btn->hauteur,
		    btn->text,
		    SIZE_INTERLIGNE,
		    MLV_COLOR_WHITE,
		    MLV_COLOR_WHITE,
		    MLV_rgba(0,0,0,MLV_ALPHA_TRANSPARENT),
		    MLV_TEXT_CENTER,MLV_HORIZONTAL_CENTER,MLV_VERTICAL_CENTER);
}
