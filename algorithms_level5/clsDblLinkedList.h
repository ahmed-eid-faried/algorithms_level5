#pragma once
#include <iostream>
using namespace std;

template<class T>
class clsDblLinkedList {
public:
	struct Node {
		T value;
		Node* prev;
		Node* next;
	};
protected:
	int _Size = 0;

private:
	Node* _head = nullptr;
	void _PrintList(Node* head) {
		cout << "NULL <--> ";
		while (head != nullptr) {
			cout << head->value << " <--> ";
			head = head->next;
		}
		cout << "NULL " << endl;
	}
	Node* _Find(Node* head, T value) {
		while (head != nullptr) {
			if (head->value == value)
				return head;
			head = head->next;
		}
		return nullptr;
	}
	Node* _GetNode(Node* head, int index) {
		if (index >= _Size || index < 0) return nullptr;
		int counter = 0;
		while (head != nullptr) {
			if (counter == index) return head;
			head = head->next;
			counter++;
		}
		return nullptr;
	}
	T _GetItem(Node* head, int index) {
		Node* Item = _GetNode(head, index);
		return	((Item == nullptr) ? NULL : Item->value);
	}
	void _InsertAtBeginning(Node*& head, T value) {
		Node* newNode = new Node();
		newNode->value = value;
		newNode->prev = nullptr;
		newNode->next = head;
		if (head != nullptr) {
			head->prev = newNode;
		}
		head = newNode;
		_Size++;
	}
	void _InsertAfter(Node* current, T value) {
		if (current == nullptr) { return; }
		Node* newNode = new Node();
		newNode->value = value;
		newNode->next = current->next;
		newNode->prev = current;
		if (current->next != nullptr) {
			current->next->prev = newNode;
		}
		current->next = newNode;
		_Size++;
	}
	bool _InsertAfter(int index, T value) {
		Node* current = _GetNode(_head, index);
		if (current != NULL) {
			_InsertAfter(current, value);
			return true;
		}
		else { return false; }
	}
	void _InsertAtEnd(Node*& head, T value) {
		Node* newNode = new Node();
		newNode->value = value;
		newNode->next = nullptr;
		if (head == nullptr) {
			newNode->prev = nullptr;
			head = newNode;
		}
		else {
			Node* current = head;
			while (current->next != nullptr) {
				current = current->next;
			}
			current->next = newNode;
			newNode->prev = current;
		}
		_Size++;
	}
	void _DeleteNode(Node*& head, Node*& NodeToDelete) {
		if (head == nullptr || NodeToDelete == nullptr) return;
		if (head == NodeToDelete) {
			head = NodeToDelete->next;
		}
		if (NodeToDelete->prev != nullptr) {
			NodeToDelete->prev->next = NodeToDelete->next;
		}
		if (NodeToDelete->next != nullptr) {
			NodeToDelete->next->prev = NodeToDelete->prev;
		}
		delete NodeToDelete;
		NodeToDelete = nullptr;
		_Size--;
	}
	void _DeleteLastNode(Node*& head) {
		if (head == nullptr) return;
		if (head->next == nullptr) {
			delete head;
			head = nullptr;
			return;
		}
		Node* current = head;
		while (current->next != nullptr) {
			current = current->next;
		}
		if (current->prev != nullptr) {
			current->prev->next = nullptr;
		}
		delete current;
		_Size--;
	}
	void _DeleteFirstNode(Node*& head) {
		if (head == nullptr) return;
		Node* temp = head;
		head = head->next;
		if (head != nullptr) {
			head->prev = nullptr;
		}
		delete temp;
		_Size--;
	}
	void _Clear() {
		//for (int i = 0; i < _Size; i++) { _DeleteFirstNode(_head); }
		while (_Size > 0) { _DeleteFirstNode(_head); }
	}
	void _SwapNode(Node*& N) {
		Node* temp = N->next;
		N->next = N->prev;
		N->prev = temp;
	}
	void _Reverse(Node*& head) {
		//empty or one item
		if (head == nullptr || head->next == nullptr) return;
		Node* current = head;
		Node* temp = nullptr;
		// Swap next and prev for all nodes in the list
		while (current != nullptr) {
			_SwapNode(current);
			temp = current; // Save the last node (new head)
			current = current->prev; // Move to the next node (in reversed direction)
		}
		// Adjust head to point to the new head of the list
		head = temp;
	}
	bool _UpdateItem(int index, T value) {
		Node* Item = _GetNode(_head, index);
		if (Item != NULL) {
			Item->value = value;
			return true;
		}
		else { return false; }

	}
	//static int _Size(Node* head) {
	//	//int Counter = 0;
	//	//while (head != nullptr) {
	//	//	++Counter;
	//	//	head = head->next;
	//	//}
	//	//return Counter;
	//	return _Size;
	//}
public:
	// Public methods to manipulate the list
	void PrintList() { _PrintList(_head); }
	void InsertAtBeginning(T value) { _InsertAtBeginning(_head, value); }
	Node* Find(T value) { return _Find(_head, value); }
	void InsertAfter(Node* current, T value) { _InsertAfter(current, value); }
	bool InsertAfter(int index, T value) { return _InsertAfter(index, value); }
	void InsertAtEnd(T value) { _InsertAtEnd(_head, value); }
	void DeleteNode(Node*& NodeToDelete) { _DeleteNode(_head, NodeToDelete); }
	void DeleteLastNode() { _DeleteLastNode(_head); }
	void DeleteFirstNode() { _DeleteFirstNode(_head); }
	int Size() { return _Size; }
	bool IsEmpty() { return _Size == 0; }
	void Clear() { return _Clear(); }
	void Reverse() { return _Reverse(_head); }
	Node* GetNode(int index) { return _GetNode(_head, index); }
	T GetItem(int index) { return _GetItem(_head, index); }
	bool UpdateItem(int index, T value) { return _UpdateItem(index, value); }
};
  
 

template <class T>
class clsDblLinkedList2
{

protected:
    int _Size = 0;

public:

    class Node
    {

    public:
        T value;
        Node* next;
        Node* prev;
    };

    Node* head = NULL;

    void InsertAtBeginning(T value)
    {

        /*
            1-Create a new node with the desired value.
            2-Set the next pointer of the new node to the current head of the list.
            3-Set the previous pointer of the current head to the new node.
            4-Set the new node as the new head of the list.
        */

        Node* newNode = new Node();
        newNode->value = value;
        newNode->next = head;
        newNode->prev = NULL;

        if (head != NULL) {
            head->prev = newNode;
        }
        head = newNode;
        _Size++;

    }

    // Print the linked list
    void PrintList()

    {
        Node* Current = head;

        while (Current != NULL) {
            cout << Current->value << " ";
            Current = Current->next;
        }
        cout << "\n";
        delete Current;

    }

    Node* Find(T Value)
    {
        Node* Current = head;
        while (Current != NULL) {

            if (Current->value == Value)
                return Current;

            Current = Current->next;
        }

        return NULL;

    }

    void InsertAfter(Node* current, T value) {


        /*  1 - Create a new node with the desired value.
             2-Set the next pointer of the new node to the next node of the current node.
             3-Set the previous pointer of the new node to the current node.
             4-Set the next pointer of the current node to the new node.
             5-Set the previous pointer of the next node to the new node(if it exists).
        */

        Node* newNode = new Node();
        newNode->value = value;
        newNode->next = current->next;
        newNode->prev = current;

        if (current->next != NULL) {
            current->next->prev = newNode;
        }
        current->next = newNode;
        _Size++;

    }

    void InsertAtEnd(T value) {

        /*
            1-Create a new node with the desired value.
            2-Traverse the list to find the last node.
            3-Set the next pointer of the last node to the new node.
            4-Set the previous pointer of the new node to the last node.
        */


        Node* newNode = new Node();
        newNode->value = value;
        newNode->next = NULL;
        if (head == NULL) {
            newNode->prev = NULL;
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
            newNode->prev = current;
        }
        _Size++;

    }

    void DeleteNode(Node*& NodeToDelete) {

        /*
            1-Set the next pointer of the previous node to the next pointer of the current node.
            2-Set the previous pointer of the next node to the previous pointer of the current node.
            3-Delete the current node.
        */
        if (head == NULL || NodeToDelete == NULL) {
            return;
        }
        if (head == NodeToDelete) {
            head = NodeToDelete->next;
        }
        if (NodeToDelete->next != NULL) {
            NodeToDelete->next->prev = NodeToDelete->prev;
        }
        if (NodeToDelete->prev != NULL) {
            NodeToDelete->prev->next = NodeToDelete->next;
        }
        delete NodeToDelete;

        _Size--;
    }

    void DeleteFirstNode()
    {

        /*
            1-Store a reference to the head node in a temporary variable.
            2-Update the head pointer to point to the next node in the list.
            3-Set the previous pointer of the new head to NULL.
            4-Delete the temporary reference to the old head node.
        */

        if (head == NULL) {
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        delete temp;
        _Size--;
    }

    void DeleteLastNode() {

        /*
            1-Traverse the list to find the last node.
            2-Set the next pointer of the second-to-last node to NULL.
            3-Delete the last node.
        */

        if (head == NULL) {
            return;
        }

        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }

        Node* current = head;
        // we need to find the node before last node.
        while (current->next->next != NULL)
        {
            current = current->next;
        }

        Node* temp = current->next;
        current->next = NULL;
        delete temp;
        _Size--;
    }

    int Size()
    {
        return _Size;
    }

    bool IsEmpty()
    {
        return (_Size == 0 ? true : false);

    }

    void Clear()
    {
        while (_Size > 0)
        {
            DeleteFirstNode();
        }
    }


    void  Reverse()
    {
        Node* current = head;
        Node* temp = nullptr;
        while (current != nullptr) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }

        if (temp != nullptr) {
            head = temp->prev;
        }
    }

    Node* GetNode(int Index)
    {

        int Counter = 0;

        if (Index > _Size - 1 || Index < 0)
            return NULL;

        Node* Current = head;
        while (Current != NULL && (Current->next != NULL)) {

            if (Counter == Index)
                break;

            Current = Current->next;
            Counter++;

        }

        return Current;
    }

    T GetItem(int Index)
    {

        Node* ItemNode = GetNode(Index);

        if (ItemNode == NULL)
            return NULL;
        else
            return ItemNode->value;

    }

    bool UpdateItem(int Index, T NewValue)
    {
        Node* ItemNode = GetNode(Index);

        if (ItemNode != NULL)
        {
            ItemNode->value = NewValue;
            return true;
        }
        else
            return false;

    }


    bool InsertAfter(int Index, T value)
    {
        Node* ItemNode = GetNode(Index);
        if (ItemNode != NULL)
        {
            InsertAfter(ItemNode, value);
            return true;
        }
        else
            return false;
    }


};

