#pragma once
#include <iostream>
#include "clsDblLinkedList.h"
using namespace std;


void  DblLinkedListInsertAfterByIndex()
{
	clsDblLinkedList <int> MydblLinkedList;

	MydblLinkedList.InsertAtBeginning(5);
	MydblLinkedList.InsertAtBeginning(4);
	MydblLinkedList.InsertAtBeginning(3);
	MydblLinkedList.InsertAtBeginning(2);
	MydblLinkedList.InsertAtBeginning(1);

	cout << "\nLinked List :\n";
	MydblLinkedList.PrintList();

 	//clsDblLinkedList <int>::Node* N = MydblLinkedList.Find(5);
	MydblLinkedList.InsertAfter(4, 500);

	cout << "\nAfter Insert :\n";
	MydblLinkedList.PrintList();

}