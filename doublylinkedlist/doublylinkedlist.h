#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDlIST_H

class Node {
	private:
		int data;
		Node* next;
		Node* prev;
	public:
		Node(int);
		int get_data();
		Node* get_next();
		Node* get_prev();
		void set_data(int);
		void set_next(Node*);
		void set_prev(Node*);
};

class DoublyLinkedList {
	private:
		Node* head;
		Node* kth;
		Node* tail;
		int size;
	public:
		DoublyLinkedList();
		bool insert_to_head(int);
		bool insert_to_tail(int);
		bool insert_to_kth(int, int);
		bool delete_from_head();
		bool delete_from_tail();
		bool delete_kth(int);
		bool delete_all();
		int get_size();
		bool is_empty();
		int find_first(int);
		int get_min();
		int get_max();
		void print_list();
		void print_list_reverse();
};

#endif