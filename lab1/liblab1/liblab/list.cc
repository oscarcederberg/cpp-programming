#include <iostream>
#include "list.h"

using std::cout;
using std::endl;

List::List() {
	first = nullptr;
}

List::~List() {
	Node* current = first;
	Node* temp;
	while(current != nullptr){
		temp = current->next;
		delete current;
		current = temp;
	}
}

bool List::exists(int d) const {
	Node* temp = first;
	while(temp != nullptr){
		if(temp->value == d){
			return true;
		}
		temp = temp->next;
	}

	return false;
}

int List::size() const {
	int size = 0;
	
	Node* temp = first;
	while(temp != nullptr){
		size++;
		temp = temp->next;
	}
	
	return size;
}

bool List::empty() const {
	return first == nullptr;
}

void List::insertFirst(int d) {
	first = new Node(d, first);
}

void List::remove(int d, DeleteFlag df) {
	
	Node* prev = nullptr;
	Node* temp = first;
	bool found = false;

	while(temp != nullptr){
		if(df == List::DeleteFlag::LESS && temp->value < d){
			found = true;
		}else if(df == List::DeleteFlag::EQUAL && temp->value == d){
			found = true;
		}else if(df == List::DeleteFlag::GREATER && temp->value > d){
			found = true;
		}else{
			prev = temp;
			temp = temp->next;
		}

		if(found){
			Node* next = temp->next;
			delete temp;
			if(prev == nullptr){
				first = next;
			}else{
				prev->next = next;
			}
			break;
		}
	}
}

void List::print() const {	
	Node* temp = first;
	cout << "{";
	while(temp != nullptr){
		cout << temp->value;
		temp = temp->next;
		if(temp != nullptr){
			cout << ", ";
		}
	}
	cout << "}" << endl;
}

