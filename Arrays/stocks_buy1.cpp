#include<bits/stdc++.h>

using namespace std;
/*
Here the procedure that weill be used is 
The problem will be broken into the smaller number of equations.
maxProfit(price,start,i-1)+maxProfit(price,j+1,end)
*/
int maxProfit(int price[],int start,int end){
    if(end<=start) return 0;
    int profit=0;
    for(int i=start;i<end;i++){
        for(int j=i+1;j<end;j++){
            if(price[j]>price[i]){
                int curr_profit = price[j]-price[i]+maxProfit(price,start,i-1)+maxProfit(price,j+1,end);
                profit = max(profit,curr_profit);
            }
        }
    }
    return profit;
}

int main(){
    int arr[] = {1,5,3,8,12};
    // We need to find the max profilt we will be buying stock if it is min and sell when max price.
}