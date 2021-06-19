#include<bits/stdc++.h>

using namespace std;

int find_square_root(int x){
    int low = 1;
    int high = X;
    int ans=-1;
    while(low<=high){
        int mid = (low+high)/2;

        if(mid*mid>x){
            high=mid-1;
        }
        else if(mid*mid==x){
            return mid;
        }else{
            low=mid+1;
            ans=mid;
        }
    }
    return mid;
    // THis particular process works in a very elegant way.
    // This technque is simply finding the last occurence of the integer that satisfy the condition of the evaluation.
}

int main(){
    int x;
    cin>>x;
    int square_root = find_square_root(x);
}