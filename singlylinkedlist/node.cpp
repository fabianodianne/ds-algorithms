#include "node.h"

template <typename Object>
Node<Object>::Node(Object x) : data(x), next(nullptr), prev(nullptr) {}

template <typename Object>
void Node<Object>::set_data(Object x){
    data = x;
}

template <typename Object>
void Node<Object>::set_next(Node<Object>* ptr){
    next = ptr;
}

template <typename Object>
void Node<Object>::set_prev(Node<Object>* ptr){
    prev = ptr;
}

template <typename Object>
Object Node<Object>::get_data(){
    return data;
}

template <typename Object>
Node<Object>* Node<Object>::get_next(){
    return next;
}

template <typename Object>
Node<Object>* Node<Object>::get_prev(){
    return prev;
}
