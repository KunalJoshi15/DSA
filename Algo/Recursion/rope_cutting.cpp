#include<bits/stdc++.h>

using namespace std;

int max(int a,int b,int c){
    if(a>=b&&b>=c){
        return a;
    }
    if(b>=a&&b>=c){
        return b;
    }
    if(c>=b&&c>=a){
        return c;
    }
}

int fun(int n,int a,int b,int c){
    if(n==0) return 0;
    if(n<0) return -1;
    // We will assume for the below case we will be getting the answer using this particular function.
    // If the res=-1 We are simply assuming that this will provide us the correct answer. If max for all the cases is -1 then the actual answer is -1;
    int res = max(fun(n-a,a,b,c),fun(n-b,a,b,c),fun(n-c,a,b,c));
    if(res==-1) return -1;
    return res+1;
    // The time complexity of the solution is very large it is O(3^n) Dynamic Programming is ued.
}

int main(){
    int n,a,b,c;
    cin>>n>>a>>b>>c;
    int res = fun(n,a,b,c);
}