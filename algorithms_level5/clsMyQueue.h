#pragma once
#include <iostream>
#include "clsDblLinkedList.h"
using namespace std;
//  back front  
//  1 2 3 4 5

template<class T>
class clsMyQueue {
protected:
	clsDblLinkedList<T> _MyQueue;

public:
	void Print() { _MyQueue.PrintList(); }
	void push(T value) { _MyQueue.InsertAtEnd(value); }
	void pop() { _MyQueue.DeleteFirstNode(); }
	int Size() { return _MyQueue.Size(); }
	bool IsEmpty() { return _MyQueue.IsEmpty(); }
	T front() { return _MyQueue.GetItem(0); }
	T back() { return _MyQueue.GetItem(Size() - 1); }

	//void InsertAtBeginning(T value) { _InsertAtBeginning(_head, value); }
	//Node* Find(T value) { return _Find(_head, value); }
	//void InsertAfter(Node* current, T value) { _InsertAfter(current, value); }
	//bool InsertAfter(int index, T value) { return _InsertAfter(index, value); }
	//void DeleteNode(Node*& NodeToDelete) { _DeleteNode(_head, NodeToDelete); }
	//void DeleteLastNode() { _DeleteLastNode(_head); }
	//void DeleteFirstNode() { _DeleteFirstNode(_head); }
	//int Size() { return _Size; }
	//bool IsEmpty() { return _Size == 0; }
	//void Clear() { return _Clear(); }
	//void Reverse() { return _Reverse(_head); }
	//Node* GetNode(int index) { return _GetNode(_head, index); }
	//T GetItem(int index) { return _GetItem(_head, index); }
	//bool UpdateItem(int index, T value) { return _UpdateItem(index, value); }

};