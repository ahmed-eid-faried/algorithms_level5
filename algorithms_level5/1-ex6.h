#pragma once
#include <iostream>
#include "clsDblLinkedList.h"
using namespace std;


void  DblLinkedListGetItemByIndex()
{

	clsDblLinkedList <int> MydblLinkedList;

	MydblLinkedList.InsertAtBeginning(5);
	MydblLinkedList.InsertAtBeginning(4);
	MydblLinkedList.InsertAtBeginning(3);
	MydblLinkedList.InsertAtBeginning(2);
	MydblLinkedList.InsertAtBeginning(1);

	cout << "\nLinked List Contenet:\n";
	MydblLinkedList.PrintList();

	cout << "\nItem(2) Value is: " << MydblLinkedList.GetItem(2);

}