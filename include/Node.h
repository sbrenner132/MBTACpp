#pragma once
template <class T> class Node
{
private:
	T data;
	Node<T> *next;
	Node<T> *prev;
public:
	Node(T data);
	T getData();
	Node<T> * getNext();
	Node<T> * getPrev();
	void setData(T data);
	void setNext(Node<T> *next);
	void setPrev(Node<T> *prev);
};