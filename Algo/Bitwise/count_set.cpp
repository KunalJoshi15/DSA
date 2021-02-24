#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int count;
    while(n){
        if(n&1){
            count++;
        }
        n=n>>1;
    }
    cout<<count;
}