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

private:
	Node* _head = nullptr;
	static void _PrintList(Node* head) {
		cout << "NULL <--> ";
		while (head != nullptr) {
			cout << head->value << " <--> ";
			head = head->next;
		}
		cout << "NULL " << endl;
	}
	static void _InsertAtBeginning(Node*& head, T value) {
		Node* newNode = new Node();
		newNode->value = value;
		newNode->prev = nullptr;
		newNode->next = head;
		if (head != nullptr) {
			head->prev = newNode;
		}
		head = newNode;
	}
	static Node* _Find(Node* head, T value) {
		while (head != nullptr) {
			if (head->value == value)
				return head;
			head = head->next;
		}
		return nullptr;
	}
	static void _InsertAfter(Node* current, T value) {
		if (current == nullptr) return;
		Node* newNode = new Node();
		newNode->value = value;
		newNode->next = current->next;
		newNode->prev = current;
		if (current->next != nullptr) {
			current->next->prev = newNode;
		}
		current->next = newNode;
	}
	static void _InsertAtEnd(Node*& head, T value) {
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
	}
	static void _DeleteNode(Node*& head, Node*& NodeToDelete) {
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
	}
	static void _DeleteLastNode(Node*& head) {
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
	}
	static void _DeleteFirstNode(Node*& head) {
		if (head == nullptr) return;
		Node* temp = head;
		head = head->next;
		if (head != nullptr) {
			head->prev = nullptr;
		}
		delete temp;
	}

public:
	struct Node;
	// Public methods to manipulate the list
	void PrintList() { _PrintList(_head); }
	void InsertAtBeginning(T value) { _InsertAtBeginning(_head, value); }
	Node* Find(T value) { return _Find(_head, value); }
	void InsertAfter(Node* current, T value) { _InsertAfter(current, value); }
	void InsertAtEnd(T value) { _InsertAtEnd(_head, value); }
	void DeleteNode(Node*& NodeToDelete) { _DeleteNode(_head, NodeToDelete); }
	void DeleteLastNode() { _DeleteLastNode(_head); }
	void DeleteFirstNode() { _DeleteFirstNode(_head); }
};
// Example usage
void DblLinkedListEx() {
	clsDblLinkedList<int> MydblLinkedList;
	MydblLinkedList.InsertAtBeginning(5);
	MydblLinkedList.InsertAtBeginning(4);
	MydblLinkedList.InsertAtBeginning(3);
	MydblLinkedList.InsertAtBeginning(2);
	MydblLinkedList.InsertAtBeginning(1);
	cout << "\nLinked List Content:\n";
	MydblLinkedList.PrintList();
	clsDblLinkedList<int>::Node* N1 = MydblLinkedList.Find(2);
	if (N1 != nullptr)
		cout << "\nNode with value 2 is Found :-)\n";
	else
		cout << "\nNode is not found :-(\n";
	MydblLinkedList.InsertAfter(N1, 500);
	cout << "\nAfter Inserting 500 after 2:\n";
	MydblLinkedList.PrintList();
	MydblLinkedList.InsertAtEnd(700);
	cout << "\nAfter Inserting 700 at end:\n";
	MydblLinkedList.PrintList();
	clsDblLinkedList<int>::Node* N2 = MydblLinkedList.Find(4);
	MydblLinkedList.DeleteNode(N2);
	cout << "\nAfter Deleting 4:\n";
	MydblLinkedList.PrintList();
	MydblLinkedList.DeleteFirstNode();
	cout << "\nAfter Deleting First Node:\n";
	MydblLinkedList.PrintList();

	cout << "\nAfter Deleting Last Node:\n";
	MydblLinkedList.DeleteLastNode();
	MydblLinkedList.PrintList();
}
