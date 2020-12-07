#include<bits/stdc++.h>
using namespace std;

void mySort(int arr[],int n)
{
    priority_queue<int> pq(arr,arr+n);
    for(int i=n-1;i>=0;i--)
    {
        arr[i] = pq.top();
        pq.pop();
    }
}

int main()
{
    int arr[] = {12,4,5,2,3,4};
    mySort(arr,6);
    return 0;
}