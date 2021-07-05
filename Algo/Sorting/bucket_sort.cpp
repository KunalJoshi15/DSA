#include<bits/stdc++.h>

using namespace std;

void bucketSort(int arr[],int n,int k){
    int max_val = arr[0];

    for(int i=1;i<n;i++){
        max_val = max(max_val,arr[i]);
    }
    max_val++;

    vector<int> bkt[k];

    for(int i=0;i<n;i++){
        int bi = (k*arr[i])/max_val;
        bkt[bi].push_back(arr[i]);
    }

    for(int i=0;i<k;i++)
        sort(bkt[i].begin(),bkt[i].end());
    int index=0;
    for(int i=0;i<k;i++){
        for(int j=0;j<bkt[i].size();j++){
            arr[index++] = bkt[i][j];
        }
    }
}


int main()
{
    // The elements in case of the bucket sort are in a particular range.
    // Each range will be having a particular number of elements/
    // The range of the numbers will be large.

    // bucket sort is used when the range is large.
    // Hashing and chaining it is similar to it.
    // In case of the bucket sort the elements are in a particular bucket.
    // There will be multiple buckets created in case of the bucket sort. They will be going to a particular bucket.
    // In all the buckets that are currently being created are in sorted order in particular.
    int arr[] = {20,80,10,85,75,99,18};
    // Ranges of the individual buckets are defined then we will be sorting the individual buckets.

    // In the bucket sort algorithm the number of buckets are also defined.
    return 0;
}