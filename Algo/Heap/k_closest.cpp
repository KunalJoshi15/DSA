#include<bits/stdc++.h>

using namespace std;

void printKClosest(int arr[], int n, int k, int x)
{
	// here the visited array is used to tell whether the particular element is already visited or not.
    bool visited[n]={false};
    
    for(int i=0;i<k;i++){
        // k times we will be finding the values which has the smallest absolute difference.
        int min_diff=INT_MAX;
        int min_diff_idx;
        // we will be storing the index of the min element which has been found and once a particular element is 
        // visited then we cannot visit it again.
        for(int j=0;j<n;j++){
            if(visited[j]==false && abs(arr[j]-x)<=min_diff){
                min_diff=abs(arr[j]-x);
                min_diff_idx=j;
            }
        }
        cout<<arr[min_diff_idx]<<" ";
        visited[min_diff_idx]=true;
    }
}

void effKClosest(int arr[],int n,int val,int k){
	priority_queue<pair<int,int>> pq;

	for(int i=0;i<k;i++){
		pq.push({abs(arr[i]-val),i});
	}

	for(int i=k;i<n;i++){
		int diff = abs(arr[i]-val);
		if(diff<pq.top().first){
			pq.pop();
			pq.push({diff,i});
		}
	}
	// At last there will be only k elements present in the heap.
	while(pq.empty()==false){
		cout<<(arr[pq.top().second])<<endl;
		pq.pop();
	}
}

int main()
{
	int arr[] = { 11, 3, 2, 1, 15, 5, 4, 45, 88, 96, 50, 45 };

	int size = sizeof(arr) / sizeof(arr[0]);

	int k = 3;
	int val = 12;

	effKClosest(arr,size,val,k);
}