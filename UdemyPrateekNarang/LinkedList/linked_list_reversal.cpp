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
node *recReverse(node *head){
    if(head==NULL or head->next==NULL){
        return head;
    }

    node *sHead = recReverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return sHead;
}

void itRev(node * &head){
    node *prev=NULL;
    node *curr=head;
    node *currNext = curr->next;

    while(curr!=NULL){
        currNext=curr->next;
        curr->next = prev;
        prev=curr;
        curr=currNext;
    }
    head=prev;
}

//In case of the iterative approach we will be maintaining three pointers in order to store the information regarding the nodes.

int main(){
    // The above logic will reverse the current linkedlist inreversal order. It will return the head of the newly created linkedlist.
}