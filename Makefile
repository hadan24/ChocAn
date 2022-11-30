# created makefile 11/29/2022 @aho
CC = g++
CFLAGS = -Wall -g
 
chocAn: bst.cpp main.cpp manager.cpp model.cpp provider.cpp
	g++ -g -o chocAn_RUN *.cpp
clear:
	rm -f *.o *.gch *~ /#*