#include"sauvegarde.h"

//Sauvegarde du tableau des meilleurs score :  score nom
void sauvegarde_m_score(M_score tab_score[10]){
  FILE* fichier=NULL;
  int i;
  fichier=fopen("sauvegarde_m_score.txt","w+");
  if(fichier==NULL){
    printf("impossible d'ouvrir le fichier\n");
    exit(EXIT_FAILURE);
  }
  for(i=0;i<10;i++){
    fprintf(fichier,"%d ",tab_score[i].m_score);
    fprintf(fichier,"%s ",tab_score[i].nom);
  }
  fclose(fichier);
}

//Sauvegarde de la partie en cours : grille score nom
//char x = numero de fihcier dans le quelle on va sauvegarder
//ex ; x = '1' -> 1_sauvegarde.txt
void sauvegarde_partie(int tab[][NB_COL],int score,char *nom,char x){
  FILE* fichier=NULL;
  char nom_fichier[24];
  sprintf(nom_fichier,"%c_sauvegarde_partie.txt",x);
  int i,j;
  fichier=fopen(nom_fichier,"w+");
  if(fichier==NULL){
    printf("impossible d'ouvrir le fichier\n");
    exit(EXIT_FAILURE);
  }
  for(i=0;i<NB_LIGNE;i++)
    {
      for(j=0;j<NB_COL;j++)
	fprintf(fichier,"%d ",tab[i][j]);
    }
  fprintf(fichier,"%d ",score);
  fprintf(fichier,"%s ",nom);
  fclose(fichier);
}

//Chargement du tableau des meilleur score : score nom
void chargement_m_score(M_score tab_score[10]){
  FILE* fichier=NULL;
  int i;
  fichier=fopen("sauvegarde_m_score.txt","r");
  if(fichier==NULL){
    printf("impossible d'ouvrir le fichier\n");
    exit(EXIT_FAILURE);
  }
  for(i=0;i<10;i++){
    fscanf(fichier,"%d",&tab_score[i].m_score);
    fscanf(fichier,"%s",tab_score[i].nom);
  }
  fclose(fichier);
}

//Chargement d'une ancienne partie : grille score nom
//char x = numero de fihcier dans le quelle on va recuperer la sauvegarde
//ex ; x =1 -> 1_sauvegarde.txt
void chargement_partie(int tab[][NB_COL],int *score,char *nom,char x){
  int i,j;
  FILE* fichier=NULL;
  char nom_fichier[24];
  sprintf(nom_fichier,"%c_sauvegarde_partie.txt",x);
  fichier=fopen(nom_fichier,"r");
  if(fichier==NULL){
    printf("impossible d'ouvrir le fichier\n");
    exit(EXIT_FAILURE);
  }
  for(i=0;i<NB_LIGNE;i++){
    for(j=0;j<NB_COL;j++){
      fscanf(fichier,"%d",&tab[i][j]);
    }
  }
  
  fscanf(fichier,"%d",score);
  fscanf(fichier,"%s ",nom);
  fclose(fichier);
}
