#include<bits/stdc++.h>
using namespace std;

/*
 * LRU page replacement algorithm
 * DS: 1. Double linked list as queue(maintain order) to maintain requests, if full delete from tail
 * DS: 2. HashMap as cache table with key->data and value->address of node in DLL
 */

struct Node{
	int data;
	Node *left;
	Node *right;
};

Node * newNode(int &data){
	Node *node = new Node;
	node->data = data;
	node->left = node->right = NULL;
	return node;
}

void moveFront(Node *&head, Node *&tail, Node *ref){
	if(ref->left){
		if(ref->right){
			ref->left->right = ref->right;
			ref->right->left = ref->left;
		}
		else{
			tail = ref->left;
			ref->left->right = NULL;
		}
		ref->left = NULL;
		ref->right = head;
		head->left = ref;
		head = ref;
	}
}


int main(){
	int pages, frames;
	cin >> pages >> frames;
	vector<int> req(pages);
	for(int i = 0; i < pages; i++){
		cin >> req[i];
	}
	
	map<int, Node *> Map;
	Node *head = NULL;
	Node *tail = NULL;
	
	for(int i = 0; i < pages; i++){
		if(Map.find(req[i]) == Map.end()){
			cout << "M" << " |  ";
			Node *tmp = newNode(req[i]);
			if(head == NULL){
				tail = tmp;
			}
			else if((int)Map.size() < frames){
				tmp->right = head;
				head->left = tmp;
			}
			else{
				Node *lnode = tail;
				if((int)Map.size() > 1){
					tail = tail->left;
					tail->right = NULL;
					tmp->right = head;
					head->left = tmp;
				}
				else{
					tail = tmp;
				}
				Map.erase(lnode->data);
				free(lnode);
			}
			head = tmp;
			Map[req[i]] = tmp;
		}
		else{
			cout << "H" << " |  ";
			moveFront(head, tail, Map[req[i]]);
		}
		
		Node *st = head;
		while(st != NULL){
			cout << st -> data << " ";
			st = st->right;
		}
		cout << endl;
	}
}

/* Test: 15 3  7 0 1 2 0 3 0 4 2 3 0 3 2 1 2
 * Output
	M |  7 
	M |  0 7 
	M |  1 0 7 
	M |  2 1 0 
	H |  0 2 1 
	M |  3 0 2 
	H |  0 3 2 
	M |  4 0 3 
	M |  2 4 0 
	M |  3 2 4 
	M |  0 3 2 
	H |  3 0 2 
	H |  2 3 0 
	M |  1 2 3 
	H |  2 1 3 
*/
