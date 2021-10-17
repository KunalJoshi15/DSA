#include<bits/stdc++.h>

using namespace std;

/*
Find the median of the elements is a very important interview problems in this we are provided with a stream of data and we need to find the median at each point in time.
*/

// the naive approach to solve this particular problem will be each time when the new elements come we will be maintaining the sorted order of the array.
void naiveMedian()
{
	double arr[]={25,7,10,15,20};int n=5;
    double temp[n];
    int size=0;
    for(int i=0;i<n;i++){
        temp[i]=arr[i];
        size++;
        int j=i;
        while(j>0&&temp[j]<temp[j-1]){
        swap(temp[j],temp[j-1]);
        j--;
    }
    if(size%2!=0)
        cout<<temp[size/2]<<" ";
    else
        cout<<(temp[size/2]+temp[(size-1)/2])/2<<" ";
        
    }
}
// the other appraoch that we can use is creating a binary serach tree which has the number of elements which are left to it.
// in case of the best solution we will be using two heaps one will be the min heap while the other one will be the maxheap.
/*
Here in this case the left side heap is the max heap and the new element always goes to the smaller heap if the size of the heaps are equal.
*/
void printMedians(int arr[],int n){
    priority_queue<int> s;
    priority_queue<int, vector<int>,greater<int>> g;
    s.push(arr[0]);
    cout<<arr[0]<<" ";
    for(int i=1;i<n;i++){
        int x=arr[i];
        if(s.size()>g.size())
        {
            if(s.top()>x){
                g.push(s.top());
                s.pop();
                s.push(x);
            }else g.push(x);
            cout<<(s.top()+g.top())/2.0<<" ";
        }else{
            if(x<=s.top()){
                s.push(x);
            }else{
                g.push(x);
                s.push(g.top());
                g.pop();
            }
            cout<<s.top()<<" ";
        }
    }
}

int main()
{
	int keys[] = { 25, 7, 10, 15, 20};
    
    printMedians(keys,5);
	
	return 0;
}