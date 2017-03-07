#include <bits/stdc++.h>
using namespace std;


struct node{
	int data;
	struct node* next;
};


node* insert(const int& data){
	node *tmp = (node *)malloc(sizeof(node));
	tmp->data =data;
	tmp->next =NULL;
	return tmp;
}
	

void printList(node *root){
	while(root!=NULL){
		cout<<root->data<<" ";
		root= root->next;
	}
	cout<<endl<<endl;
}
	
		
int main(){
	int n,d;
	node *rootA=NULL;
    node *tmp,*curr;
	cin>>n;
	for(int i=0;i<m;i++){
		cin>>d;
		tmp = insert(d);
		if(rootA==NULL){
			rootA=tmp;
			curr=rootA;
			continue;
		}
		curr->next = tmp;
		curr = tmp; 
	}
	printList(rootA);
	reverse(rootA);
	printList(rootA);
	return 0;
}
	
	
	
	
	
	
