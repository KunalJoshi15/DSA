#include<bits/stdc++.h>

using namespace std;

class node{
    public:
        int data;
        node *next;
    node(int data){
        this->data=data;
        next=NULL;
    }
};

node *merge(node *a,node *b){
    if(a==NULL) return b;
    if(b==NULL) return a;

    node *res;
    if(a->data<n->data){
        res = a;
        res->next = merge(a->next,b);
    }
    else{
        res = b
        res->next = merge(a,b->next);
    }
}

node *midPoint(node *head){
    node *slow =head;
    node *fast = head->next;

    while(fast!=NULL and fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

node *mergeSort(node *head){
    //base case
    if(head==NULL or head->next==NULL){
        return head;
    }

    node *mid = midPoint(head);
    node *a = head;
    node *b = mid->next;
    // Recursive Sort
    a = mergeSort(a);
    b = mergeSort(b);

    return merge(a,b);
}

int main()
{
    
}
/*
Finding the midpoint in case of the linked list will take more time but still the overall time complexity of the algorithm is not altered.
*/