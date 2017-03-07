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


node *mergeList(node *ptrA,node* ptrB){
	node *ans = NULL;
	
	if(ptrA!=NULL && ptrB!=NULL){
		if(ptrA->data > ptrB->data) 
			ans = ptrB;
		else ans = ptrA;
	}
	if(ptrA==NULL) ans=ptrB;
	if(ptrB==NULL) ans=ptrA;
	
	node *currA= ptrA, *currB = ptrB;
	while(ptrA!=NULL && ptrB!=NULL){
		while(ptrA->next!= NULL && ptrA->next->data< ptrB->data){
				ptrA= ptrA->next;
				currA =ptrA;
		}
		while(ptrB->next!= NULL && ptrB->next->data < ptrA->data){
			ptrB= ptrB->next;
			currB =ptrB;
		}
		if(ptrA->data > ptrB->data){
			currB = ptrB->next;
			ptrB->next = ptrA;
			ptrB = currB;
		}
		else{
			currA = ptrA->next;
			ptrA->next = ptrB;
			ptrA = currA;
		}
	}
	return ans;
}



		
		
int main(){
	int m,n,d;
	node *rootA=NULL, *rootB=NULL;
    node *tmp,*curr;
	cin>>m>>n;
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
	curr=rootB;
	for(int i=0;i<n;i++){
		cin>>d;
		tmp = insert(d);
		if(rootB==NULL){
			rootB=tmp;
			curr=rootB;
			continue;
		}
		curr->next = tmp;
		curr = tmp; 
	}
	//printList(rootA);
	//printList(rootB);
	node *res=mergeList(rootA, rootB);
	printList(res);
	return 0;
}
	
	
	
	
	
	
