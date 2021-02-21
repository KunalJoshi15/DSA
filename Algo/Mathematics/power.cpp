#include<bits/stdc++.h>

using namespace std;
// number is always divided by 2;
int power(int x,int n){
    if(n==0)
    {
        return 1;
    }
    int temp = power(x,n/2);
    temp = temp*temp;
    if(n%2==0)
    {
        return temp;
    }
    else{
        return temp*x;
    }
    // This particular algorithm is an efficient way for 
}

int main(){
    int p = pow(5,3);
    cout<<p<<endl;
}