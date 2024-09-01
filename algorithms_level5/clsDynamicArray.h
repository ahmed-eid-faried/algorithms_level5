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

	void Resize(int newSize) {
		if (newSize < 0) 			newSize = 0;
		int minLength = min(newSize, _Size);

		T* tempArray = new T[newSize];  // ����� ������ ����� ������ ������

		// ��� ������� �� �������� ������� ��� �������� �������
		for (int i = 0; i < minLength; i++) {
			tempArray[i] = OrignalArray[i];
		}

		// ����� ������� �������
		delete[] OrignalArray;

		// ����� ������ ����� ��� �������� �������
		OrignalArray = tempArray;

		// ����� ����� ��� ����� ������
		_Size = newSize;
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
	T GetItem(int index) { return OrignalArray[index]; }
	void Reverse() {
		T* tempArray = new T[_Size];
		for (int i = 0; i < _Size; i++) {
			tempArray[i] = OrignalArray[_Size - i];
		}
		delete[] OrignalArray;
		OrignalArray = tempArray;
	}
	void Clear() {
		delete[] OrignalArray;
		_Size = 0;
	}
};