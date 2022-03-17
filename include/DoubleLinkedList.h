#pragma once
#include "Node.h"
#include <iostream>
#include <string>
#include "Station.h"

using namespace std;

template <class T>
class DoubleLinkedList
{
private:

	int size;
	Node<T> *head = nullptr;
	Node<T> *tail = nullptr;

public:

	DoubleLinkedList(){
		size = 0;
	}


	~DoubleLinkedList(){
		delete head;
	}


	Node<T>* getFirst(){
		return head;
	}


	void insert(T e){
		Node<T> *n = new Node<T>(e);

		if (size == 0){
			head = n;
		}else{
			tail->setNext(n);
			n->setPrev(tail);
		}

		tail = n;
		size += 1;
	}


	T deleteElement(T e){
		if (head->getData() == e){
			if (head.getNext == nullptr){
				head = nullptr;
				return e;
			}else{
				head = head->getNext();
				head->setPrev(nullptr);
				return e;
			}
		}else if (tail->getData() == e){
			tail = tail->getPrev();
			tail->setNext(nullptr);
		}else{
			Node<T>* currptr = head->getNext();
			while (currptr != nullptr){
				if (currptr->getData() == e){
					currptr->setNext(currptr->getPrev());
					currptr->setPrev(currptr->getNext());
					return e;
				}
				currptr = currptr->getNext();
			}
		}
	}


	T get(const T &e){
		Node<T>* curr = head;
		while (curr != nullptr){
			if (curr->getData() == e){	
				T dt = curr->getData();
				return dt;
			}
			curr = curr->getNext();
		}
		cout << "get" << endl;
		return T();
	}


	int length(){
		return size;
	}


	std::string to_str(){
		cout << "to_str" << endl;
		Node<T> *curr = this->head;
		string dll("[");
		while (curr != NULL){
			cout << curr << endl;
			T dt = curr->getData();
			cout << (&dt == nullptr) << endl;
			dll += dt.to_str();
			if (curr != this->tail){
				dll += ", ";
			}
			curr = curr->getNext();
		}
		return dll + "]";
	}


	// passing e by ref
	std::string to_string(Station e) {
		return e.to_str();
	}
};
