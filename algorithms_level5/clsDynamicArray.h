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
	T* OriginalArray;

	clsDynamicArray(int Size = 0) {
		if (Size < 0)Size = 0;
		_Size = Size;
		OriginalArray = new T[_Size];
	}
	~clsDynamicArray() {
		delete[] OriginalArray;
	}
	void Resize(int newSize) {
		if (newSize < 0) 			newSize = 0;
		int minLength = min(newSize, _Size);

		T* tempArray = new T[newSize];  // ÊÎÕíÕ ãÕÝæÝÉ ÌÏíÏÉ ÈÇáÍÌã ÇáÌÏíÏ

		// äÓÎ ÇáÚäÇÕÑ ãä ÇáãÕÝæÝÉ ÇáÃÕáíÉ Åáì ÇáãÕÝæÝÉ ÇáÌÏíÏÉ
		for (int i = 0; i < minLength; i++) {
			tempArray[i] = OriginalArray[i];
		}

		// ÊÍÑíÑ ÇáÐÇßÑÉ ÇáÞÏíãÉ
		delete[] OriginalArray;

		// ÊÍÏíË ÇáãÄÔÑ áíÔíÑ Åáì ÇáãÕÝæÝÉ ÇáÌÏíÏÉ
		OriginalArray = tempArray;

		// ÊÍÏíË ÇáÍÌã Åáì ÇáÍÌã ÇáÌÏíÏ
		_Size = newSize;
	}
	bool DeleteItem2(T value) {
		_Size--;
		if (_Size < 0) _Size = 0;
		T* tempArray = new T[_Size];
		int counter = 0;
		int IsFind = false;
		for (int i = 0; i < _Size; i++) {
			if (OriginalArray[counter] == value) {
				counter++;
				IsFind = true;
			}
			tempArray[i] = OriginalArray[counter];
			counter++;
		}
		delete[] OriginalArray;
		OriginalArray = tempArray;
		return IsFind;
	}
	bool DeleteItemAt(int index) {
		if (index >= _Size || index < 0)return false;
		_Size--;
		if (_Size < 0) _Size = 0;
		T* tempArray = new T[_Size];
		//before index
		for (int i = 0; i < index; i++) {
			tempArray[i] = OriginalArray[i];
		}
		//after index
		for (int i = index + 1; i < _Size + 1; i++) {
			tempArray[i - 1] = OriginalArray[i];
		}
		delete[] OriginalArray;
		OriginalArray = tempArray;
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
			OriginalArray[index] = value;
			return true;
		}
		else { return false; }
	}
	//as setitem
	bool UpdateItem(int index, T value) {
		if (index >= _Size || index < 0)return false;
		OriginalArray[index] = value;
		return true;
	}
	int Find(T value) {
		for (int i = 0; i < _Size; i++) {
			if (OriginalArray[i] == value) return i;
		}
		return -1;
	}
	bool DeleteItem(T value) {
		int index = Find(value);
		if (index == -1) {
			return false;
		}
		else {
			return DeleteItemAt(index);
		}
	}
	int Size() {
		return _Size;
	}
	bool IsEmpty() {
		return Size() == 0;
	}
	void PrintList() {
		for (int i = 0; i < _Size; i++)
		{
			cout << OriginalArray[i] << " ";
		}
		cout << endl;
	}
	T GetItem(int index) {
		return OriginalArray[index];
	}
	void Reverse() {
		T* tempArray = new T[_Size];
		for (int i = 0; i < _Size; i++) {
			tempArray[i] = OriginalArray[_Size - 1 - i];
		}
		delete[] OriginalArray;
		OriginalArray = tempArray;
	}
	void Clear() {
		delete[] OriginalArray;
		_Size = 0;
		OriginalArray = new T[_Size];
	}
	bool InsertAt(T index, T value) {
		if (index > _Size || index < 0)	return false;
		_Size++;
		_TempArray = new T[_Size];

		//copy all before index
		for (int i = 0; i < index; i++)
		{
			_TempArray[i] = OriginalArray[i];
		}
		_TempArray[index] = value;
		//copy all after index
		for (int i = index; i < _Size - 1; i++)
		{
			_TempArray[i + 1] = OriginalArray[i];
		}

		delete[] OriginalArray;
		OriginalArray = _TempArray;
		return true;
	}
	bool InsertAtBeginning(T value) {
		return InsertAt(0, value);
	}
	bool InsertAtEnd(T value) {
		return InsertAt(_Size, value);
	}
	bool InsertBefore(int index, T value) {
		if (index < 1)index = 1;
		return InsertAt(index - 1, value);
	}
	bool InsertAfter(int index, T value) {
		if (index >= _Size)index = _Size - 1;
		return InsertAt(index + 1, value);
	}

};