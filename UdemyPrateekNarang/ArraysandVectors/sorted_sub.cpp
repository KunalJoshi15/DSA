#include<bits/stdc++.h>

using namespace std;

bool ourOfOrder(vector<int> arr,int i){
    int x = arr[i];
    if(i==0) return x>arr[i];
    if(i==arr.size()-1) return x<arr[i-1];
    return x>arr[i+i] or x<arr[i-1];
    // These three conditions are used for specifying whether a particular number is out of order or not.

}

pair<int,int> subarraySort2(vector<int> arr){
    // We will have to find the elements which are out of order.
    // If the current element is larger than the previous and next. 
    // If the current element is smaller than the current element then also it is not in order.
    // We will be having the two variables to maintain the largest and the smallest element which is out of order.
    int smallest = INT_MAX;
    int largest = INT_MIN;

    for(int i=0;i<arr.size();i++){
        int x = arr[i];
        if(ourOfOrder(arr,i)){
            smallest = min(smallest,x);
            largest = max(largest,x);
        }
    }

    if(smallest==INT_MAX){
        return {-1,-1};
    }
    int left=0;
    while(smallest>=arr[left]){
        left++;
    }
    // This will be used for finding the start and the end of the subarray which needs to be sorted in order to obtain a sorted array.
    int right = arr.size()-1;
    while(largest<=arr[right]){
        right--;
    }
    return {left,right};
}

vector<int> subarraySort(vector<int> a){
    vector<int> b(a);//Here the constructor is being passed.
    sort(a.begin(),a.end());
// This is the first solution which comes to our mind it is we sort the array and then find the first index from left side and right side which has changed its position.
//It provides us the start and the end positions as per our need.
    int i=0;
    int n=a.size();
    while(i<n and a[i]==b[i]){
        i++;
    }
    int j=a.size()-1;
    while(j>=0 and a[j]==b[j]){
        j--;
    }
    if(i==a.size()){
        return {-1,-1};
    }
    return {i,j};
}

int main(){
    // In this particular problem we need to find the subarray which is sorted and we need to find the locations where it is sorted.
    vector<int> arr={2,4,6,7,2,1,32,5,7,3,2,2,5,4};
    vector<int> sol = subarraySort(arr);
    pair<int,int> sol2 = subarraySort2(arr);
    // The first and second is used for accessing the values in each of the cases.
    cout<<sol2.first<<" "<<sol2.second;
}