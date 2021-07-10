#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
        Node(int data){
            this->data = data;
            next=NULL;
        }
};

Node *insert(Node *head,int data){
    if(head==NULL) return new Node(data);
    
    head->next = insert(head->next,data);
    return head;
}

void printLL(Node *root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<"->";
    printLL(root->next);
}

Node *reverse(Node *root){
    if(root==NULL || root->next==NULL) return root;
    // 1-><-2<-3<-4-<4(tmp)
    Node *tmp = reverse(root->next);
    root->next->next=root;
    root->next = NULL;
    return tmp;
}

void altNodes(Node *root){
    if(root==NULL || root->next==NULL) return;
    
    cout<<root->data<<" ";
    altNodes(root->next->next);
    
}

Node *mergeLL(Node *head1,Node *head2){
    if(head1==NULL) return head2;
    if(head2==NULL) return head1;
    
    
    Node *start;
    if(head1->data>head2->data){
        start=head2;
        head2->next=mergeLL(head1,head2->next);
    }
    else{
        start=head1;
        head1->next=mergeLL(head1->next,head2);
    }
    return start;
}

int main() {
	// your code goes here
	Node *head = NULL;
	Node *head2 = NULL;
	for(int i=1;i<=10;i++){
	    head = insert(head,i);
	}
	for(int i=4;i<20;i=i+2){
	    head2 = insert(head2,i);
	}
	printLL(head);
// 	head = reverse(head);
	cout<<endl;
	printLL(head);
	cout<<endl;
	altNodes(head);
	Node *merged = mergeLL(head,head2);
	cout<<endl;
	printLL(merged);
	return 0;
}
