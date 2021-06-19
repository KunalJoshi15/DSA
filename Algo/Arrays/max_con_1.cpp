#include<bits/stdc++.h>

using namespace std;
//Naive approach of this particular problem can be represented as follows.
/*
maxCons this approach which is being used is a naive approach. For each time the loop runs and there if we find a zero then 
we breaks and res is changed if there are consecutive ones found in the array.
*/
int maxCons(int *arr,int n){
    int res=0;
    for(int i=0;i<n;i++){
        int curr=0;
        for(int j=i;j<n;j++)
        {
            if(arr[j]==1) curr++;
            else break;
        }
        res = max(res,curr);
    }
    return res;
}

int count_cons(int *arr,int n){
    int count=0;
    int max_count=INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]==1){
            count++;
        }
        else{
            count=0;
        }

        if(count>max_count){
            max_count=count;
        }
    }
    return max_count;
}

int main(){
    int arr[] = {1,0,1,1,1,1,0,1,1};
    int n = sizeof(arr)/sizeof(int);
    cout<<count_cons(arr,n);
}