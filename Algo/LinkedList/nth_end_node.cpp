#include<bits/stdc++.h>

using namespace std;

class Node{
        public:
                int data;
                Node *next;
        Node(int data){
                this->data = data;
                next = NULL;
        }
};
// The steps that needs to be followed are the first node is moved by n positions a
//s per our requirement.
void printnthFromEnd(Node *head,int n){
        if(head==NULL) return;
        Node *first = head;
        for(int i=0;i<n;i++){
                if(first==NULL) return;
                first = first->next;
        }
        Node *second = head;
        while(first!=NULL){
                second  = second->next;
                first = first->next;
        }
        cout<<second->data;
}

int main()
{
        Node *head = new Node(1);
        head->next = new Node(2);
        head->next->next = new Node(3);
        head->next->next->next = new Node(4);
        head->next->next->next->next = new Node(5);
	printnthFromEnd(head,1);
}
