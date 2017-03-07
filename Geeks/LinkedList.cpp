#include <bits/stdc++.h>
using namespace std;

struct Node{
	int data; 
	Node *next;
};

Node *newNode(const int& val){
	Node *ret = new Node;
	ret->data = val;
	ret->next = NULL;
	return ret;
}

void printList(Node *head){
	while(head != NULL){
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<endl;
}

void reverseIt(Node *&head){
	if(head == NULL || head->next == NULL) return;
	Node *cur = head->next, *prev1 = head, *prev2 = NULL;
	while(cur != NULL){
		prev1->next = prev2;
		prev2 = prev1;
		prev1 = cur;
		cur = cur->next;
	}
	prev1->next = prev2;
	head = prev1;
}


void reverseRec(Node *node, Node *prev, Node *&refHead){
	if(node->next == NULL){
		refHead = node;
		node->next = prev;
		return;
	}
	reverseRec(node->next, node, refHead);
	node->next = prev;
}

int main(){
	Node *head = NULL, *cur = NULL;
	int n, val;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>val;
		Node *tmp = newNode(val);
		if(i == 0){
			head = cur = tmp;
			continue;
		}
		cur->next = tmp;
		cur = tmp;
	}
	reverseIt(head);
	cout<<"Reverse Iterative = "; printList(head);
	Node *start = head;
	reverseRec(start, NULL, head);
	cout<<"Reverse Recursive = ";printList(head);
	return 0;
}
