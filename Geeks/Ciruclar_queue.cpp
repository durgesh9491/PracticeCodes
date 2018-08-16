#include<bits/stdc++.h>
using namespace std;

//traces
#define SP                   system("pause")
#define dbg1(x)              cerr<<__FUNCTION__<<" : "<<__LINE__<<" : "#x" = "<<x<<endl;
#define dbg2(x,y)            cerr<<__FUNCTION__<<" : "<<__LINE__<<" : "#x" = "<<x<<" | "#y" = "<<y<<endl;
#define dbg3(x,y,z)          cerr<<__FUNCTION__<<" : "<<__LINE__<<" : "#x" = "<<x<<" | "#y" = "<<y<<" | "#z" = "<<z<<endl;
#define dbg4(a,b,c,d)        cerr<<__FUNCTION__<<" : "<<__LINE__<<" : "#a" = "<<a<<" | "#b" = "<<b<<" | "#c" = "<<c<<" | "#d" = "<<d<<endl;
#define dbg5(a,b,c,d,e)      cerr<<__FUNCTION__<<" : "<<__LINE__<<" : "#a" = "<<a<<" | "#b" = "<<b<<" | "#c" = "<<c<<" | "#d" = "<<d<<" | "#e" = "<<e<<endl;
#define ds                   cerr<<__FUNCTION__<<" : "<<__LINE__<<" : ----- I am Here -----\n";



class Queue{
	private:
		int front, rear, size, cap;
		int *array;
	
	public:
		Queue(const int &capacity){
			cap = capacity;
			front = size = 0;
			rear = cap - 1;
			array = new int[cap];
		}
		
		void enqueue(const int &item){
			if(isFull()){
				cout << "Queue is full\n";
				return;
			}
			rear = (rear + 1) % cap;
			array[rear] = item;
			size += 1;
		}
		
		int dequeue(){
			if(isEmpty()){
				cout << "Queue is empty\n";
				return INT_MAX;
			}
			int item = array[front];
			front = (front + 1) % cap;
			size -= 1;
			return item;
		}
		
		void print(){
			int temp = front;
			for(int i = 0; i < size; i += 1){
				cout << array[temp] << " ";
				temp = (temp + 1) % cap;
			}
		}
		
	private:
		bool isFull(){
			return size == cap;
		}
		
		bool isEmpty(){
			return size == 0; 
		}
	
};
	
int main(){
	int cap, q, inp, item;
	cin >> cap >> q;
	Queue Q(cap);
	while(q--){
		cin >> inp;
		switch(inp){
			case 1:
				cin >> item;
				Q.enqueue(item);
				Q.print();
				break;
			
			case 2:
				item = Q.dequeue();
				if(item != INT_MAX){
					cout << item << endl; 
				}
				Q.print();
				break;
				
			case 3:
				Q.print();
				break;
		}
	}
}

