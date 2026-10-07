# LIFAP6 - Automne 2017 - R. Chaine

# Pour compiler utiliser simplement la commande make (ou make main.ex)
# Pour compiler la version récursive utiliser la commande make main_rec.ex


main.ex : main.o liste-triee.o element.o
# L'executable main.ex doit être remis à jour si certains des fichiers 
# main.o liste-triee.o et element.o sont plus récents
	g++ main.o liste-triee.o element.o -omain.ex

main_rec.ex : main.o liste-triee_rec.o  element.o
# L'executable main_rec.ex doit être remis à jour si certains des fichiers 

# main.o liste-triee_rec.o et element.o sont plus récents
	g++ main.o liste-triee_rec.o element.o -omain_rec.ex

element.o : element.cpp element.h
# Le fichier objet element.o doit être remis à jour si certains des fichiers
#  element.cpp et element.h sont plus récents
	g++ -Wall -std=c++11 -c element.cpp

liste-triee.o : liste-triee.cpp liste-triee.h element.h
# Le fichier objet liste-triee.o doit être remis à jour si certains des fichiers
# liste-triee.cpp liste-triee.h et element.h sont plus récents
	g++ -Wall -std=c++11 -c liste-triee.cpp

liste-triee_rec.o : liste-triee.cpp liste-triee.h element.h
# Le fichier objet liste-triee_rec.o doit être remis à jour si certains des fichiers
# liste-triee.cpp liste-triee.h et element.h sont plus récents
	g++ -D_RECURSIF -Wall -std=c++11 -c liste-triee.cpp -oliste-triee_rec.o

main.o : main-triee.cpp liste-triee.h element.h
# Le fichier objet main.o doit être remis à jour si certains des fichiers
# main.cpp liste-triee.h et element.h sont plus récents
	g++ -Wall -ansi -std=c++11 -c main-triee.cpp

clean :
	-rm *.o *~

veryclean : clean 
	-rm *.ex

