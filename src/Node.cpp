#include "../include/Node.h"
#include <string>

template <class T> Node<T>::Node(T data) {
	this->data = data;
	setNext(nullptr);
	setPrev(nullptr);
}

template <class T> T Node<T>::getData() {
	return data;
}

template <class T> Node<T>* Node<T>::getNext() {
	return next;
}

template <class T> Node<T>* Node<T>::getPrev() {
	return prev;
}

template <class T> void Node<T>::setData(T data) {
	this->data = data;
}

template <class T> void Node<T>::setNext(Node<T> *next) {
	this->next = next;
}

template <class T> void Node<T>::setPrev(Node<T> *prev) {
	this->prev = prev;
}


int main(){
	
}