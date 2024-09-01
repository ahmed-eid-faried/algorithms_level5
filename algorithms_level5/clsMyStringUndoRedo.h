#pragma once
#include <iostream>
#include <stack>
using namespace std;

class clsMyString {
private:
	stack<string> _UndoList;
	stack<string> _RedoList;
	string _Value = "";

public:
	clsMyString() { SetValue(""); }
	// Get and Set for _Value property
	void SetValue(string Value) {
		_UndoList.push(Value);
		_Value = Value;
	}

	string GetValue() {
		return _Value;
	}
	__declspec(property(get = GetValue, put = SetValue)) string Value;

	// Undo the last change
	void Undo() {
		if (!_UndoList.empty()) {
			_RedoList.push(_Value);
			_UndoList.pop();
			_Value = _UndoList.top();
		}
	}

	// Redo the last undone change
	void Redo() {
		if (!_RedoList.empty()) {
			_Value = _RedoList.top();
			_UndoList.push(_Value);
			_RedoList.pop();
		}
	}
};
