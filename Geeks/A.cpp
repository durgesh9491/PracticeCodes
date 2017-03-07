#include<bits/stdc++.h>
using namespace std;

priority_queue<int> pq;

int main(){
	int k, n, ele;
	/*
	 * input k : Number of elements in the array
	 * input n : find n largest elements in the given array
	 */
	cin >> k >> n;
	
	/*
	 * 	Taking input: array elements
	 *  Consturcting the priority queue (max heap)
	 *  Complexity: O(k * log(k))
	 * 	This can be done in O(k) construction method of heap, but the requirement of the problem attains the complexity of O(n * log(k)) which we'll see later on,
	 *  So, no need to take advantage of O(k) construction of heap as in worst case when n == k ; O(k) + O(k * log(k)) = O(k * log(k))
	 */
	for(int i = 1; i <= k;i++){
		cin>>ele;
		pq.push(ele);
	}
	/*
	 * Taking top element(maximum element) of the priority queue each time 
	 * Complexity of pop operation : O(1)
	 * Complexity to maintain heapify property : O(log(k))
	 * Overall complexity : O(n * log(k))
	 */
	while(!pq.empty() && n>0){
		int front = pq.top();
		pq.pop();
		--n;
		cout<< front << " ";
	}
	/*
	 * Upper bound of complexity : O((n + k) * log(k))
	 */
	
	return 0;
}
		
