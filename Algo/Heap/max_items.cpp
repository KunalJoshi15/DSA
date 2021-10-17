#include<bits/stdc++.h>

using namespace std;

void naiveMax(int cost[],int n,int sum){
	int res=0;

	sort(cost,cost+n);
    for(int i=0;i<n;i++){
        if(cost[i]<=sum){
            sum-=cost[i];
            res++;
        }else{
            break;
        }
    }
    cout<<res;
}

void efficientMax(int cost[],int n,int sum){
	priority_queue<int,vector<int>,greater<int>> pq;
    // min heap is created in this particular case.
    int res=0;
    // all the elements of the array are pushed into the heap. This will create a minheap.
    for(int i=0;i<n;i++)
        pq.push(cost[i]);
    
    for(int i=0;i<n;i++){
        if(pq.top()<=sum){
            // one by one we will be taking the element out and then we will be decrementing the sum as well.
            sum-=pq.top();
            pq.pop();
            res++;
        }else{
            break;
        }
    }
    cout<<res;
}
/*
In both the cases we will be getting the same result.
*/

int main() 
{ 
    int n=5;
    int cost[n]={1,12,5,111,200};
    int sum=10;

    naiveMax(cost,n,sum);
    cout<<endl;
    efficientMax(cost,n,sum);
    return 0;
} 