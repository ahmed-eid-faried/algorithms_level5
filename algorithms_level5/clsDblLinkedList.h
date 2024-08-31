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
		if (current == nullptr) return;
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
	void InsertAtEnd(T value) { _InsertAtEnd(_head, value); }
	void DeleteNode(Node*& NodeToDelete) { _DeleteNode(_head, NodeToDelete); }
	void DeleteLastNode() { _DeleteLastNode(_head); }
	void DeleteFirstNode() { _DeleteFirstNode(_head); }
	int Size() {
		return _Size;
	}
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

	cout << "\nSize of DblLinkedList:\n";
	cout << MydblLinkedList.Size() << endl;

}



template <class T>
class clsDblLinkedList2
{
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


	}
	void PrintList()

	{
		Node* Current = head;

		while (Current != NULL) {
			cout << Current->value << " ";
			Current = Current->next;
		}
		cout << "\n";


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

	}
};

