# created makefile 11/29/2022 @aho
CC = g++
CFLAGS = -Wall -g
 
chocAn: bst.cpp main.cpp manager.cpp model.cpp provider.cpp
	g++ -g -o chocAn_RUN bst.cpp main.cpp manager.cpp model.cpp provider.cpp member.cpp service.cpp -Wall
test: bst.cpp unit_test.cpp manager.cpp model.cpp provider.cpp
	g++ -g -o chocAn_RUN bst.cpp unit_test.cpp manager.cpp model.cpp provider.cpp member.cpp service.cpp -Wall
clear:
	rm -f *.o *.gch *~ /#*