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
/*
this particular question is a very popular interview question.
The cache is the fastest memory in the system and the space in case of the cache is limited.
When there is the miss then we insert the element into the cache as per our requirement.

If there is a miss then the most recently accessed item comes to the front.

WHen there is the miss but the cache is full then we remove the item from the last and insert at the first.
ARRAY IS NOT A GOOD DATA STRUCTURE TO IMPLEMENT THIS.
*/


int main()
{

}