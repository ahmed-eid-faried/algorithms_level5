#pragma once
#include <iostream>
using namespace std;

template <class T>
class clsDynamicArray {
protected:
	T* TempArray;
	int _Size = 0;

public:
	T* OrignalArray;

	clsDynamicArray(int Size = 0) {
		if (Size < 0)Size = 0;
		_Size = Size;
		OrignalArray = new T[_Size];
	}

	~clsDynamicArray() {
		delete[] OrignalArray;
	}

	bool SetItem(int index, T value) {
		if (index >= 0 && index < _Size) {
			OrignalArray[index] = value;
			return true;
		}
		else { return false; }
	}

	int Size() { return _Size; }

	bool IsEmpty() { return Size() == 0; }

	void PrintList() {
		for (int i = 0; i < _Size; i++)
		{
			cout << OrignalArray[i] << " ";
		}
		cout << endl;
	}
};