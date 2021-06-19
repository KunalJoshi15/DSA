#include<bits/stdc++.h>

using namespace std;

void merge(vector<int> &arr,int s,int e){
    // This particular merge procedure is used to combine both the arrays as per our requirement.
    int i = s;
    int m = (s+e)/2;
    int j=m+1;

    vector<int> temp;
    // This particular loop will run until one of the array has been exhausted.
    while(i<=m and j<=e){
        if(arr[i]<arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            temp.push_back(arr[j]);
            j++;
        }
    }
    // There two cases now either the left part has the elements or the right side has the elemeents.

    while(i<=m){
        temp.push_back(arr[i++]);
    }

    while(j<=e){
        temp.push_back(arr[j++]);
    }
    // Only one of them execute;
    int k=0;
    for(int idx=s;idx<=e;idx++){
        arr[idx] = temp[k];
        k++;
    }
    return;
}

void mergesort(vector<int> &arr,int s,int e){
    // Initially we will be writing the base case for the problem.
    if(s>=e){
        return;
    }
    int mid = (s+e)/2;
    mergesort(arr,s,mid);
    mergesort(arr,mid+1,e);
    return merge(arr,s,e);
}

int main(){
    vector<int> arr{10,5,2,0,7,6,4};

    int s=0;
    int e = arr.size()-1;

    mergesort(arr,s,e);

    for(int x:arr){
        cout<<x<<",";
    }
}