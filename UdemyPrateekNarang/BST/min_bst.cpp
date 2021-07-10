#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
        int data;
        Node *left;
        Node *right;

        Node(int data){
            this->data = data;
            left = NULL;
            right = NULL;
        }
};


Node *sortedArray(vector<int> arr,int start,int end){
    if(start>end)
        return NULL;

    int mid = (start+end)/2;
    // Find the mid element in the sorted array and it will be used as the root node. This will help us in reducing the time complexity of the code to O(n);
    Node *root = new Node(arr[mid]);
    root->left = sortedArray(arr,start,mid-1);
    root->right = sortedArray(arr,mid+1,end);

    return root;
}

int main()
{
    vector<int> arr = {2,1,2,3,1,2,3,5,6,4};
    Node *root = sortedArray(arr,0,arr.size());
}