# Makefile pour INF3105 / TP2

OPTIONS = -Wall
# Choisir l'une des deux configurations : -g -O0 pour débogage et -O2 pour la remise.
#OPTIONS = -g -O0 -Wall
OPTIONS = -O2 -Wall

# Syntaxe : cible : dépendance1 dépendance2 ...
# Ensuite, la ou les ligne(s) débutant par une tabulation (\t) donne les commandes pour construire une cible

all : tp2 testdate

tp2: tp2.o historique.o dateheure.o
	g++ $(OPTIONS) -o tp2 dateheure.o historique.o tp2.o

tp2.o: tp2.cpp
	g++ $(OPTIONS) -c -o tp2.o tp2.cpp

dateheure.o: dateheure.h dateheure.cpp
	g++ $(OPTIONS) -c -o dateheure.o dateheure.cpp

historique.o: historique.h historique.cpp
	g++ $(OPTIONS) -c -o historique.o historique.cpp

testdate : testdate.cpp dateheure.o
	g++ $(OPTIONS) -o testdate testdate.cpp dateheure.o

clean :
	rm -f *.o
	rm -f tp2 testdate
	rm -f *~

