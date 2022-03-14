#pragma once
#include "Node.h"
#include <iostream>
#include <string>
template <class T> class DoubleLinkedList
{
private:
	int* size;
	Node<T>* head = nullptr;
	Node<T>* tail = nullptr;
public:
	DoubleLinkedList();
	~DoubleLinkedList();
	Node<T>* getFirst();
	void insert(T e);
	T deleteElement(T e);
	T get(T e);
	int length();
	std::string to_str();
};

