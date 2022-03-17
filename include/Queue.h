#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Queue
{
private:

    T *q;
    int head;
    int tail;
    int numEntries;
    int capacity;
    
    
    void loopInc(){
        tail = (tail+1)%capacity;
        numEntries++;
    }

    void loopDec(){
        head = (head == 0) ? (capacity-1) : (head-1);
        numEntries--;
    }


public:

    Queue();
    Queue(int cap)
    {
        if (cap < 0)
        {
            throw length_error("Queue cannot have negative capacity");
        };
        capacity = cap;
        q = new T[capacity];
        numEntries = head = tail = 0;
    }

    Queue(const Queue &q)
    {
        this->capacity = q.capacity;
        this->numEntries = q.numEntries;
        this->head = q.head;
        this->tail = q.tail;
        this->q = new T[capacity];
        for (int i = 0; i < numEntries; i++)
        {
            this->q[i] = q.q[i];
        }
    }

    void enqueue(T element){
        if (head == tail && numEntries > 0){
            throw overflow_error("Queue full");
        }
        q[tail] = element;
        loopInc();
    }

    void dequeue(){
        if (numEntries == 0){
            throw underflow_error("Queue empty");
        }
        delete &q[head];
        loopDec();
    }

    T* front(){
        return &q[head];
    }

    int size(){
        return numEntries;
    }


};
