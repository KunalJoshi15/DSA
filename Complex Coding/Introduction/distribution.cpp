#include<bits/stdc++.h>

using namespace std;

int iteration(int n)
{
    int i=1;
    int count=0;
    while(((n*i)%11)!=1){
        count++;
        i=i<<1;
    }
    return count;
}

int main(){
    int n;
    cin>>n;
    cout<<iteration(n);
}