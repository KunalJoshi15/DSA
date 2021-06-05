#include<bits/stdc++.h>

using namespace std;

void rearrange(int *arr,int n){
    int max_idx = n-1,min_idx=0;
    int max_element = arr[n-1]+1;
    // Here we will be using the max element to create a formula which will help us in fetching the values required.
    for(int i=0;i<n;i++){
        if(i%2==0){
            arr[i] += (arr[max_idx]%max_element)*max_element;
            max_idx--;
        }
        else{
            arr[i]+=(arr[min_idx]%max_element)*max_element;
            min_idx++;
        }
    }
    // This will provide us the max element and the min element whichever is required.
    for(int i=0;i<n;i++){
        arr[i] = arr[i]/max_element;
    }
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int n = sizeof(arr)/sizeof(int);

    cout<<"Orignal Array\n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    rearrange(arr,n);
    cout<<"\nModified Array\n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}