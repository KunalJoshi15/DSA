#include<bits/stdc++.h>

using namespace std;

void printNbyK(int arr[],int n,int k){
    unordered_map<int,int> m;
    for(int i=0;i<n;i++){
        m[arr[i]]++;
    }

    for(auto e:m){
        if(e.second>n/k){
            cout<<e.first<<" ";
        }
    }
}

int main()
{
    // The approach that can be used to find the n/k occurences of the data which is present is.
    // First sort the array and find the count of the variable the time complexity of this particular solution is O(n log n)
    // There is a better solution to this particular problem that leverages the idea of the hashmap. 
    // We will be storing the frequencies in a hashmap.
}