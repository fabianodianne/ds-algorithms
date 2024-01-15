#ifndef NODE_H
#define NODE_H

template <typename Object>
class Node {
    private:
        Object data;
        Node<Object>* next;
        Node<Object>* prev;
    public:
        Node(Object = Object());
        void set_data( Object);
        void set_next( Node<Object>*);
        void set_prev( Node<Object>*);
        Object get_data() ;
        Node<Object>* get_next() ;
        Node<Object>* get_prev() ;
};

#endif
