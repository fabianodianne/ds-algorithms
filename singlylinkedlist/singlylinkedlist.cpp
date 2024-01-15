#include <iostream>
using namespace std;
#include "singlylinkedlist.h"

template<typename Object>
SinglyLinkedList<Object>::SinglyLinkedList() : head(nullptr), tail(nullptr), count (0) {}

template<typename Object>
int SinglyLinkedList<Object>::size(){
    return count;
}

template<typename Object>
bool SinglyLinkedList<Object>::empty(){
    return size() == 0;
}

template<typename Object>
Object SinglyLinkedList<Object>::front(){
    return head->get_data();
}

template<typename Object>
Object SinglyLinkedList<Object>::back(){
    return tail->get_data();
}

template<typename Object>
Node<Object>* SinglyLinkedList<Object>::begin(){
    return head;
}

template<typename Object>
Node<Object>* SinglyLinkedList<Object>::end(){
    return nullptr;
}

template<typename Object>
void SinglyLinkedList<Object>::push_front(Object x){
    Node <Object>* ptr = new Node<Object> (x);
    if (size() == 0){
        head = tail = ptr;
    } else {
        ptr->set_next(head);
        head->set_prev(ptr); // mine
        head = ptr;
    }
    count ++;
}

template<typename Object>
void SinglyLinkedList<Object>::push_back(Object x){
    Node <Object>* ptr = new Node<Object> (x);
    if (size() == 0){
        head = tail = ptr;
    } else {
        tail->set_next(ptr);
        ptr->set_prev(tail); // mine
        tail = ptr;
    }
    count++;
}

template<typename Object>
Object SinglyLinkedList<Object>::pop_front() {
    if (empty())
        throw underflow_error("Error: Can't delete from an empty list!");

    Node <Object>* ptr = head;
    head = head->get_next();
    count--;
    return ptr->get_data();
}

template<typename Object>
Object SinglyLinkedList<Object>::pop_back(){
    if (empty())
        throw underflow_error("Error: Can't delete from an empty list!");
    
    Node <Object>* ptr = begin();
    Object d;
    if (size() == 1) {
        d = ptr->get_data();
        delete ptr;
        head = tail = end();
        count--;
    } else {
        while(ptr->get_next()->get_next() != end()) {
            ptr = ptr->get_next();
        }
        d = tail->get_data();
        ptr->set_next(end());
        end()->set_prev(ptr); // mine
        delete tail;
        tail = ptr;
        count --;
    }
    return d;
}

template<typename Object>
void SinglyLinkedList<Object>::erase(Node<Object>* location){
    if (empty())
        throw underflow_error("Error: Can't delete from an empty list!");

    if (location == end())
        return;

    if (location == begin()) {
        pop_front();
        return;
    }

    if (location->get_next() == end()){
        pop_back();
        return;
    }
        
    Node <Object>* ptr = begin();
    while(ptr->get_next() != location) 
        ptr = ptr->get_next();
    ptr->set_next(location->get_next());
    (location->get_next())->set_prev(ptr); // mine
    delete location;
    count --;
}

template<typename Object>
void SinglyLinkedList<Object>::erase(Object x){
    if (empty())
        throw underflow_error("Error: Can't delete from an empty list!");

    if (x == front()) {
        pop_front();
        return;
    }

    if (x == back()) {
        pop_back();
        return;
    }
        
    Node <Object>* ptr = begin();
    while(ptr != end() && ptr->get_next()->get_data() != x) 
        ptr = ptr->get_next();
    
    if (ptr != end()){
        Node <Object>* tmp = ptr->get_next();
        ptr->set_next(tmp->get_next());
        (tmp->get_next())->set_prev(ptr); // mine
        delete tmp;
    }
    count --;
}

// mine
template<typename Object>
void SinglyLinkedList<Object>::append(SinglyLinkedList<Object>* L) {
    Node <Object>* ptr = tail;
    ptr->set_next(L->begin());
    (L->begin())->set_prev(ptr);
    tail = L->tail;
}

// mine
template<typename Object>
void SinglyLinkedList<Object>::unique() {
    Node <Object>* ptr = begin();
    while(ptr != end()) {
        if(ptr->get_data() == ptr->get_next()->get_data())
            erase(ptr->get_data());
        ptr = ptr->get_next();
    }
}