#include "DoubleLinkedList.h"
using namespace std;
template <class T> DoubleLinkedList<T>::DoubleLinkedList() {
	size = new int;
	*size = 0;
}

template <class T> DoubleLinkedList<T>::~DoubleLinkedList() {
	delete size;
	delete head;
}

template <class T> Node<T>* DoubleLinkedList<T>::getFirst() {
	return head;
}

template <class T> void DoubleLinkedList<T>::insert(T e) {
	Node<T>* n = new Node<T>(e);
	if (length() == 0) {
		this->head = n;
	}
	else {
		this->tail->setNext(n);
		n->setPrev(this->tail);
	}

	this->tail = n;
	*(this->size) += 1;
}

template <class T> T DoubleLinkedList<T>::deleteElement(T e) {
	if (e == this->head->getData()) {
		T obj = this->head->getData();
		Node<T>* old = this->head;
		this->head = this->head->getNext();
		this->size--;
		delete old;
		return obj;
	}
	else {
		Node<T>* curr = this->head;
		while (curr != nullptr) {
			if (curr->getData() == e) {
				Node<T>* old = curr;
				curr->getPrev()->setNext(curr->getNext());
				if (curr->getNext() != NULL) {
					curr->getNext()->setPrev(curr->getPrev());
				}
				delete old;
				*(this->size) -= 1;
				return curr->getData();
			}
			curr = curr->getNext();
		}
		return NULL;
	}
}

template <class T> T DoubleLinkedList<T>::get(T e) {
	Node<T>* curr = this->head;
	while (curr != nullptr) {
		if (curr->getData() == e) {
			return curr->getData();
		}
		curr = curr->getNext();
	}
	return NULL;
}

template <class T> int DoubleLinkedList<T>::length() {
	return *(this->size);
}

template <class T> string DoubleLinkedList<T>::to_str() {
	Node<T>* curr = this->head;
	string dll("[");
	while (curr != NULL) {
		dll += to_string(curr->getData());
		if (curr != this->tail) {
			dll += ", ";
		}
		curr = curr->getNext();
	}
	return dll + "]";
}

// passing e by ref
//std::string to_string(const Foo &e) {
//
//}
