#include <bits/stdc++.h>
using namespace std;

class Node{
	
	private:
		static const int CHAR_SIZE = 26;
		
	public:
		Node *child[CHAR_SIZE];
		bool isLeaf;
		
		Node(){
			isLeaf = false;
			for(int i = 0; i < CHAR_SIZE; i++){
				child[i] = NULL;
			}
		}
		
		bool isLeafNode(){ 
			return (this != NULL && this->isLeaf); 
		}
		
		bool isFreeNode(){
			for(int i = 0; i < CHAR_SIZE; i++){
				if(this->child[i] != NULL){
					return false;
				}
			}
			return true;
		}
};


class Trie{
	
	private:
		Node *root;
		int no_of_words;

		void freeNode(Node *&node){
			free(node);
			node = NULL;
		}
		
		int getIndex(const char &c){
			if('A' <= c && c <= 'Z') return 26 + c - 'A';
			return c - 'a';
		}
		
		bool deleteNode(Node *&node, const string &s, const int &level){ 
			if(node == NULL) return false;
			 
			if(level == (int)s.length()){ 
				if(node->isLeafNode()){ 
					node->isLeaf = false;
					if(node->isFreeNode()){
						no_of_words -= 1; 
						return true; 
					}
					return false; 
				} 
			} 
			else{ 
				const int &id = getIndex(s[level]); 
				if(deleteNode(node->child[id], s, level + 1)){
					freeNode(node->child[id]);
					return (!node->isLeafNode() && node->isFreeNode()); 
				} 
			}
			return false; 
		}


	public:
		Trie(){
			root = new Node;
			no_of_words = 0;
		}

		void insert(const string &s){
			int len = (int)s.length();
			Node *c = root;
			bool new_word = false;
			for(int i = 0; i < len; i++){
				const int &id = getIndex(s[i]);
				if(c->child[id] == NULL){
					c->child[id] = new Node;
					new_word = true;
				}
				c = c->child[id];
			}
			c->isLeaf = true;
			if(new_word) no_of_words += 1;
		}

		bool search(const string &s){
			int len = (int)s.length();
			Node *c = root;
			for(int i = 0; i < len; i++){
				const int &id = getIndex(s[i]);
				if(c->child[id] == NULL){
					return false;
				}
				c = c->child[id];
			}
			return c->isLeafNode();
		}
		
		void deleteKey(const string &s){
			if((int)s.length() == 0) return;
			deleteNode(root, s, 0);
		}
		
		int getCount(){
			return no_of_words;
		}
};

int main(){
	Trie obj;
	string s;
	obj.insert("durgesh");
	obj.insert("kumar");
	obj.insert("kumarsoni");
	cout << obj.getCount() << endl;
	cout << "$$" << obj.search("durgesh") << endl;
	obj.deleteKey("durgesh");
	cout << "a #" << obj.search("durgesh") << endl;
	cout << "b #" << obj.search("kumar") << endl;
	cout << "c #" << obj.search("kumarsoni") << endl;
	obj.deleteKey("kumarsoni");
	cout << "d #" << obj.search("kumar") << endl;
	cout << "e #" << obj.search("kumarsoni") << endl;
	cout << obj.getCount() << endl;
	return 0;
}



