#include <stdexcept>
using std::underflow_error;

#include "node.h"

#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

template <typename Object>
class SinglyLinkedList {
    private:
        Node <Object>* head; 
        Node <Object>* tail;
        int count;
    public:
        SinglyLinkedList();
        int size();
        bool empty();
        Object front();
        Object back();
        Node<Object>* begin();
        Node<Object>* end();
        void push_front(Object);
        void push_back(Object);
        Object pop_front();
        Object pop_back(); 
        void erase(Node<Object>*);
        void erase(Object);
        void append(SinglyLinkedList<Object>*);
        void unique();
};

#endif
