CC = gcc                                                                        
OPTION =-Wall

2048 :  2048.o bouton.o menu.o fonction.o jeux.o affichage_jeu.o sauvegarde.o
	$(CC) $(OPTION) `pkg-config --cflags MLV` `pkg-config --libs-only-other --libs-only-L MLV`  2048.o bouton.o menu.o fonction.o jeux.o affichage_jeu.o sauvegarde.o `pkg-config --libs-only-l MLV` -o 2048

2048.o : 2048.c
	$(CC) $(OPTION) -c 2048.c

bouton.o :  bouton.c bouton.h                       
	$(CC) $(OPTION) -c bouton.c

menu.o :  menu.c menu.h                       
	$(CC) $(OPTION) -c menu.c

fonction.o :  fonction.c fonction.h                       
	$(CC) $(OPTION) -c fonction.c

jeux.o : jeux.c jeux.h                       
	$(CC) $(OPTION) -c jeux.c

affichage_jeu.o : affichage_jeu.c affichage_jeu.h                       
	$(CC) $(OPTION) -c affichage_jeu.c

sauvegarde.o : sauvegarde.c sauvegarde.h                       
	$(CC) $(OPTION) -c sauvegarde.c

clean :
	rm -rf *.o *~ 2048
