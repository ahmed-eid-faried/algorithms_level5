#pragma once
#include <iostream>
#include "clsDynamicArray.h"
using namespace std;


template<class T>
class clsMyQueueArr{
protected:
	clsDynamicArray<T> _MyQueue;

public:
	void Print() { _MyQueue.PrintList(); }
	void push(T value) { _MyQueue.InsertAtEnd(value); }
	void pop() { _MyQueue.DeleteFirstItem(); }
	int Size() { return _MyQueue.Size(); }
	bool IsEmpty() { return _MyQueue.IsEmpty(); }
	T front() { return _MyQueue.GetItem(0); }
	T back() { return _MyQueue.GetItem(Size() - 1); }
	T GetItem(int index) { return _MyQueue.GetItem(index); }
	void Reverse() { return _MyQueue.Reverse(); }
	bool UpdateItem(int index, T value) { return _MyQueue.UpdateItem(index, value); }
	T InsertAfter(int index, T value) { return _MyQueue.InsertAfter(index, value); }
	void InsertAtFront(T value) { _MyQueue.InsertAtBeginning(value); }
	void InsertAtBack(T value) { _MyQueue.InsertAtEnd(value); }
	void Clear() { return _MyQueue.Clear(); }
};