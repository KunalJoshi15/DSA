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
    //Base case
    if(a==NULL) return b;
    if(b==NULL) return a;

    node *c;
    if(a->data<b->data){
        c=a;
        c->next = merge(a->next,b);
    }
    else{
        c=b;
        c->next = merge(a,b->next);
    }
    // Every time we are returining the head.
    return c;
}

int main()
{

}