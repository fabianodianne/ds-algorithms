#include <iostream>
#include <string>
using namespace std;

#include "doublylinkedlist.h"

bool character(string str) {
	for(auto i : str) {
		if(isalpha(i)) {
			return true;
			break;
		} else {
			return false;
		}
	}
}

int main() {
	DoublyLinkedList A;
	string op;
	string pos;
	int k;
	string tmpNum;
	int num;

	do {
		cin >> op;
		if(op == "INSERT") {
			cin >> pos >> tmpNum;
			if(pos == "HEAD" && isdigit(tmpNum[0])) {
				num = stoi(tmpNum);
				A.insert_to_head(num);
			} else if(pos == "TAIL" && isdigit(tmpNum[0])) {
				num = stoi(tmpNum);
				A.insert_to_tail(num);
			} else if(isdigit(pos[0]) && isdigit(tmpNum[0])) {
				k = stoi(pos);
				num = stoi(tmpNum);
				A.insert_to_kth(k, num);
			} else
				cout << "INVALID" << endl;
		} else if(op == "DELETE") {
			cin >> pos;
			if(pos == "HEAD")
				A.delete_from_head();
			else if(pos == "TAIL")
				A.delete_from_tail();
			else if(isdigit(pos[0])) {
				k = stoi(pos);
				if(A.is_empty() || k >= A.get_size())
					cout << "INVALID" << endl;
				else
					A.delete_kth(k);
			} else if(pos == "ALL")
				A.delete_all();
			else
				cout << "INVALID" << endl;
		} else if(op == "PRINT") {
			getline(cin, pos);
			if(pos == "")
				A.print_list();
			else if(pos == " SIZE")
				cout << A.get_size() << endl;
			else if(pos == " MIN") {
				if(A.is_empty())
					cout << "INVALID" << endl;
				else
					cout << A.get_min() << endl;
			} else if(pos == " MAX") {
				if(A.is_empty())
					cout << "INVALID" << endl;
				else
					cout << A.get_max() << endl;
			} else if(pos == " REVERSED") {
				if(A.is_empty())
					cout << "INVALID" << endl;
				else
					A.print_list_reverse();
			} else if(pos.find("LOC")) {
				int i = pos.find("LOC") + 3;
				string tmpPos = "";
				while(i++ != pos.size()) {
					tmpPos += pos[i];
				}
				if(isdigit(tmpPos[0])) {
					num = stoi(tmpPos);
					cout << A.find_first(num) << endl;
				} else {
					cout << "INVALID" << endl;
				}
			} else
				cout << "INVALID" << endl;
		} else if(op == "END") {
			break;
		} else {
			cout << "INVALID" << endl;
		}
	} while(op != "END");
	
	return 0;
}