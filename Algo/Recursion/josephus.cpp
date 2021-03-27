#include<bits/stdc++.h>

using namespace std;
// We will assume that the smallAns will provide a result to josphus n-1 problem we will calculate what we need to be done for finding n.
int josephus(int n,int k){
    if(n==1){
        return 0;
    }
    int smallAns = josephus(n-1,k);
    return (smallAns+k)%n;
}

int main(){
    int n,k;
    cin>>n>>k;
    int ans = josephus(n,k);
}