#include<bits/stdc++.h>

using namespace std;

int intersect(int a[],int b[],int m,int n){
    unordered_set<int> s(a,a+m);
    // Firstly all the elements of the array a are pushed to the unordered set. We will now simply traverse through the second array and remove the found element from the unordered set.
    int res=0;
    for(int i=0;i<n;i++){
        if(s.find(b[i])!=s.end()){
            res++;
            // For this paricular element we are removing that particular element.
            s.erase(b[i]);
        }
    }
    return res;
    // This will give us the count of the elements.
}

int main(){
    int a[]={10,20,10,30};
    int b[]={20,10,10,40};

}