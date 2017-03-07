#include <bits/stdc++.h>
using namespace std;

struct Lnode{
	int data; 
	Lnode *next;
};

struct Tnode{
	int data;
	Tnode *left;
	Tnode *right;
};

Lnode *newLnode(const int& val){
	Lnode *ret = new Lnode;
	ret->data = val;
	ret->next = NULL;
	return ret;
}

void printList(Lnode *head){
	while(head != NULL){
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<endl;
}

void preorder(Tnode *node){
	if(node != NULL){
		cout<<node->data<<" ";
		preorder(node->left);
		preorder(node->right);
	}
}

Tnode *ListToBBST(Lnode *&head, int n){
	if(n <= 0) return NULL;
	Tnode *Left = ListToBBST(head, n/2);
	
	Tnode *root = new Tnode;
	root->data = head->data;
	root->left = Left;
	head = head->next;
	
	root->right = ListToBBST(head, n - n/2 -1);
	return root;
}

int main(){
	Lnode *head = NULL, *cur = NULL;
	int n, val;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>val;
		Lnode *tmp = newLnode(val);
		if(i == 0){
			head = cur = tmp;
			continue;
		}
		cur->next = tmp;
		cur = tmp;
	}
	printList(head);
	Tnode *root = NULL;
	Lnode *start = head;
	root = ListToBBST(start, n);
	preorder(root);

}
