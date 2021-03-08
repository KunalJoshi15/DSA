#include<bits/stdc++.h>

using namespace std;
int count_zeros(int a){
    //This is the base case of the problem this is required by us to solve the problem to a greater extent.
    if(a<10) return 0;
    if(a%10==0){
        int smallAns = count_zeros(a/10);
        return 1+smallAns;
    }
    return count_zeros(a/10);
}
int main(){
    int a;
    cin>>a;
    int zeros = count_zeros(a);
    cout<<zeros;
}