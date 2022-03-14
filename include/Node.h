#pragma once
template <class T>
class Node
{
private:
	T data;
	Node<T> *next;
	Node<T> *prev;

public:
	Node(T data)
	{
		this->data = data;
		setNext(nullptr);
		setPrev(nullptr);
	}
	T getData()
	{
		return data;
	}
	Node<T> *getNext()
	{
		return next;
	}
	Node<T> *getPrev()
	{
		return prev;
	}
	void setData(T data)
	{
		this->data = data;
	}
	void setNext(Node<T> *next)
	{
		this->next = next;
	}
	void setPrev(Node<T> *prev)
	{
		this->prev = prev;
	}
};