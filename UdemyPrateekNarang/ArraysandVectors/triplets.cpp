#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> triplets(vector<int> arr,int sum){
    //logic
    int n = arr.size();
    sort(arr.begin(),arr.end());
    vector<vector<int>> result;
    // Pick every a[i], pair sum for remaining part.
    for(int i=0;i<=n-3;i++){
        int j=i+1;
        int k=n-1;

        while(j<k){
            int current_sum = arr[i];
            current_sum +=arr[j];
            current_sum+=arr[k];

            if(current_sum==sum){
                result.push_back({arr[i],arr[j],arr[k]});
                j++;
                k--;
            }
            else if(current_sum>sum){
                k--;
                //If the sum becomes larger then we will exclude the last element
            }
            else{
                j++;
                //If the sum is smaller then increment the start pointer;
            }
        }
    }
}

int main(){
    //there are two approaches which can be used the brute force one is O(n^3) solution while the other solution is O(n^2)
    // We can simply used the concept which we were introduced in pairs problem. Considering each and every element pertaining to that case.
    vector<int> arr{1,2,3,4,5,6,7,8,9,10};
    int S = 18;

    auto result = triplets(arr,S);

    return 0;
    // In case of the triplet problem we will be using the two pointer technique to find all the pairs which are possible.
    // THen iterate through the array. Here the sorting will not act as the bottleneck.
}