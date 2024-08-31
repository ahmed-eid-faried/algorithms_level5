#pragma once
#include <iostream>
#include "clsDblLinkedList.h"
using namespace std;

void DblLinkedListIsEmpty()
{

	clsDblLinkedList <int> MydblLinkedList;

	if (MydblLinkedList.IsEmpty())
		cout << "\n\nYes List is Empty.\n";
	else
		cout << "\n\nNo List is not Empty.\n";

	MydblLinkedList.InsertAtBeginning(5);
	MydblLinkedList.InsertAtBeginning(4);
	MydblLinkedList.InsertAtBeginning(3);
	MydblLinkedList.InsertAtBeginning(2);
	MydblLinkedList.InsertAtBeginning(1);

	cout << "\nLinked List Contenet:\n";
	MydblLinkedList.PrintList();

	cout << "\nNumber of items in the linked list = " << MydblLinkedList.Size();

	if (MydblLinkedList.IsEmpty())
		cout << "\n\nYes List is Empty.\n";
	else
		cout << "\n\nNo List is not Empty.\n";
}