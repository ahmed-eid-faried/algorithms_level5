#pragma once
#include <iostream>
#include "clsDblLinkedList.h"
using namespace std;


template<class T>
class clsMyStack {
protected:
	clsDblLinkedList<T> _MyStack;

public:
	void Print() { _MyStack.PrintList(); }
	void push(T value) { _MyStack.InsertAtBeginning(value); }
	void pop() { _MyStack.DeleteFirstNode(); }
	int Size() { return _MyStack.Size(); }
	bool IsEmpty() { return _MyStack.IsEmpty(); }
	T Top() { return _MyStack.GetItem(0); }
	T Bottom() { return _MyStack.GetItem(Size() - 1); }


	T GetItem(int index) { return _MyStack.GetItem(index); }
	void Reverse() { return _MyStack.Reverse(); }
	bool UpdateItem(int index, T value) { return _MyStack.UpdateItem(index, value); }
	T InsertAfter(int index, T value) { return _MyStack.InsertAfter(index, value); }
	void InsertAtFront(T value) { _MyStack.InsertAtBeginning(value); }
	void InsertAtBack(T value) { _MyStack.InsertAtEnd(value); }
	void Clear() { return _MyStack.Clear(); }
};