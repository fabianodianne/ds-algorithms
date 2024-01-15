all : exam

node.o : node.h node.cpp
	g++ -c node.cpp

singlylinkedlist.o : singlylinkedlist.h singlylinkedlist.cpp 
	g++ -c singlylinkedlist.cpp

main.o : main.cpp
	g++ -c main.cpp

exam : main.o node.o singlylinkedlist.o
	g++ -o exam main.o node.o singlylinkedlist.o 

clean :
	rm -rf *.o *.gch exam
