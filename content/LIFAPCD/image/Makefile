all: executable.out

executable.out: src/Pixel.o src/mainTest.o
	g++ -g obj/mainTest.o obj/Pixel.o -o executable.out

# pour chaque dependances, on va ecrire une regle: une dependance=> un .cpp
# -c permets de sarrete a la compilation de lobjet (.o)
# -g permets de preciser les fichiers objets necessaires a la compilation
# lordre des dependances ne comptene=t pas
# lordre des regles non plus

src/Pixel.o:
	g++ -g -Wall -c src/Pixel.cpp -o obj/Pixel.o

src/mainTest.o:
	g++ -g -Wall -c src/mainTest.cpp -o obj/mainTest.o

clean:
	rm *.o

veryclean: clean
	rm *.out

# 1 regle/executable (qui rassemble les dependances et 1 regle pour chaques dependances de lexecutable)
