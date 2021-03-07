#include<bits/stdc++.h>

using namespace std;

int sum(int *a,int size){
    int ans=0;
    for(int i=0;i<size;i++){
        ans+=a[i];
    }
    return ans;
}

int main(){
    int a[10];
    cout<<sizeof(a)<<endl;
    cout<<sum(a,10)<<endl;
}
// We can even pass a particular part of an array if we want to.
// When the arrays are passed as inside a function they are treated as the pointers;
