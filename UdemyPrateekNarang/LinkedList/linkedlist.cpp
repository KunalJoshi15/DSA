#include<bits/stdc++.h>

using namespace std;
/*
Unlike arrays the linked list are the data structures which is not continuous.
In case of the linked list we are provided with the starting point of the linked list.
In linkedlist there is large usage.
Large feed items.

The basic operations which can be performed on a linked list are.
Deletion insertion printing searching.

Many problems there are for the segmentation fault*/
class node{
    public:
        int data;
        node* next;

        node(int data){
            this->data = data;
            next=NULL;
        }
};
//Here we have passed the head pointer as the reference because we need to change the pointing of the head pointer.
void insertAtHead(node * &head,int data){
    if(head==NULL){
        head = new node(data);
        return;
    }
    // This will create a new node and push data
    node *temp = new node(data);
    temp->next = head;
    head = temp;
}

void insertInMiddle(node *&head,int data,int pos)
{
    if(pos==0){
        insertAtHead(head,data);
        return;
    }
    node *temp = head;
    int i=1;
    while(i!=(pos-1) and temp!=NULL){
        temp = temp->next;
    }
    node *n = new node(data);
    n->next = temp->next;
    temp->next = n;
}
void printList(node *head){
    node *temp = head;
    //Here the orignal value of the head is not altered
    while(temp!=NULL){
        cout<<temp->data<<"-->";
        temp=temp->next;
    }
}
// This particular function is used for reversing a particular linked list using the current data information that we have it basically reverses linked list in a group of k.
node *kReverse(node *head,int k)
{
    if(head==NULL) return NULL;
    // reverse the k nodes using the iterative approach then follow recursion.
    node* prev=NULL;
    node* current=head;
    node *temp;
    int cnt=1;

    while(current!=NULL and cnt<=k){
        temp=current->next;
        current->next = prev;

        prev=current;
        current=temp;
        //reverses the k nodes.
    }
    if(temp!=NULL){
        head->next = kReverse(temp,k);
    }
    return prev;
}
// At the last we will be returning the previous node value as per our requirement.

int main()
{
    node* head = NULL;
    insertAtHead(head,4);
    insertAtHead(head,5);
    insertAtHead(head,2);
    insertAtHead(head,4);
    insertAtHead(head,6);
    insertAtHead(head,9);
    insertAtHead(head,2);
    head = kReverse(head,3);
    printList(head);
    // This will created the linked
    return 0;
}
