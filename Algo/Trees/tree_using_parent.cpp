#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

void sort_and_print(vector <int> &v)
{
    sort( v.begin() , v.end() );
    for( int i=0 ; i<v.size() ; i++ )
        cout<< v[i] << " ";
    v.clear();
}

void printLevelOrder(struct Node* root)
{
    vector <int> v;
    queue <Node*> q;
    
    q.push(root);
    
    Node* next_row = NULL;
    
    while(!q.empty())
    {
        Node* n = q.front();
        q.pop();
        
        if(n==next_row)
        {
            sort_and_print(v);
            next_row = NULL;
        }
        
        v.push_back(n->data);
        
        if(n->left)
        {
            q.push(n->left);
            if(next_row == NULL) next_row = n->left;
        }
        
        if(n->right)
        {
            q.push(n->right);
            if(next_row == NULL) next_row = n->right;
        }
    }
    sort_and_print(v);
}

Node *createTree(int parent[], int n);

/* Driver program to test above function*/


 // } Driver Code Ends
/* node structure  used in the program

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

class Solution{
  public:
    //Function to construct binary tree from parent array.
    Node *createTree(int parent[], int N)
    {
        // Your code here
        unordered_map<int,Node*> m;
        Node *temp;
        
        for(int i=0;i<N;i++){
            if(parent[i]==-1 and m.find(i)==m.end()){
                temp = new Node(i);
                m[i] = temp;
                continue;
            }
            
            if(m.find(parent[i])==m.end()){
                m[parent[i]] = new Node(parent[i]);
            }
            if(m.find(i)==m.end()){
                m[i] = new Node(i);
            }
            Node *parents = m[parent[i]];
            Node *childs = m[i];
            https://practice.geeksforgeeks.org/problems/construct-binary-tree-from-parent-array/0/?track=DSASP-Tree&batchId=154#
            if(parents->left==NULL){
                parents->left = childs;
            }
            else{
                parents->right = childs;
            }
        }
         for(int i=0;i<N;i++)
         {
             if(parent[i]==-1)
             {
                 return m[i];
             }
         }
         return NULL;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>> t;
    while(t--)
    {
        int n;
        cin>> n;
        int a[n];
        for( int i=0 ; i<n ; i++ )
            cin>> a[i];
            
        Solution ob;
        
        Node *res = ob.createTree(a,n);
        
        printLevelOrder(res);
        cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends