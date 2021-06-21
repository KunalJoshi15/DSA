#include<bits/stdc++.h>

using namespace std;

int highest_mountain(vector<int> arr){
    int n = arr.size();
    int largest = 0;

    for(int i=1;i<=n-2;){
        if(arr[i-1]<arr[i] && arr[i]<arr[i+1]){
            //do some work 
            int cnt=1;
            int j=i;
            //count backwards
             while(j>=1 and arr[j]>arr[j-1]){// check all the ones which are smaller. Count the values which are in that case.
             //The last element cannot be the largest element.
                 j--;
                 cnt++;
             }           
            //count forwards.
            while(i<=n-2 and arr[i]>arr[i+1]){
                // Increment the larger values and count the values which are present in the mountain.
                i++;
                cnt++;
            }
            largest = max(largest,cnt);
        }
        else{
            i++;
        }
    }
}

int main(){
    // It might seem that the problem of finding the numbers which are present in the highest peak are,
    // This at the first glance might seem a trick question while it is very easy.
    // In case of the mountain problem we initially find the peak and then we count the number of elements 
    //on the left side of the peak and then to the right side of the peak.
    vector<int> arr{5,6,1,2,3,4,5,4,3,2,0,1,2,3,-2,4};
    cout<<highest_mountain(arr);
}