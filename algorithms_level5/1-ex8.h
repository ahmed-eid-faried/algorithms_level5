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

	cout << "\nLinked List Contenet:\n";
	MydblLinkedList.PrintList();

	MydblLinkedList.InsertAfter(2, 500);

	cout << "\nAfter Updating Item(2): " << "\n";
	MydblLinkedList.PrintList();
}