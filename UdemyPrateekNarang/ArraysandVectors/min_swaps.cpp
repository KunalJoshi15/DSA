#include<bits/stdc++.h>

using namespace std;
// This is used to find the min number of swaps to sort a particular array.
// Algorithm that we will find out will be having the minimum number of swaps to sort a particular array.
int countMinSwaps(vector<int> arr){
    // Know the actual position of thw elements in the arary which are present.
    // Store the current indices as well.
    int n = arr.size();
    pair<int,int> ap[n];
    for(int i=0;i<n;i++){
        ap[i].first = arr[i];
        ap[i].second = i;
    }
    //Sorting
    sort(ap,ap+n);

    //Build the main logic
    vector<bool> visited(n,false);
    int ans;
    for(int i=0;i<n;i++){
        // If the element is already visited or we are visiting it for the first time.
            int old_position = ap[i].second;
            if(visited[i]==true or old_position==i){
                continue;
            }
        // Visiting the element index for the first time
        // The node variable represents the current index that is being visited.
        int node = i;
        int cycle=0;
        while(!visited[node]){
            // If the particular node is not visited then we will simply visit that node.
            // The next node that willl be visited is. ap[node].second
            // Sorting is performed on the basis of the indices.
            // All the elements which are a part of the loop are considered together.
            visited[node] = true;
            int next_node = ap[node].second;
            node = next_node;
            cycle +=1;
        }
        ans += (cycle-1);
    }
    return ans;
}
int main(){
    // In order to find the minimum number of swaps we need to find the exact location of the numbers that are present.
    // Correct location of each element therefore sorting is always needed.
    // we need to find all the cycles which are possible in case of the arrays.
    // If there are N elements in the array then in order to sort them we will require N-1 swaps.
    
     vector<int> arr{5,4,3,2,1};
     cout<<countMinSwaps(arr)<<endl;
     return 0;
}