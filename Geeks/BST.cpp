#include <bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	int lcount;
	Node *left;
	Node *right;
};

Node * newNode(const int &data){
	Node *tmp = new Node;
	tmp -> data = data;
	tmp -> left = tmp -> right = NULL;
	return tmp;
}

Node* insert(Node *node, int val){
	if(node == NULL){
		return newNode(val);
	}
	if(val < node->data){
		node->left = insert(node->left, val);
		node->lcount++;
	}
	else  node->right = insert(node->right, val);
	return node;
}

bool search(Node *node, int key){
	if(node == NULL) return false;
	if(node->data == key) return true;
	if(node->data > key) return search(node->left, key);
	else return search(node->right, key);
}

void inorder(Node *node){
	stack<Node *> st;
	while(1){
		while(node != NULL){
			st.push(node);
			node = node->left;
		}
		if(st.empty()) break;
		cout<<st.top()->data<<" ";
		node = st.top()->right;
		st.pop();
	}
	cout<<endl;
}

void preorder(Node *node){
	if(node != NULL){
		cout<<node->data<<" ";
		preorder(node->left);
		preorder(node->right);
	}
}


int findInorderSuccesor(Node *node){
	while(node->left != NULL)
		node = node->left;
	return node->data;
}
	
Node*  deleteNode(Node *node, int key){
	if(node == NULL) return node;
	if(key < node->data) node->left = deleteNode(node->left, key);
	else if(key > node->data) node->right = deleteNode(node->right, key);
	else{
		if(node->left == NULL){
			Node *tmp = node->right;
			free(node);
			return tmp;
		}
		else if(node->right == NULL){
			Node *tmp = node->left;
			free(node);
			return tmp;
		}
		else{
			int inorderSuccesor = findInorderSuccesor(node->right);
			node->data = inorderSuccesor;
			node->right = deleteNode(node->right, inorderSuccesor);
		}
	}
	return node;
} 

int KthSmallest(Node *node, int k){
	while(node != NULL){
		if(node->lcount + 1 == k){
			return node->data;
		}
		if(k > node->lcount){
			k = k - (node->lcount+1);
			node = node->right;
		}
		else{
			node = node->left;
		}
	}
	return -1;
} 

void InorderSucPred(Node *node, int key, int &pred, int &suc){
	if(node == NULL) return;
	if(node->data == key){
		if(node->left != NULL){
			Node *tmp = node->left;
			while(tmp->right != NULL)
				tmp = tmp->right;
			pred = tmp->data;
		}

		if(node->right != NULL){
			Node *tmp = node->right;
			while(tmp->left != NULL)
				tmp = tmp->left;
			suc = tmp->data;
		}
		return;
	}
	if(node->data > key){
		suc = node->data;
		InorderSucPred(node->left, key, pred, suc);
	}
	else if(node->data < key){
		pred = node->data;
		InorderSucPred(node->right, key, pred, suc);
	}
}


void FloorCeil(Node *node, int key, int &floor, int &ceil){
	if(node == NULL) return;
	if(node->data == key){
		floor = ceil = key;
		return;
	}
	if(node->data > key){
		ceil = node->data;
		FloorCeil(node->left, key, floor, ceil);
	}
	else if(node->data < key){
		floor = node->data;
		FloorCeil(node->right, key, floor, ceil);
	}
}


int LCA(Node *node, int n1, int n2){
	if(node == NULL) return -1;
	if(node->data > n1 && node->data > n2) return LCA(node->left, n1, n2);
	if(node->data < n1 && node->data < n2) return LCA(node->right, n1, n2);
	if(search(node->left, min(n1, n2)) && search(node->right, max(n1, n2)))
		return node->data;
	return -1;
}

void isPairPresent(Node *node, int target){
	stack<Node *> s1, s2;
	bool f1 = false, f2 = false;
	/*
	 * norm : Normal inorder traversal iterator
	 * rev : Reverse inorder traversal iterator
	 */
	Node *norm = node, *rev = node;
	int cur1 = 0, cur2 = 0; 
  	while(1){
		while(!f1){
			if(norm != NULL){
				s1.push(norm);
				norm = norm->left;
				continue;
			}
			if(s1.empty()){
				f1 = true;
				break;
			}
			cur1 = s1.top()->data;
			norm = s1.top()->right;
			s1.pop();
			f1 = true;
		}
		
		while(!f2){
			if(rev != NULL){
				s2.push(rev);
				rev = rev->right;
				continue;
			}
			if(s2.empty()){
				f2 = true;
				break;
			}
			cur2 = s2.top()->data;
			rev = s2.top()->left;
			s2.pop();
			f2 = true;
		}
		
		if(cur1 != cur2 && cur1 + cur2 == target){
			cout<<"\nTarget sum exists\n";
			return;
		}
		if(cur1 + cur2 < target) f1 = false;
		else f2 = false;
		
		if(cur1 >= cur2){
			cout<<"\nTarget sum doesn't exists\n";
			return;
		}
	}
}

bool checkBST(Node *node, Node* &ref){
	if(node == NULL) return true;
	bool f1 = checkBST(node->left, ref);
	if(ref != NULL && ref->data > node->data) return false;
	ref = node;
	bool f2 = checkBST(node->right, ref);
	if(!f1 || !f2) return false;
	return true;
}

void correctBST(Node *node, Node *&first, Node *&middle, Node *&last, Node *&prev){
	if(node == NULL) return;
	correctBST(node->left, first, middle, last, prev);
	if(prev != NULL  && node->data < prev->data){
		if(middle == NULL){
			first = prev;
			middle = node;
		}
		else last = node;
	}
	prev = node; 
	correctBST(node->right, first, middle, last, prev);
}

void correctBSTUtil(Node *node){
	Node *first, *middle, *last, *prev;
	first = NULL, middle = NULL, last = NULL, prev = NULL;
	correctBST(node, first, middle, last, prev);
	if(first && last) swap(first->data, last->data);
	else if(first && middle) swap(first->data, middle->data);
}


void mergeBST(Node *node1, Node *node2){
	stack<Node *> s1, s2;
	/*
	 * cur1 : Normal inorder traversal iterator BST1
	 * cur2 : Normal inorder traversal iterator BST2
	 */
	Node *cur1 = node1, *cur2 = node2;
	int d1, d2;
  	while(1){
		while(cur1 != NULL){
			s1.push(cur1);
			cur1 = cur1->left;
		}
		if(!s1.empty()) d1 = s1.top()->data;

		while(cur2 != NULL){
			s2.push(cur2);
			cur2 = cur2->left;
		}
		if(!s2.empty()) d2 = s2.top()->data;
				
	    if(s1.empty() && s2.empty()) break;
	    
		if(s1.empty()){
			cout<<d2<<" ";
			cur2 = s2.top()->right;
			s2.pop();
			continue;
		}
		if(s2.empty()){
			cout<<d1<<" ";
			cur1 = s1.top()->right;
			s1.pop();
			continue;
		}
		
		if(d1 <= d2){
			cout<<d1<<" ";
			cur1 = s1.top()->right;
			s1.pop();
		}
		else{
			cout<<d2<<" ";
			cur2 = s2.top()->right;
			s2.pop();
		}
	}
}
		

int main(){
	Node *root = NULL;
	root = insert(root, 8);
	insert(root, 3);
	insert(root, 12);
	insert(root, 1);
	insert(root, 6);
	insert(root, 10);
	insert(root, 18);
	insert(root, 4);
	insert(root, 7);
	insert(root, 16);
	cout<<KthSmallest(root, 3)<<endl;
	cout<<KthSmallest(root, 5)<<endl;
	cout<<KthSmallest(root, 8)<<endl;
	
	inorder(root);
	if(search(root, 4)) cout<<"Key found\n";
	else cout<<"Key not found\n";
	
		
	/* NOTE:After deletion lcount may disturb */
	deleteNode(root, 4);	
	deleteNode(root, 18);	
	deleteNode(root, 6);	
	deleteNode(root, 12);	
	inorder(root);
	
	insert(root, 4);	
	insert(root, 18);	
	insert(root, 6);	
	insert(root, 12);	
	inorder(root);
	
	int pred = -1, suc = -1;
	InorderSucPred(root, 7, pred, suc);
	cout<<"\nPredecessor = "<<pred<<" "<<"\nSuccessor = "<<suc<<endl;
	
	/* NOTE: Concept similar to InorderSucPred */
	int floor = -1, ceil = -1;
	FloorCeil(root, 5, floor, ceil);
	cout<<"\nFor 5\nFloor = "<<floor<<" "<<"\nCeil = "<<ceil<<endl;
	
	cout<<"LCA of 1 and 7  is = "<< LCA(root, 1, 7)<<endl;
	cout<<"LCA of 5 and 18  is = "<< LCA(root, 5, 18)<<endl;
	
	/*checks whether a pair with given sum is present in BST
	 * Time : O(n), space: O(h) */
	isPairPresent(root, 29);
	Node *tmp = NULL;
	cout<<checkBST(root, tmp)<<endl;
	
	
	return 0;
	
}


