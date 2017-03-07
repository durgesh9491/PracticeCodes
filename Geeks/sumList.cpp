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


Node *ListSumLSB(Node *node1, Node *node2, int& carry){
	if(node1 == NULL && node2 == NULL){
		if(carry == 0) return NULL;
		Node *tmp = new Node;
		tmp->data = carry;
		carry /= 10;
		tmp->next = ListSumLSB(node1, node2, carry);
		return tmp;
	}
	Node *tmp = new Node;
	int x = 0, y = 0, state = 0;
	if(node1 == NULL){
		state = 0;
		y = node2->data;
	}
	else if(node2 == NULL){
		state = 1;
		x  = node1->data;
	}
	else{
		state = 2;
		x  = node1->data;
		y = node2->data;
	}
	int sum = (x + y + carry);
	carry = sum / 10;
	sum %= 10;
	tmp->data = sum; 
	
	if(state == 0) tmp->next = ListSumLSB(node1, node2->next, carry);
	else if(state ==1) tmp->next = ListSumLSB(node1->next, node2, carry);
	else  tmp->next = ListSumLSB(node1->next, node2->next, carry);
	return tmp;
}


Node *ListSumMSB(Node *node1, Node *node2, int& carry){
	if(node1 == NULL && node2 == NULL) return NULL;
	Node *tmp = new Node;
	tmp->next = ListSumMSB(node1->next, node2->next, carry);
	int sum = node1->data + node2->data + carry;
	carry = sum/10;
	sum %= 10;
	tmp->data = sum;
	return tmp;
}

void joinList(Node *node, Node *&ref, Node *&headSum,  int& carry){
	if(node == ref){
		int sum = node->data + carry;
		carry = sum/10;
		sum %= 10;
		node->data = sum;
		node->next = headSum;
		return;
	}
	joinList(node->next, ref, headSum, carry);
	int sum = node->data + carry;
	carry = sum/10;
	sum %= 10;
	node->data = sum;
} 

Node *insertFront(Node *start, int &val){
	Node *tmp = new Node;
	tmp->data = val;
	tmp->next = start;
	return tmp;
}
int main(){
	Node *head1 = NULL, *head2= NULL, *cur = NULL;
	int n,n1,n2, val;
	
	/* Note: Assuming that n1 >= n2
	 * unused nodes of n1 is used as final list */
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>val;
		Node *tmp = newNode(val);
		if(i == 0){
			head1 = cur = tmp;
			continue;
		}
		cur->next = tmp;
		cur = tmp;
	}
	n1 = n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>val;
		Node *tmp = newNode(val);
		if(i == 0){
			head2 = cur = tmp;
			continue;
		}
		cur->next = tmp;
		cur = tmp;
	}
	n2 = n;
	
	int carry = 0;
	Node *headSum = NULL;
	headSum = ListSumLSB(head1, head2, carry);
	printList(headSum);
	
	carry = 0;
	int diff =  n1 - n2;
	Node *prev = NULL, *start = head1;
	while(diff>0){
		prev = head1;
		head1 = head1->next;
		--diff;
	}
	headSum = ListSumMSB(head1, head2, carry);
	joinList(start, prev, headSum, carry);
	if(carry > 0) headSum = insertFront(start, carry);
	printList(headSum);
	return 0;
}
