#include<bits/stdc++.h>

using namespace std;

int countSubsets(int arr[],int n,int sum){
    if(n==0) return (sum==0)?1:0;
    return countSubsets(arr,n-1,sum)+countSubsets(arr,n-1,sum-arr[n-1]);
}

// There will be two smallAnswers which are considered and it has the values which is needed. One time we will include the item while the second time we will exclude it.

int main(){

}