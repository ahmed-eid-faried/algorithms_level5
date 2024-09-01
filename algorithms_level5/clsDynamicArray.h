#pragma once
template <class T>
class clsDynamicArray {
protected:
	int _Size = 0;
	T* _TempArray;
public:
	T* OrignalArray;

	clsDynamicArray(int Size = 0) {
		if (Size < 0)Size = 0;
		_Size = Size;
		OrignalArray = new T[_Size];
	}

	~clsDynamicArray() { delete[] OrignalArray; }

	SetItem(int index, T value) {
		OrignalArray[index] = value;
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