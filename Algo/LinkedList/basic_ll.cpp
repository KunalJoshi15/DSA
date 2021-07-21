#include<bits/stdc++.h>

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

int main()
{
	Node *head = new Node(2);
	cout<<head->data;
}