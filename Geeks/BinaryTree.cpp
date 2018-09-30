#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node *left;
	Node *right;
};

Node * newNode(const int &data){
	Node *tmp = new Node;
	tmp -> data = data;
	tmp -> left = tmp -> right = NULL;
	return tmp;
}

int MaximumSumPath(Node *node, int &ans){
	if(node == NULL) return 0;
	int l = max(0, MaximumSumPath(node->left, ans));
	int r = max(0, MaximumSumPath(node->right, ans));
	int p = max(l, r) + node->data;
	ans = max(ans, max(p, l + r + node -> data));
	return p;
}
	
int LeafToLeafSum(Node *node, int &ans){
	if(node == NULL) return 0;
	int l = LeafToLeafSum(node->left, ans);
	int r = LeafToLeafSum(node->right, ans);
	ans = max(ans, l + r + node->data);
	if(node -> left == NULL) return r + node->data;
	if(node -> right == NULL) return l + node->data;
	return max(l, r) + node->data;
}

int height(Node *node){
	if(node == NULL) return 0;
	return max(height(node ->left), height(node ->right)) + 1;
}

int minDepth(Node* node) {
    if(node == NULL) return 0;
    if(node ->left == NULL && node->right == NULL) return 1;
    if(!node->left) return minDepth(node->right) + 1;
    if(!node->right) return minDepth(node->left) + 1;
    return min(minDepth(node->right), minDepth(node->left)) + 1;
}

void preorder(Node *node){
	if(node != NULL){
		cout<<node->data<<" ";
		preorder(node->left);
		preorder(node->right);
	}
}

void preorderNonRec(Node *node){
	stack<Node *> st;
	while(1){
		while(node != NULL){
			cout<<node->data<<" ";
			st.push(node);
			node = node->left;
		}
		if(st.empty())break;
		node = st.top()->right;
		st.pop();
	}
	cout<<endl;
}
		
void inorder(Node *node){
	if(node != NULL){
		inorder(node->left);
		cout<<node->data<<" ";
		inorder(node->right);
	}
}

void inorderNonRec(Node *node){
	stack<Node *> st;
	while(1){
		while(node != NULL){
			st.push(node);
			node = node->left;
		}
		if(st.empty())break;
		cout<<st.top()->data<<" ";
		node = st.top()->right;
		st.pop();
	}
	cout<<endl;
}

void postorder(Node *node){
	if(node != NULL){
		postorder(node->left);
		postorder(node->right);
		cout<<node->data<<" ";
	}
}

void postorderNonRec(Node *node){
	/*
	 * Differentiate whether we are returning from left subtree or right
	 * Each node is visited twice.
	 */
	stack<Node *> st;
	while(1){
		if(node != NULL){
			st.push(node);
			node = node->left;
			continue;
		}
		if(st.top()->right == NULL){
			node = st.top();
			st.pop();
			cout<<node->data<<" ";
		}
		while(!st.empty() && node == st.top()->right){
			node = st.top();
			st.pop();
			cout<<node->data<<" ";
		}
		if(!st.empty())
			node = st.top()->right;
		else break;
	}
	cout<<endl;
}

void spiralTraversal(Node *node){
	if(node == NULL) return;
	stack<Node *> s1;    // right to left
	stack<Node *> s2;    // left to right
	s1.push(node);
	while(!s1.empty() || !s2.empty()){
		while(!s1.empty()){
			Node *tmp = s1.top();
			s1.pop();
			cout<<tmp->data<<" ";
			if(tmp->right) s2.push(tmp->right);
			if(tmp->left) s2.push(tmp->left);
		}
		while(!s2.empty()){
			Node *tmp = s2.top();
			s2.pop();
			cout<<tmp->data<<" ";
			if(tmp->left) s1.push(tmp->left);
			if(tmp->right) s1.push(tmp->right);
		}
	}
}

int maxWidth(Node *node){
	int ans = 0;
    if(node == NULL) return ans;
	queue<Node *> Q;
	Q.push(node);
	while(!Q.empty()){
		int count = Q.size();
		ans = max(ans, count);
		while(count--){
			Node *tmp = Q.front();
			Q.pop();
			if(tmp->left) Q.push(tmp->left);
			if(tmp->right) Q.push(tmp->right);
			
		}
	}
	return ans;
}

void topView(Node *node, int id, map<int, int> &Map){
	if(node == NULL) return;
	if(Map.find(id) == Map.end()){
		Map.insert(make_pair(id, node->data));
	}
	topView(node->left, id-1, Map);
	topView(node->right, id+1, Map);
}
void printTopView(Node *root){
	cout<<"\n\nTop view of the tree is = ";
	map<int, int> Map;
	topView(root, 0, Map);
	for(map<int, int>::iterator it = Map.begin();it != Map.end();++it){
			cout<<it->second<<" ";
	}
}

void bottomView(Node *node, int id, map<int, int> &Map){
	if(node == NULL) return;
	queue<pair<Node *, int> > Q;
	Q.push(make_pair(node, 0));
	while(!Q.empty()){
		Node *tmp = Q.front().first;
		int id = Q.front().second;
		Map[id] = tmp->data;
		Q.pop();
		if(tmp->left) Q.push(make_pair(tmp->left, id - 1));
		if(tmp->right) Q.push(make_pair(tmp->right, id + 1));
	}
}

void printBottomView(Node *root){
	cout<<"\n\nBottom view of the tree is = ";
	map<int, int> Map;
	bottomView(root, 0, Map);
	for(map<int, int>::iterator it = Map.begin();it != Map.end();++it){
			cout<<it->second<<" ";
	}
}

void verticalTraversal(Node *node, int id, map<int, vector<int> > &Map){
	if(node == NULL) return;
	Map[id].push_back(node->data);
	verticalTraversal(node->left, id-1, Map);
	verticalTraversal(node->right, id+1, Map);
}

void printVerticalTraversal(Node *root){
	cout<<"\n\nVertical traversal of the tree is = ";
	map<int, vector<int> > Map;
	verticalTraversal(root, 0, Map);
	for(map<int, vector<int> >::iterator it = Map.begin();it != Map.end();++it){
		for(int i=0;i<(int)it->second.size();i++){
			cout<<it->second[i]<<" ";
		}
	}
}

void LeftView(Node *node, int currentLevel, int& level){
	if(node == NULL) return;
	if(level < currentLevel){
		level = currentLevel;
		cout<<node->data<<" ";
	}
	LeftView(node->left, currentLevel+1, level);
	LeftView(node->right, currentLevel+1, level);
}

void printLeftView(Node *node){
	cout<<"\n\nLeft view of the tree is = ";
	int tmp = 0;
	LeftView(node, 1, tmp);
}


void RightView(Node *node, int currentLevel, int& level){
	if(node == NULL) return;
	if(level < currentLevel){
		level = currentLevel;
		cout<<node->data<<" ";
	}
	RightView(node->right, currentLevel+1, level);
	RightView(node->left, currentLevel+1, level);
}

void printRightView(Node *node){
	cout<<"\n\nRight view of the tree is = ";
	int tmp = 0;
	RightView(node, 1, tmp);
}

void distantNodes(Node *node, int K){
	if(node ==NULL) return;
	if(K == 1){
		cout<<node->data<<" ";
		return ;
	}
	distantNodes(node->left, K-1);	
	distantNodes(node->right, K-1);	
}

bool printAncestor(Node *node, int x){
	if(node == NULL) return false;
	if(node->data == x) return true;
	if(printAncestor(node->left, x) || printAncestor(node->right, x)){
		cout<<node->data<<" ";
		return true;
	}
	return false;
}


/*
 * O(n^2) Method
 */
int diameterSlow(Node *node){
	if(node == NULL) return 0;
	int ld = diameterSlow(node->left);
	int rd = diameterSlow(node->right);
	int lh = height(node->left);
	int rh = height(node->right);
	return max(lh + rh +1, max(ld, rd));
}

/*
 * O(n) Method
 */
int diameter(Node *node, int *height){
	if(node == NULL){
		*height = 0;
		return *height;
	}
	int lh = 0, rh = 0, ld, rd;
	ld = diameter(node->left, &lh);
	rd = diameter(node->right, &rh);
	*height = max(lh, rh) + 1;
	return max(lh + rh +1, max(ld, rd));
}

bool checkRootToLeafPathSum(Node *node, int sum, int target){
    if(node == NULL) return false;
    if(node->data + sum == target && node->left==NULL && node->right == NULL){
        return true;
    }
    if(checkRootToLeafPathSum(node->left, node->data + sum, target) || checkRootToLeafPathSum(node->right, node->data + sum, target)) 
		return true;
    return false;
}

void sumPaths(Node* node, int sum, int target,  vector<vector<int> >& ans, vector<int> &cur){
    if(node == NULL) return;
    if(node->data + sum == target && node ->left == NULL && node->right == NULL){
        cur.push_back(node->data);
        ans.push_back(cur);
        cur.pop_back();
    }
    cur.push_back(node->data);
    sumPaths(node->left, node->data + sum, target, ans, cur);
    sumPaths(node->right, node->data + sum, target, ans, cur);
    cur.pop_back();
} 

vector<vector<int> > getSumPaths(Node* root, int target) {
    vector<vector<int> > ans;
    vector<int> cur;
    sumPaths(root, 0, target, ans, cur);
    return ans; 
}


bool leaf(Node *node){
    if(node == NULL) return 0;
    if(node->left == NULL && node->right == NULL) return 1;
    return 0;
}

bool isSumTree(Node* node){
    if(node == NULL || leaf(node)) return 1;
    
    if(isSumTree(node->left) && isSumTree(node->right)){
        int ls, rs;
        if(node->left == NULL)
            ls = 0;
        else if(leaf(node->left))
            ls = node->left->data;
        else
            ls = 2 * node->left->data;
        
        if(node->right == NULL)
            rs = 0;
        else if(leaf(node->right))
            rs = node->right->data;
        else
            rs = 2 * node->right->data;
        
        return (node->data == ls + rs);
    }
    return 0;
}


bool isBalanced(Node *node, int &h){
    if(node == NULL){
        h = 1;
        return true;
    }
    int lh = 0, rh = 0;
    bool l = isBalanced(node->left, lh);
    bool r = isBalanced(node->right, rh);
    
    h = (lh > rh ? lh : rh) + 1;
    
    if(abs(lh -rh) > 1){
        return false;
    }
    return l & r;
}


int main(){
    //Node *root = newNode(20);
    //root->left = newNode(8);
    //root->right = newNode(22);
    //root->left->left = newNode(5);
    //root->left->right = newNode(3);
    //root->right->left = newNode(4);
    //root->right->right = newNode(25);
    //root->left->right->left = newNode(10);
    //root->left->right->right = newNode(14);
    
    Node *root        = newNode(2);
    root->left        = newNode(8);
    root->right       = newNode(-3);
    root->left->left  = newNode(9);
    root->left->right = newNode(-7);
    root->left->right->left = newNode(5);
    root->left->right->right = newNode(-3);
    root->right->right = newNode(1);
    root->right->left= newNode(-8);
    root->right->right->left   = newNode(-6);
    root->right->right->right  = newNode(-1);
    root->left->left->right  = newNode(2);
    
    int ans = INT_MIN;
    MaximumSumPath(root, ans);
    cout<<"MaximumSumPath = "<<ans<<endl;
    ans = INT_MIN;
    LeafToLeafSum(root, ans);
    cout<<"LeafToLeafSum  = "<<ans<<endl;
    cout<<"Height = "<<height(root)<<endl;
    cout<<"Max width = "<<maxWidth(root)<<endl;
    
    
    cout<<"Preorder Traversal\n";
    preorderNonRec(root);
    preorder(root); cout<<endl<<endl;
    cout<<"Inorder Traversal\n";
    inorderNonRec(root);
    inorder(root);cout<<endl<<endl;
    cout<<"Postrder Traversal\n";
    postorderNonRec(root);
    postorder(root); cout<<endl<<endl;
    cout<<"spiral or zigzag Traversal\n";
    spiralTraversal(root);
    printVerticalTraversal(root);
    printTopView(root);
    printBottomView(root);
    printLeftView(root);
    printRightView(root);
    
    int k =3;
    cout<<"\n\nNodes at distance "<<k<<" are = ";
    distantNodes(root, k);
    
    int x = -6;
    cout<<"\n\nAncestors of "<<x<<" are = ";
    printAncestor(root, x);
    
    int height = 0;
    cout<<"\n\nDiameter = "<<diameter(root, &height)<<endl;
    
	return 0;
}



/*	TODO
 *  http://www.geeksforgeeks.org/construct-a-binary-tree-from-postorder-and-inorder/
 *  all such variations
 *  Morris Traversal
 */

