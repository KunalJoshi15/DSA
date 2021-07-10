#include<bits/stdc++.h>

using namespace std;

int union_elements(int a[],int b[],int m,int n){
    unordered_set<int> h(a,a+m);
    // This particular will push all the elements from array a to the unordered set.
    for(int i=0;i<n;i++){
        h.insert(b[i]);
    }
    return h.size();
}

int main()
{
    int a[] = {10,30,10,40};
    int b[] = {40,5,10,15};
    int m = sizeof(a)/sizeof(int);
    int n = sizeof(b)/sizeof(int);

    int un = union_elements(a,b,m,n);
    cout<<un;
}