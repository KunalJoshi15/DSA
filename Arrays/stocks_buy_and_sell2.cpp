#include<bits/stdc++.h>

using namespace std;
//In this particular approach we will be buying the stock when the price is lower and will be buying when the price is high.
// This can be simply used in a better way as we want. There is no harm is incrementing the value each and every time.
int maxProfit(int *arr,int n){
    int profit=0;
    for(int i=1;i<n;i++){
        if(arr[i]>arr[i-1]){
            profit += arr[i]-arr[i-1];
        }
    }
    return profit;
}
int main(){

}