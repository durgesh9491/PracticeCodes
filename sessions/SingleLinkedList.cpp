#include<bits/stdc++.h>
using namespace std;

class Node{
	public:
		int data;
		Node *next;
};


Node* createNode(int x){
	Node* node = new Node;
	node->data = x;
	node->next = NULL;
	return node;
}

void appendList(Node  *&head, Node *newNode){
	if(head == NULL){
		head = newNode;
	}
	else{
		Node *tmp = head;
		while(tmp -> next != NULL){
			tmp = tmp -> next;
		}
		tmp -> next = newNode;
	}
}

void freeList(Node *head){
	while(head != NULL){
		Node *tmp = head; 
		head = head -> next;
		delete(tmp);
	}
	
	cout << "\nList is destroyed"<< endl;
}

void customPrintForDelete(int data){
	cout << "\nNode with data :: " << data << " is deleted!" << endl;
}


void deleteNode(Node *&head, int targetElement){
	
	if(head == NULL){
		cout << "List is empty";
		return;
	}
	
	Node *prev = head;
	if(prev -> data == targetElement){
		head = head -> next;
		customPrintForDelete(prev -> data);
		delete(prev);
		return;
	}
	
	while(prev -> next != NULL && prev -> next -> data != targetElement){
		prev = prev -> next;
	}
	
	if(prev -> next != NULL && prev -> next -> data == targetElement){
		Node *nodeToBeDeleted = prev -> next;
		prev -> next = nodeToBeDeleted -> next;
		customPrintForDelete(nodeToBeDeleted -> data);
		delete(nodeToBeDeleted);
		return;
	}

	cout << "\nTarget element not found in list :: " << targetElement << endl;
}

void printSingleLinkedList(Node *tmp){
	cout << "\nLinkedList is ---->" << endl;
	
	int i = 1;
	while(tmp != NULL){
		cout << "Data " << i++ << " : " << tmp->data << endl;
		tmp = tmp -> next;
	}
}

void addElement(Node *&head, int position, int element){
}

int main(){
	int ele, nodes;
	Node *head = NULL;
		
	/*
	 * Creating the linkedList
	 */
	cout << "\nEnter number of nodes in the list : "; 
	cin >> nodes;
	for(int i = 1; i <= nodes; i++){
		cin >> ele;
		Node *newNode = createNode(ele);
	    appendList(head, newNode);
	}
	printSingleLinkedList(head);
	
	/*
	 * Deleting an element in the list
	 * provided: the list is having unique elements
	 */
	int targetElement;
	cout << "\nEnter the target element to delete : "; 
	cin >> targetElement;
	deleteNode(head, targetElement);
	printSingleLinkedList(head);
	
	
	/*
	 * Freeing the space
	 * Garbage collection
	 */
	freeList(head);
}




/**
 * 
 * 1 2
 */
	
