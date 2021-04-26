#include<bits/stdc++.h>

using namespace std;
//The values in case of the arrays are all the non negative values.
//Naive approach

/*
This approach works this way we cannot store the water in the side bars.
For the bars in between we will be finding the value of lmax and rmax. min(lmax,rmax)-arr[i] will represent the water which can be stored at a particular level.
This particular naive solution is O(n^2)
the solution which is better requires O(n) space complexity and O(n) time complexity. we simply
*/
int trappingRain(int *arr,int n){
    int res=0;
    for(int i=1;i<n-1;i++){
        int lmax = arr[i];
        for(int j=0;j<i;j++){
            lmax = max(lmax,arr[j]);
        }
        int rmax = arr[i];
        for(int j=i+1;j<n;j++){
            rmax = max(rmax,arr[i]);
        }
        res = res+(min(lmax,rmax)-arr[i]);
    }
    return res;
}

int trappingWater1(int *arr,int n){
    int res = 0;
    int lmax[n],rmax[n];
    lmax[0]=arr[0];

    for(int i=1;i<n;i++){
        lmax[i] = max(arr[i],lmax[i-1]);
    }

    for(int i=n-2;i>=0;i--){
        rmax[i] = max(arr[i],rmax[i-1]);
    }

    for(int i=1;i<n-1;i++){
        res=res+(min(lmax[i],rmax[i])-arr[i]);
    }
    // This res variable represents the quantity of the water that is to be stored at a particular wall.
    return res;
}

int main(){

}