#include <iostream>
#include "doublylinkedlist.h"

using std::cout;
using std::endl;

Node::Node(int x = 0) : data(x), next(nullptr), prev(nullptr) {}

int Node::get_data() { return data; }

Node* Node::get_next() { return next; }

Node* Node::get_prev() { return prev; }

void Node::set_data(int x) { data = x; }

void Node::set_next(Node* ptr) { next = ptr; }

void Node::set_prev(Node* ptr) { prev = ptr; }

DoublyLinkedList::DoublyLinkedList() : head(nullptr), tail(nullptr), kth(nullptr) {};

bool DoublyLinkedList::insert_to_head(int x) {
	Node* newNodePtr = new Node(x);
	if (is_empty()) {						// if list is empty
		head = newNodePtr;					// one node in the list is set as head, kth, and tail
		kth = head;	
		tail = head;
	} else {
		newNodePtr->set_next(head);
		head->set_prev(newNodePtr);
		head = newNodePtr;					// insert the new node at the front
		head->set_prev(nullptr);
	}
}

bool DoublyLinkedList::insert_to_tail(int x) {
	Node* newNodePtr = new Node(x);
	if(is_empty()) {						// if list is empty
		head = newNodePtr;					// one node in the list is set as head, kth, and tail
		kth = head;
		tail = head;
	} else {
		tail->set_next(newNodePtr);
		newNodePtr->set_prev(tail);
		tail = newNodePtr;					// insert the new node at the end of the list
		tail->set_next(nullptr);
	}
}

bool DoublyLinkedList::insert_to_kth(int k, int x) {
	Node* newNodePtr = new Node(x);
	if(is_empty()) {						// if list is empty
		head = newNodePtr;					// one node in the list is set as head, kth, and tail
		kth = head;	
		tail = head;
	} else if(k >= get_size()) {
		cout << "INVALID" << endl;
	} else if(k == 0) { 
		insert_to_head(x);
	} else if(k == get_size()-1) {
		insert_to_tail(x);
	} else {
		Node* tmpA = head;
		Node* tmpB;
		int i = 0;
		while(i++ < k-1) { 
			tmpA = tmpA->get_next();		// node A
		}
		tmpB = tmpA->get_next();			// node B
		tmpA->set_next(newNodePtr);			// insert the new node between node A and node B
		newNodePtr->set_prev(tmpA);
		newNodePtr->set_next(tmpB);
		tmpB->set_prev(newNodePtr);
	}
}

bool DoublyLinkedList::delete_from_head() {
	Node* tmpPtr = head;					// get the head
	if(is_empty())
		cout << "INVALID" << endl;
	else if(get_size() == 1)
		delete_all();
	else {
		head = tmpPtr->get_next();			// set the head to the second node
		delete tmpPtr;
		head->set_prev(nullptr);
	}
}

bool DoublyLinkedList::delete_from_tail() {
	Node* tmpPtr = tail;					// get the tail
	if(is_empty())
		cout << "INVALID" << endl;
	else if(get_size() == 1)
		delete_all();
	else {
		tail = tmpPtr->get_prev();			// set the prev node from the tail as the new tail
		delete tmpPtr;
		tail->set_next(nullptr);			// next to tail is null
	}
}

bool DoublyLinkedList::delete_kth(int k) {
	Node* tmpPtr;
	Node* tmpA = head;
	Node* tmpB;
	if(is_empty())
		cout << "INVALID" << endl;
	else if(k == 0)							// deleting node in position 0 is same as deleting head
		delete_from_head();
	else if(k == get_size()-1)				// the last node is also the tail
		delete_from_tail();
	else {
		int i = 0;
		while(i++ < k-1) {
			tmpA = tmpA->get_next();		// node A
		}
		tmpPtr = tmpA->get_next();			// kth node
		tmpB = tmpPtr->get_next();			// node B
		delete tmpPtr;
		tmpA->set_next(tmpB);	
		tmpB->set_prev(tmpA);
	}
}

bool DoublyLinkedList::delete_all() {
	while(head != nullptr) {				// delete from head until nullptr
		Node* tmpPtr = head;
		head = tmpPtr->get_next();
		delete tmpPtr;
	}
}

int DoublyLinkedList::get_size() {
	Node* tmpPtr = head;
	size = 0;
	while(tmpPtr != nullptr) {
		tmpPtr = tmpPtr->get_next();
		size++;
	}
	return size;
}

bool DoublyLinkedList::is_empty() {
	if(head == nullptr)
		return true;
	else 
		return false;
}

int DoublyLinkedList::find_first(int x) {
	Node* tmpPtr = head;
	int i = 0;
	while(tmpPtr != nullptr) {
		if(tmpPtr->get_data() == x) {	// scan all nodes until x is found
			return i;
			break;
		}
		tmpPtr = tmpPtr->get_next();
		i++;
	}
}

int DoublyLinkedList::get_min() {
	Node* tmpPtr = head;
	int min = tmpPtr->get_data();
	while(tmpPtr != nullptr) {
		if(min > tmpPtr->get_data()) {	// compare the current min to every scanned node
			min = tmpPtr->get_data();
		}
		tmpPtr = tmpPtr->get_next();
	}
	return min;
}

int DoublyLinkedList::get_max() {
	Node* tmpPtr = head;
	int max = tmpPtr->get_data();
	while(tmpPtr != nullptr) {
		if(max < tmpPtr->get_data()) {	// compare the current max to every scanned node
			max = tmpPtr->get_data();
		}
		tmpPtr = tmpPtr->get_next();
	}
	return max;
}

void DoublyLinkedList::print_list() {
	if(head == nullptr)
		cout << "INVALID";
	else {
		Node* tmpPtr = head;
		while(tmpPtr != nullptr) {
			cout << tmpPtr->get_data();
			tmpPtr = tmpPtr->get_next();
		}
	}
	cout << endl;
}

void DoublyLinkedList::print_list_reverse() {
	if(head == nullptr)
		cout << "INVALID";
	else {
		Node* tmpPtr = tail;
		while(tmpPtr != nullptr) {
			cout << tmpPtr->get_data() ;
			tmpPtr = tmpPtr->get_prev();
		}
	}
	cout << endl;
}