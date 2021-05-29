#include<bits/stdc++.h>

using namespace std;

int subarray_sum(vector<int> m){
    int max1=0,max2=0;
    for(int i=0;i<m.size();i++){
        max1=m[i];
        if(max1>max2){
            max2=max1;
        }
        if(max1<0) max1=0;
    }
    return max2;
}

int main(){
    vector<int> m={2,3,1,2,3,5,-2,-2,23};
    cout<<subarray_sum(m);
}