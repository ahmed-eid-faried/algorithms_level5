#include <iostream>
#include "clsDynamicArray.h"

using namespace std;

void clsDynaminArrayEx()
{

	clsDynamicArray <int> MyDynamicArray(5);

	MyDynamicArray.SetItem(0, 10);
	MyDynamicArray.SetItem(1, 20);
	MyDynamicArray.SetItem(3, 40);
	MyDynamicArray.SetItem(4, 50);
	MyDynamicArray.SetItem(2, 30);


	cout << "\nIs Empty?  " << MyDynamicArray.IsEmpty();
	cout << "\nArray Size: " << MyDynamicArray.Size() << "\n";
	cout << "\nArray Items: \n";

	MyDynamicArray.PrintList();
}