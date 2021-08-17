// { Driver Code Starts
#include <iostream>

using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};



Node *swapkthnode(Node* head, int num, int K);

void addressstore(Node **arr, Node* head)
{
    Node* temp = head;
    int i = 0;
    while(temp){
        arr[i] = temp;
        i++;
        temp = temp->next;
    }
}

bool check(Node ** before, Node **after, int num, int K)
{
    if(K > num)
        return 1;
    return (before[K-1] == after[num - K]) && (before[num-K] == after[K-1]);
}

int main()
{
    int T;
    cin>>T;
    while(T--){
        int num, K , firstdata;
        cin>>num>>K;
        int temp;
        cin>>firstdata;
        Node* head = new Node(firstdata);
        Node* tail = head;
        for(int i = 0; i<num - 1; i++){
            cin>>temp;
            tail->next = new Node(temp);
            tail = tail->next;
        }
        
        Node *before[num];
        addressstore(before, head);
        
        head = swapkthnode(head, num, K);
        
        Node *after[num];
        addressstore(after, head);
        
        if(check(before, after, num, K))
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
}
// } Driver Code Ends


//User function Template for C++

/* Linked List Node structure
   struct Node  {
     int data;
     Node *next;
     Node(int x) {
        data = x;
        next = NULL;
  }
  }
*/
int countNodes(Node *head){
    if(head==NULL) return 0;
    return 1+countNodes(head->next);
}
//Function to swap Kth node from beginning and end in a linked list.
Node *swapkthnode(Node* head, int num, int K)
{
    // Your Code here
    int n = countNodes(head);
    if(n<K) return head;
    
    if(2*K-1==n) return head;
    int p = K;
    Node *startK = head;
    Node *startKprev = NULL;
    
    for(int i=1;i<K;i++){
        startKprev = startK;
        startK = startK->next;
    }
    Node *endK = head;
    Node *endKprev = NULL;
    
    for(int i=1;i<n-K+1;i++){
        endKprev = endK;
        endK = endK->next;
    }
    
    if(startKprev){
        startKprev->next = endK;
    }
    
    if(endKprev){
        endKprev->next = startK;
    }
    
    Node *temp = startK->next;
    startK->next = endK->next;
    endK->next = temp;
    
    if(K==1){
        head = endK;
    }
    
    if(K==n){
        head = startK;
    }
    return head;
}

