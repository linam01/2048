#include <string.h>
#include<time.h>
#include"fonction.h"
//#include"sauvegarde.h"

//initialise la grille à 0
void initialiseGrille(int Grille[][NB_COL]){
  int i, j;
  for (i=0; i<NB_LIGNE; i++){
    for (j=0; j<NB_COL; j++){
      Grille[i][j] = 0;
    }
  }
}

//Test si on est au debut du jeux en comptant le nombre de case vide
int debut_jeux(int Grille[][NB_COL]){
  int i,j,nombre_case_v=0;
  for(i=0;i<NB_LIGNE;i++){
    for(j=0;j<NB_COL;j++){
      if(Grille[i][j]==0){
	nombre_case_v++;
      }
    }
  }
  if(nombre_case_v==NB_LIGNE*NB_COL){
    return 1;
  }
  return 0;
}

//Genere un nombre aleatoire (2 ou 4) et le place dans la grille
void aleatoire(int Grille[][NB_COL]){
  int i,j,a;
  //si on est au debut du jeux alors aleatoire = 2
  if(debut_jeux(Grille)==1){
    i=rand()%NB_LIGNE;
    j=rand()%NB_COL;
    Grille[i][j]=2;
  }
  //sinon 2 ou 4
  do {
    i=rand()%NB_LIGNE;
    j=rand()%NB_COL;    
  }while(Grille[i][j]!=0);
  if(Grille[i][j] == 0){
    do{
      a=rand()%(4+1-2)+2;
    }while(a == 3);
    Grille[i][j] = a;
  }
}

//fonction qui copie la grille dans une grille temporaire
void copierGrille(int Grille[][NB_COL],int Grille_tmp[][NB_COL]){
  int i, j;
  for (i=0; i<NB_LIGNE; i++){
    for (j=0; j<NB_COL; j++){
      Grille_tmp[i][j]=Grille[i][j]; 
    }
  }
}

//fonction qui compare la grille temporeaire avec la grille
int comparaison(int Grille[][NB_COL],int Grille_tmp[][NB_COL]){
  int i, j;
  for (i=0; i<NB_LIGNE; i++){
    for (j=0; j<NB_COL; j++){
      if(Grille[i][j]!=Grille_tmp[i][j]){
	return 0;
      }
    }
  }
  return 1;
}

//Deplacement des tuiles vers la gauche
void gauche(int Grille[][NB_COL]){
  int i,j,k;
  for(i=0;i<NB_LIGNE;i++){
    for(j=0;j<NB_COL;j++){
      for(k=j+1;k<NB_COL;k++){              
	if(Grille[i][j] == 0 && Grille[i][k] != 0){
	  Grille[i][j]=Grille[i][k];
	  Grille[i][k]=0;                               		       	
	}
      }
    }
  }
}

//Deplacement des tuiles vers le haut
void haut(int Grille[][NB_COL]){
  int i,j,k;
  for(i=0;i<NB_LIGNE;i++){
    for(j=0;j<NB_COL;j++){
      for(k=i+1;k<NB_LIGNE;k++){
	if(Grille[i][j]==0 && Grille[k][j]!=0){
	  Grille[i][j]=Grille[k][j];
	  Grille[k][j]=0;
	}             
      }
    }
  }
}

//Deplacement des tuiles vers le bas
void bas(int Grille[][NB_COL]){
  int i,j,k;
  for(i=NB_LIGNE-1;i>=0;i--) {
    for(j=0;j<NB_COL;j++){
      for(k=i-1;k>=0;k--){
	if(Grille[i][j]==0 && Grille[k][j]!=0){
	  Grille[i][j]=Grille[k][j];
	  Grille[k][j]=0;
	}
      }
    }
  }
}	 
//Deplacement des tuiles vers le droite
void droite(int Grille[][NB_COL]){
  int i,j,k ;	
  for(i=0;i<NB_LIGNE;i++){
    for(j=NB_COL-1;j>=0;j--){
      for(k=j-1;k>=0;k--){
	if(Grille[i][j]==0 && Grille[i][k]!=0){
	  Grille[i][j]=Grille[i][k];
	  Grille[i][k]=0;
	}
      }	  
    }
  }
}

//Fonction qui gere les deplacement en fonction de la direction donnée par les fleches directionelle du clavier
void f_direction(int Grille[][NB_COL], MLV_Keyboard_button direction){
  if(direction==MLV_KEYBOARD_LEFT){
    gauche(Grille);
  }
  else if(direction==MLV_KEYBOARD_RIGHT){
    droite(Grille);
  }
  else if(direction==MLV_KEYBOARD_UP){
    haut(Grille);
  }
  else if(direction==MLV_KEYBOARD_DOWN){
    bas(Grille); 
  }
}	 

//fonction qui fusionne les tuiles en adiitionnant le contenu de leur case et incremente la somme a chaque deplacement
void addition(int tab[][NB_COL],MLV_Keyboard_button direction,int *somme,int *m_score){
  int i,j;     
  if(direction==MLV_KEYBOARD_LEFT){
    for(i=0;i<NB_LIGNE;i++){
      for(j=0;j<NB_COL;j++){
	if(tab[i][j] != 0 && tab[i][j+1] != 0 && tab[i][j]==tab[i][j+1]){
	  tab[i][j]=tab[i][j]+tab[i][j+1];
	  tab[i][j+1]=0;
	  score(somme,m_score,tab,i,j);
	}
      }
    }
    gauche(tab);
  }
  else if(direction==MLV_KEYBOARD_RIGHT){
    for(i=0;i<NB_LIGNE;i++){
      for(j=NB_COL-1;j>0;j--){
	if(tab[i][j] != 0 && tab[i][j-1] != 0 && tab[i][j]==tab[i][j-1]){
	  tab[i][j]=tab[i][j]+tab[i][j-1];
	  tab[i][j-1]=0;
	  score(somme,m_score,tab,i,j);
	}
      }
    }
    droite(tab);
  }
  else if(direction==MLV_KEYBOARD_UP){
    for(i=0;i<NB_LIGNE-1;i++){
      for(j=0;j<NB_COL;j++){
	if(tab[i][j] != 0 && tab[i+1][j] != 0 && tab[i][j]==tab[i+1][j]){
	  tab[i][j]=tab[i][j]+tab[i+1][j];
	  tab[i+1][j]=0;
	  score(somme,m_score,tab,i,j);
	}
      }
    }
    haut(tab);
  }else if(direction==MLV_KEYBOARD_DOWN){
    for(i=NB_LIGNE-1;i>0;i--){
      for(j=0;j<NB_COL;j++){
	if(tab[i][j] != 0 && tab[i-1][j] != 0 && tab[i][j]==tab[i-1][j]){
	  tab[i][j]=tab[i][j]+tab[i-1][j];
	  tab[i-1][j]=0;
	  score(somme,m_score,tab,i,j);
	}
      }
    }
    bas(tab);
  } 
}	 

//Incrementation du score et verification si meilleur score atteint -> maj du m_score
void score(int *somme,int *m_score,int Grille[][NB_COL],int i,int j){
  *somme=*somme+Grille[i][j];
  if (*m_score<*somme){
    *m_score=*somme;
  }
}

//Actualise le tableau de meilleru score
void meilleur_score(M_score tab_m_score[10],int scr,char nom[10]){
  int i;
  //si score > m_score et que le nom du meilleur score est le meme que le nom du joueur actuel alors on actualise uniquement le score
  if(scr>tab_m_score[0].m_score && strcmp(tab_m_score[0].nom,nom)==0){
    tab_m_score[0].m_score=scr;
  }
  //sinon on actualise le score et le nom du joueur et on decale de 1 rang les autre score
  else if(scr>tab_m_score[0].m_score && strcmp(tab_m_score[0].nom,nom)!=0){
    for(i=9;i>0;i--){
      tab_m_score[i]=tab_m_score[i-1];
    }
    tab_m_score[0].m_score=scr;
    sprintf(tab_m_score[0].nom,"%s",nom);
  }
  //sauvegarde du tableau : maj des meilleurs score
  // sauvegarde_m_score(tab_m_score);
}

//Test victoire si tuile = 2048
int victoire(int Grille[][NB_COL]){
  int i,j;
  for(i=0;i<NB_LIGNE;i++){
    for(j=0;j<NB_COL;j++){
      if(Grille[i][j]==2048){
	return 1;
      }
    }
  }
  return 0;
}

//verifie si un deplacement est posible sur les lignes 
int deplace_ligne(int Grille[][NB_COL]){
  int i,j;
  for(i=0;i<NB_LIGNE;i++){
    for(j=0;j<NB_COL-1;j++){
      if(Grille[i][j]==Grille[i][j+1]){
	return 1;
      }
    }
  }
  return 0;
}	 
//verifie si un deplacement est posible sur les colonnes
int deplace_colonne(int Grille[][NB_COL]){
  int i,j;
  for(i=0;i<NB_LIGNE-1;i++){
    for(j=0;j<NB_COL;j++){
      if(Grille[i][j]==Grille[i+1][j]){
	return 1;
      }
    }
  }
  return 0;
}

//test la condition de defaite
int defaite(int Grille[][NB_COL]){
  int i,j,nombre=0;
  for(i=0;i<NB_LIGNE;i++){
    for(j=0;j<NB_COL;j++){
      if(Grille[i][j]==0){
	nombre++;
	return 1;
      }
    }
  }
  //si il n'y a pas de case vide et aucun deplacement possible sur les ligne et colonne alors -> defaite
  if(nombre==0 && deplace_ligne(Grille)==0 && deplace_colonne(Grille)==0){
    return 0;
  }
  return 1;
}

//test si une case est vide
int case_vide(int Grille[][NB_COL]){
  int i,j;
  for(i=0;i<NB_LIGNE;i++){
    for(j=0;j<NB_COL;j++){
      if(Grille[i][j]==0){
	return 1;
      }
    }
  }
  return 0;
}
