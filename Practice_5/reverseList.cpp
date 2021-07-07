#include <bits/stdc++.h>
using namespace std;


struct Node {
	int data;
	struct Node* next;
	Node(int data)
	{
		this->data = data;
		next = NULL;
	}
};

struct LinkedList {
	Node* head;
	LinkedList() 
    { 
        head = NULL; 
    }

	void reverseList()
	{
		Node* curr = head;
		Node *prev = NULL, *next = NULL;

		while (curr != NULL) {
			
			next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}

		head = prev;
	}

	void printList()
	{
		struct Node* temp = head;
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
	}

	void push(int data)
	{
		Node* tmp = new Node(data);
		tmp->next = head;
		head = tmp;
	}
};


int main()
{
	LinkedList list;
	list.push(1);
	list.push(2);
	list.push(3);
	list.push(4);

	cout << "Given linked list\n";
	list.printList();

	list.reverseList();

	cout << "\nReversed Linked list \n";
	list.printList();
	return 0;
}
