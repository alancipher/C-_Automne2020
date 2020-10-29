#Makefile pour Lab5

#Configuration standard
OPTIONS =

#Configuration avec debugage
#OPTIONS = -g -O0 -Wall

#Configuration avec optimisation
#OPTIONS = -O3 -Wall

all: test_avl lab6 

test_avl: testavl.cpp arbreavl.h
	g++ $(OPTIONS) -o test_avl testavl.cpp

lab6: lab6.cpp arbreavl.h
	g++ $(OPTIONS) -o lab6  lab6.cpp

clean :
	rm -f test_avl
	rm -f lab6
	

