#pragma once
#include <iostream>
#include <cmath>
using namespace std;

template <class T>
class clsDynamicArray {
protected:
	T* _TempArray;
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

	void Resize(int Size) {
		if (Size < 0)Size = 0;
		int MinLength = min(Size, _Size);
		_Size = Size;
		_TempArray = OrignalArray;
		OrignalArray = new T[_Size];
		for (int i = 0; i < MinLength; i++)
		{
			OrignalArray[i] = _TempArray[i];
		}
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