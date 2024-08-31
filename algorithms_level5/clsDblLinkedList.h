#pragma once
#include <iostream>
using namespace std;

template<class T>
class clsDblLinkedList {
private:
	Node<T>* _head = NULL;

public:
	struct Node {
		T value;
		Node* prev;
		Node* next;
	};

	// Print the linked list
	static void PrintList(Node<T>* head) {
		cout << "NULL <--> ";
		while (head != NULL) {
			cout << head->value << " <--> ";
			head = head->next;
		}
		cout << "NULL ";
		cout << endl;
	}
	void PrintList() { PrintList(_head); }

	static void InsertAtBeginning(Node<T>*& head, int value) {
		//1 - Create a new node with the desired value.
		//2 - Set the next pointer of the new node to the current head of the list.
		//3 - Set the previous pointer of the current head to the new node.
		//4 - Set the new node as the new head of the list.
		Node<T>* newNode = new Node<T>();

		newNode->value = value;
		newNode->prev = NULL;
		newNode->next = head;
		if (head != NULL) {
			head->prev = newNode;
		}
		head = newNode;
	}
	void InsertAtBeginning(int value) { InsertAtBeginning(_head, value); }

	Node<T>* Find(Node<T>* head, int Value) {
		while (head != NULL) {
			if (head->value == Value)
				return head;
			head = head->next;
		}
		return NULL;
	}
	Node<T>* Find(int value) { return Find(_head, value); }

	static void InsertAfter(Node<T>* current, int value) {
		//1 - Create a new node with the desired value.
		//2-Set the next pointer of the new node to the next node of the current node.
		//3-Set the previous pointer of the new node to the current node.
		//4-Set the next pointer of the current node to the new node.
		//5-Set the previous pointer of the next node to the new node(if it exists).
		Node<T>* newNode = new Node<T>();
		newNode->value = value;
		newNode->next = current->next;
		newNode->prev = current;

		current->next = newNode;
		if (current->next != NULL)	current->next->prev = newNode;
	}
	void InsertAfter(Node<T>* current, int value) { InsertAfter(current, value); }

	static void InsertAtEnd(Node<T>* head, int value) {
		//1-Create a new node with the desired value.
		//2-Traverse the list to find the last node.
		//3-Set the next pointer of the last node to the new node.
		//4-Set the previous pointer of the new node to the last node.
		Node<T>* newNode = new Node<T>();
		newNode->value = value;
		newNode->next = NULL;
		//4-Set the previous pointer of the new node to the last node.
		if (head == NULL) {
			newNode->prev = head;
			head = newNode;
		}
		else {
			Node<T>* current = head;
			while (current->next != NULL) {
				current = current->next;
			}
			current->next = newNode;
			newNode->prev = current;
		}
	}
	void InsertAtEnd(int value) { InsertAtEnd(_head, value); }

	static void DeleteNode(Node<T>*& head, Node<T>*& NodeToDelete) {
		//1-Set the next pointer of the previous node to the next pointer of the current node.
		//2-Set the previous pointer of the next node to the previous pointer of the current node.
		//3-Delete the current node.
		if (head == NULL || NodeToDelete == NULL)return;
		if (head == NodeToDelete)head = NodeToDelete;
		if (NodeToDelete->prev->next != NULL)NodeToDelete->prev->next = NodeToDelete->next;
		if (NodeToDelete->next->prev != NULL)NodeToDelete->next->prev = NodeToDelete->prev;
		delete NodeToDelete;
	}
	void DeleteNode(Node<T>*& NodeToDelete) { DeleteNode(_head, NodeToDelete); }

	static void DeleteLastNode(Node<T>*& head) {
		//1-Traverse the list to find the last node.
		//2-Set the next pointer of the second-to-last node to NULL.
		//3-Delete the last node.
		if (head == NULL)return;

		if (head->next == NULL) {
			delete head;
			head = NULL;
			return;
		}
		//Node<T>* current = head;
		//while (current->next->next != NULL) {
		//	current = current->next;
		//}
		//Node<T>* temp = current->next;
		//current->next = NULL;
		//delete temp;
		Node<T>* current = head;
		while (current->next != NULL) {
			current = current->next;
		}
		Node<T>* temp = current;
		current->prev->next = NULL;
		delete temp;
	}
	void DeleteLastNode() { DeleteLastNode(_head); }

	static void DeleteFirstNode(Node<T>*& head) {
		//1-Store a reference to the head node in a temporary variable.
		//2-Update the head pointer to point to the next node in the list.
		//3-Set the previous pointer of the new head to NULL.
		//4-Delete the temporary reference to the old head node.
		if (head == NULL)return;
		Node<T>* temp = head;
		head = head->next;
		if (head != NULL)head->prev = NULL;
		delete temp;
	}
	void DeleteFirstNode() { DeleteFirstNode(_head); }
};


void DblLinkedListEx() {
	clsDblLinkedList <int> MydblLinkedList;

	MydblLinkedList.InsertAtBeginning(5);
	MydblLinkedList.InsertAtBeginning(4);
	MydblLinkedList.InsertAtBeginning(3);
	MydblLinkedList.InsertAtBeginning(2);
	MydblLinkedList.InsertAtBeginning(1);

	cout << "\nLinked List Contenet:\n";
	MydblLinkedList.PrintList();

	clsDblLinkedList<int>::Node* N1 = MydblLinkedList.Find(2);

	if (N1 != NULL)
		cout << "\nNode with value 2 is Found :-)\n";
	else
		cout << "\nNode Is not found :-(\n";

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