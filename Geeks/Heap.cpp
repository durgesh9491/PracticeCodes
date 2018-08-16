#include<bits/stdc++.h>
using namespace std;

class MinHeap{
	private:
		int size, *array;
	
	public:
		MinHeap(int &cap, int *inp){
			size = cap;
			array = inp;
			build();
			print();
		}
		

		int top(){
			if(isEmpty()) return -1;
			return array[0];
		}
		
		int pop(){
			if(isEmpty()) return -1;
			int idx = 0;
			int item = array[idx];
			array[idx] = array[--size];
			heapify(idx);
			return item;
		}
			
		void print(){
			for(int i = 0; i < size; i++){
				cout << array[i] << " ";
				cout << endl;
			}
		}
	
	private:
		bool isEmpty(){
			return size == 0;
		}
		
		int leftChild(int& idx) const{ 
			int id = 2 * idx + 1;
			return (id >= size ? -1 : id);
		}
		
		int rightChild(int& idx) const{
			int id = 2 * idx + 2;
			return (id >= size ? -1 : id);
		}
		
		void heapify(int& idx){
			int left = leftChild(idx);
			int right = rightChild(idx);
		    int temp = idx;
		    if(left != -1 && array[temp] > array[left]){	               4 
				temp = left;
			}
			if(right != -1 && array[temp] > array[right]){
				temp = right;
			}
			if(temp != idx){
				swap(array[idx], array[temp]);
				heapify(temp);
			}
		}
		
		void build(){
			for(int i = (size - 1)/2; i >= 0; i--){
				heapify(i);
			}
		}
};



int main(){
	int cap, q, inp, item;
	cin >> cap >> q;
	int array[cap];
	for(int i = 0; i < cap; i++){
		cin >> array[i]; 
	}
	MinHeap H(cap, array);
	while(q--){
		cin >> inp;
		switch(inp){
			case 1:
				item = H.pop();
				if(item != INT_MAX){
					cout << item << endl; 
				}
				break;

			case 2:
				cout << H.top() << endl;
				break;
			
			default:
				H.print();
		}
	}
}
