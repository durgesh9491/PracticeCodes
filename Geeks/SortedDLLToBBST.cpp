#include <bits/stdc++.h>
using namespace std;

struct Dnode{
	int data; 
	Dnode *next;
	Dnode *prev;
};

Dnode *newLnode(const int& val){
	Dnode *ret = new Dnode;
	ret->data = val;
	ret->next = ret->prev = NULL;
	return ret;
}

void printList(Dnode *head){
	while(head != NULL){
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<endl;
}

void preorder(Dnode *node){
	if(node != NULL){
		cout<<node->data<<" ";
		preorder(node->prev);
		preorder(node->next);
	}
}

Dnode *DLLToBBST(Dnode *&head, int n){
	if(n <= 0) return NULL;
	Dnode *left = DLLToBBST(head, n/2);
	Dnode *root = head;
	root->prev = left;
	head = head->next;
	root->next = DLLToBBST(head, n - n/2 -1);
	return root;
}

int main(){
	Dnode *head = NULL, *cur = NULL;
	int n, val;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>val;
		Dnode *tmp = newLnode(val);
		if(i == 0){
			head = cur = tmp;
			continue;
		}
		cur->next = tmp;
		tmp->prev = cur;
		cur = tmp;
	}
	printList(head);
	Dnode *root = NULL;
	Dnode *start = head;
	root = DLLToBBST(start, n);
    preorder(root);
	return 0;
}
