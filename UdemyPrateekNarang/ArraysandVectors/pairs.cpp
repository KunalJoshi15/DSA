#include<bits/stdc++.h>

using namespace std;

vector<int> best(int arr[],int n,int Sum)
{
    std::unordered_set<int> s;
    // We cannot add all the elements to the array itself and then perform the other actions as this can cause many problems.
    vector<int> result;

    for(int i=0;i<n;i++){
        // WE will be checking whether the complement of the particular value is present or not.
        int x = Sum - arr[i];
        if(s.find(x)!=s.end()){
            result.push_back(x);
            result.push_back(arr[i]);
            return result;
        }
        s.insert(arr[i]);
    }
    // We check whether the complement of the element is already present in the unordered_set if it is then we can say that we have the pair to get a particular sum.
}
int brute_force(int arr[],int n,int sum){
    for(int i=0;i<n;i++){
        for(int j=i+1;i<n-1;i++){
            if(arr[i]+arr[j]==sum){
                return true;
            }
        }
    }
    return false;
}
int main(){
    vector<int> arr={10,5,2,3,-6,9,11};
    int s=4;
    //sorting technique can be used for solving this particular problem.

    //The brute force approach to solve this particular question is considering all the pairs.
    //That can be formed in a particular array and find the sum of all the pairs if sum exists then say that the solution is possible.
}