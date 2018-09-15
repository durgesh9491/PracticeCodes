#include<bits/stdc++.h>
using namespace std;


struct Node{
	struct Node *left;
	struct Node *right;
	struct Node *next;
	int val;
};

struct Node* getNewNode(int val){
	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
	node->val = val;
	node->left = NULL;
	node->right = NULL;
	node->next = NULL;
	return(node);
}

/*
 * Function to obtain the next valid neighbour of the current node who calls it
 */
Node* getNextChild(Node *node){
    while(node){
        if(node->left)
            return node->left;
        if(node->right)
            return node->right;
        node = node->next ;
    }
    return node;
}


/*
 * Recursive function to get next pointer of each node 
 */
void constructNext(struct Node *cur){
	if(cur == NULL || (cur->left == NULL && cur->right == NULL))
		return;
	
	/*
	 * if current node has both the childs
	 */
	if(cur->left != NULL && cur->right != NULL){
		cur->left->next = cur->right;
		cur->right->next = getNextChild(cur->next);
	}
	/*
	 * if current node has only left child
	 * else check for right child
	 */
	else if(cur->left != NULL)
		cur->left->next = getNextChild(cur->next);
	else
		cur->right->next = getNextChild(cur->next);
		
	/*
	 * recur for both the childs
	 */ 
	constructNext(cur->right);
	constructNext(cur->left);
}



void solve(struct Node *root){
	if(root == NULL) return;
	root->next = root;
	constructNext(root);
}


int main(){
	/* 
	 * Sample test case
	 * Constructing the tree
	 * Intinitially next of each node is NULL 
	 */ 
	struct Node *root = getNewNode(10);
	root->left	 = getNewNode(20);
	root->right	 = getNewNode(30);
	root->left->left = getNewNode(40);
	root->right->left	 = getNewNode(50);
	
	solve(root);
	
	/* 
	 * print the next pointers of each node to verify the results 
	 * Some of them are
	 */
	 
	 cout<< root->right->val << " has next " << root->right->next->val <<endl;
	 cout<< root->left->left->val << " has next " << root->left->left->next->val <<endl;
	 cout<< root->right->left->val << " has next " << root->right->left->next->val <<endl;
	return 0;
}
