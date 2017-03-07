#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node* next;
};

bool detect_loop(node* head){
	if(head==NULL)
	return false;
	node* slow=head;
	node* fast=head;
	
	while(fast->next!=NULL && fast->next->next!=NULL){
		slow=slow->next;
		fast=fast->next->next;
		if(slow==fast)
		return true;
	}
	return false;
}


node* remove_loop(node* head){
	node* slow=head;
	node* fast=head;
	node* prev = NULL;
	if(head == NULL) return head;
	
	bool flag = false;
	while(fast->next!=NULL && fast->next->next!=NULL){
		prev = slow;
		slow=slow->next;
		fast=fast->next->next;
		if(slow==fast){
			flag  = true;
			break;
		}
	}
	slow = head;
	while(1 && flag){
		if(fast == head){
			prev->next = NULL;
			break;
		}
		prev = fast;
		fast = fast->next;
		slow = slow->next;
		if(fast == slow){
			prev->next = NULL;
			break;
		}
	}
	return head;
}


void print_list(node *head){
	while(head != NULL){
		cout<<head->data<<" ";
		head = head->next;
	}
}
int main(){
	node* head=NULL;
	node* n1=new node();
	node* n2=new node();
	node* n3=new node();
	node* n4=new node();
	node* n5=new node();

	n1->data=10; n2->data=20; n3->data=30; n4->data=40; n5->data=50;
	head=n1; n1->next=n2; n2->next=n3; n3->next=n4; n4->next=n5;n5->next=n2;
	
	bool loop=detect_loop(head);
	if(loop)
		cout<<"loop exists"<<endl;
	else
		cout<<"no loop"<<endl;

	head=remove_loop(head);
	

	print_list(head);
	return 0;
}
