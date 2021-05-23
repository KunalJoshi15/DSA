#include<bits/stdc++.h>

using namespace std;
/*
The brute force method in this case. we will be finding all the subarrays 
and will be finding the max even odd sequence in it.
*/
int maxEvenOdd(int *arr,int n){
    int res=1;

    for(int i=0;i<n;i++){
        int curr=1;
        for(int j=i+1;j<n;j++){
            if((arr[j]%2==0 &&arr[j-1]%2==1)||(arr[j]%2==1 && arr[j-1]%2==0)){
                curr++;
            }else{
                break;
            }
        }
        res=max(res,curr);
    }
    return res;
    // For each iteration of the element it is reset.
}

int maxOddEven2(int *arr,int n){
    int curr=1;
    int maxCurr=curr;
    // Here the sequence of the elements is found.
    //
    for(int i=1;i<n;i++){
        //current element is even while the previous will be odd or there will be the other case.
        if((arr[i]%2==0 && arr[i-1]%2==1)||(arr[i]%2==1 && arr[i]%2==0)){
            curr++;
        }else{
            curr=1;
        }
        if(maxCurr<curr){
            maxCurr=curr;
        }
    }
    return maxCurr;
}

int main(){

}