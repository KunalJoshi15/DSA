#include<bits/stdc++.h>

using namespace std;
//The naive approach for finding the max subarray is finding all the. The complexity of this particular solution is very
//large.

int max_sub_sum1(int *arr,int n){
    int res = arr[0];

    for(int i=0;i<n;i++){
        int curr=0;
        for(int j=i;j<n;j++){
            curr = curr+arr[i];
            res = max(res,curr);
        }
    }
    return res;
}

int max_sub_sum2(int *arr,int n){
    int max_sum_so_far=0;
    int curr_max_sum=0;

    for(int i=0;i<n;i++){
        max_sum_so_far = max_sum_so_far+arr[i];
        if(curr_max_sum<max_sum_so_far){
            curr_max_sum=max_sum_so_far;
        }
        if(max_sum_so_far<0) max_sum_so_far=0;
    }
    return curr_max_sum;
}
int main(){

}