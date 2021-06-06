#include<bits/stdc++.h>
using namespace std;

/*
In case of the housing problem we need to make a plot as per our need. Along one side of a road there is a sequence of vacant plots of land. Each plot has a different area. So, the areas form a sequence.
We are to build a plot at a place of k acres

The brute force time complexity of this particular algorithm will be O(n^3) we will be finding all the subarrays present and then will find the specific i and j such that the sum is equal to k
The better approach to solve this particular problem will be make a prefix sum array.

we will be creating a prefix sum array and for all the i's we will try finding a j such that ps[j]-ps[i]=k
Using the concept of the prefix sum we will be performing the binary search on the other reamining part. Therefore it will be reducing the time complexity to O(n log n).

The final solution that will come handy will be the sliding window solution it will give us the time complexity of O(n)
In case of the sliding window solution we will be maintaining two pointers one is pointing to start while the other one is pointing to the other part.
if the sum that we have is the greater than the required sum then we will removing the element from the start of the array.
if small then we will be finding the sum.
*/
vector<pair<int,int>> housingProblem(int *arr,int n,int k)
{
    int i=0,j=0;
    int sum=0;
    vector<pair<int,int>> solution;
    while(j<n){
        sum += arr[j];
        j++;

        while(sum>k and i<j){
            sum = sum-arr[i];
            i++;
        }
        if(sum==k){
            solution.push_back({i,j-1});
        }
    }
    return solution;
}

bool prefix_bool(int *arr,int n,int k){
    if(k>0 and n==0) return false;
    if(k==0 and n==0) return true;
    int prefix[n];
    memset(prefix,0,sizeof prefix);
    prefix[0] = arr[0];

    for(int i=1;i<n;i++){
        prefix[i] = prefix[i]+prefix[i-1];
    }

    for(int i=0;i<n;i++){
        int curr = arr[i];
        // run the binary search in the remaining part of the array and according to it the other actions are taken as per our need.
        int it = binary_search(arr,arr+n,k-arr[i]);
    }
    return true;
}

int main(){
    int arr[] = {2,3,4,1,2,3,4,5,6,8,2};
    int k = 10;
    vector<pair<int,int>> solution = housingProblem(arr,sizeof(arr)/sizeof(int),k);

    for(pair<int,int> sol:solution){
        cout<<sol.first<<" "<<sol.second<<endl;
    }
}