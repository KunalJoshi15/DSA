#include<bits/stdc++.h>

using namespace std;

class ListNode{
    public:
        int val;
        ListNode *next;

        ListNode(){
            this->val=0;
            this->next=NULL;
        }

        ListNode(int val){
            this->val=val;
            this->next=NULL;
        }
};

int main(){
    cout<<"Enter the elements to be inserted in the Linked List"<<endl;
    int n;
    cin>>n;
    cout<<"Enter the elements"<<endl;
    int temp;
    cin>>temp;
    ListNode *a = new ListNode(temp);
    for(int i=0;i<n;i++){
    }
}