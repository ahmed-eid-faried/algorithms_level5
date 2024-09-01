#pragma once
#include <iostream>
#include "clsDynamicArray.h"
using namespace std;

void clsDynamicArrayExtensions11()
{

	clsDynamicArray <int> MyDynamicArray(5);

	MyDynamicArray.SetItem(0, 10);
	MyDynamicArray.SetItem(1, 20);
	MyDynamicArray.SetItem(2, 30);
	MyDynamicArray.SetItem(3, 40);
	MyDynamicArray.SetItem(4, 50);

	cout << "\nIs Empty?  " << MyDynamicArray.IsEmpty();
	cout << "\nArray Size: " << MyDynamicArray.Size() << "\n";
	cout << "\nArray Items: \n";

	MyDynamicArray.PrintList();

	MyDynamicArray.InsertAtBeginning(100);
	cout << "\n\nArray after insert 100 at Begining:";
	cout << "\nArray Size: " << MyDynamicArray.Size() << "\n";
	MyDynamicArray.PrintList();

	MyDynamicArray.InsertBefore(2, 200);
	cout << "\n\nArray after insert 200 before index 2:";
	cout << "\nArray Size: " << MyDynamicArray.Size() << "\n";
	MyDynamicArray.PrintList();

	MyDynamicArray.InsertAfter(2, 300);
	cout << "\n\nArray after insert 300 after index 2:";
	cout << "\nArray Size: " << MyDynamicArray.Size() << "\n";
	MyDynamicArray.PrintList();


	MyDynamicArray.InsertAtEnd(400);
	cout << "\n\nArray after insert 400 at End:";
	cout << "\nArray Size: " << MyDynamicArray.Size() << "\n";
	MyDynamicArray.PrintList();
}