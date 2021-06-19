#include<bits/stdc++.h>

using namespace std;

int majorityElement(int arr[],int n){
    int count=1;
    int max_count=1;
    int index=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]==arr[j]){
                count++;
            }
        }
        if(count>max_count){
            max_count=count;
            count=1;
            index=i;
        }
    }
    if(max_count>n/2) return index;
    else return -1;
}
// arr[res] is checked with arr[i]
// count is incremented if the element is not matched then 
/*
The working of the algorithm is in this particular way.
There is one element that contributes for the vote while the next element cancels the vote.
This divides the elements into two sets. The majority element needs to be on the right side.
*/
int findMajority(int arr[],int n){
    int res=0,count=1;
    for(int i=1;i<n;i++){
        if(arr[res]==arr[i]) count++;
        else count--;
        if(count==0) {res=i;count=1;}
    }

    count=0;
    for(int i=0;i<n;i++){
        if(arr[res]==arr[i]) count++;
        if(count<=n/2) res=-1;
        return res;
    }
}

int main(){
    int arr[] = {8,7,6,8,6,6,6,6};

}