# Makefile

all : doublylinkedlist.o test

doublylinkedlist.o : doublylinkedlist.cpp
	g++ -c doublylinkedlist.cpp
	
test : fabiano1andalis2_main.cpp doublylinkedlist.o
	g++ -o test fabiano1andalis2_main.cpp doublylinkedlist.o
	
clean :
	rm -rf doublylinkedlist.o test
	
