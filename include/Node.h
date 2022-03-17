#pragma once
template <class T>
class Node
{
private:
	T data;
	Node<T> *next;
	Node<T> *prev;

public:
	Node(T dt)
	{
		data = dt;
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
	void setData(T dt)
	{
		data = dt;
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