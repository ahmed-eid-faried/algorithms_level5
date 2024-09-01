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

		T* tempArray = new T[newSize];  // ÊÎÕíÕ ãÕÝæÝÉ ÌÏíÏÉ ÈÇáÍÌã ÇáÌÏíÏ

		// äÓÎ ÇáÚäÇÕÑ ãä ÇáãÕÝæÝÉ ÇáÃÕáíÉ Åáì ÇáãÕÝæÝÉ ÇáÌÏíÏÉ
		for (int i = 0; i < minLength; i++) {
			tempArray[i] = OrignalArray[i];
		}

		// ÊÍÑíÑ ÇáÐÇßÑÉ ÇáÞÏíãÉ
		delete[] OrignalArray;

		// ÊÍÏíË ÇáãÄÔÑ áíÔíÑ Åáì ÇáãÕÝæÝÉ ÇáÌÏíÏÉ
		OrignalArray = tempArray;

		// ÊÍÏíË ÇáÍÌã Åáì ÇáÍÌã ÇáÌÏíÏ
		_Size = newSize;
	}
	bool DeleteItem(T value) {
		_Size--;
		if (_Size < 0) _Size = 0;
		T* tempArray = new T[_Size];
		int counter = 0;
		int IsFind = false;
		for (int i = 0; i < _Size; i++) {
			if (OrignalArray[counter] == value) {
				counter++;
				IsFind = true;
			}
			tempArray[i] = OrignalArray[counter];
			counter++;
		}
		delete[] OrignalArray;
		OrignalArray = tempArray;
		return IsFind;
	}
	bool DeleteItemAt(int index) {
		if (index >= _Size || index < 0)return false;
		_Size--;
		if (_Size < 0) _Size = 0;
		T* tempArray = new T[_Size];
		//before index
		for (int i = 0; i < index; i++) {
			tempArray[i] = OrignalArray[i];
		}
		//after index
		for (int i = index + 1; i < _Size + 1; i++) {
			tempArray[i - 1] = OrignalArray[i];
		}
		delete[] OrignalArray;
		OrignalArray = tempArray;
		return true;
	}
	bool DeleteFirstItem() {
		return DeleteItemAt(0);
	}
	bool DeleteLastItem() {
		return DeleteItemAt(_Size - 1);
	}
	bool SetItem(int index, T value) {
		if (index >= 0 && index < _Size) {
			OrignalArray[index] = value;
			return true;
		}
		else { return false; }
	}
	int Find(T value) {
		for (int i = 0; i < _Size; i++) {
			if (OrignalArray[i] == value) return i;
		}
		return -1;
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
	T GetItem(int index) {
		return OrignalArray[index];
	}
	void Reverse() {
		T* tempArray = new T[_Size];
		for (int i = 0; i < _Size; i++) {
			tempArray[i] = OrignalArray[_Size - 1 - i];
		}
		delete[] OrignalArray;
		OrignalArray = tempArray;
	}
	void Clear() {
		delete[] OrignalArray;
		_Size = 0;
		OrignalArray = new T[_Size];
	}
};