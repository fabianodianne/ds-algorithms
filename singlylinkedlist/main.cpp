#include <iostream>
#include <string>
using namespace std;

#include "node.h"
#include "node.cpp"
#include "singlylinkedlist.h"
#include "singlylinkedlist.cpp"

int main(){
    SinglyLinkedList<int>* A = new SinglyLinkedList<int>();
    A->push_back(1);
    A->push_back(4);
    A->push_back(3);

    SinglyLinkedList<int>* B = new SinglyLinkedList<int>();
    B->push_back(4);
    B->push_back(4);

    A->append(B);

    SinglyLinkedList<int> L;
    L.push_back(1);
    L.push_back(4);
    L.push_back(3);
    L.push_back(3);
    L.push_back(4);
    L.push_back(4);
    L.push_back(4);

    L.unique();
    
    return 0;
}
