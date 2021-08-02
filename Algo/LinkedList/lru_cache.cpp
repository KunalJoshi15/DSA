#include<bits/stdc++.h>

using namespace std;

class Node{
public:
	int key;
	int data;
	Node *next;
	Node *next;

	Node(int key,int data){
		this->key = key;
		this->data = data;
		next = NULL;
		pre = NULL;
	}
};
/*
this particular question is a very popular interview question.
The cache is the fastest memory in the system and the space in case of the cache is limited.
When there is the miss then we insert the element into the cache as per our requirement.

If there is a miss then the most recently accessed item comes to the front.

WHen there is the miss but the cache is full then we remove the item from the last and insert at the first.
ARRAY IS NOT A GOOD DATA STRUCTURE TO IMPLEMENT THIS.

Here we will be using the concept of the doubly linked list with hashing.
When the cache is full then we will be removing an element.
Value and the address is store.

In case of the hit the intermediate node goes to the starting of the list while in case of the miss as well goes to the starting.
*/
class LRUCache{
public:
	unordered_map<int,Node*> map;
	int capacity,count;

	Node *head,Node *tail;

	LRUCache(int c){
		capacity = c;
		head = new Node(0,0);
		tail = new Node(0,0);
		head->next = tail;
		tail->pre = head;
		head->pre = NULL;
		tail->next = NULL;
		count = 0;
	}

	void deleteNode(Node *node){
		node->pre->next = node->next;
		node->next->pr = node->pre;
	}

	void addToHead(Node *node){
		node->next = head->next;
		node->next->pre = node;
		node->pre = head;
		head->next = node;
	}

	int get(int key){
		if(map[key]!=NULL){
			Nde *node = map[key];
			int result = node->value;

			deleteNode(node);
			addToHead(node);
			cout<<"Got the value "<<result<<" for the key: "<<key<<endl;
			return result;
		}
		cout<<"Did not get any value"<<" for the key: "<<key<<endl;
		return -1;
	}
	void set(int key, int value) 
	{ 
		cout<<"Going to set the (key, "<< 
			"value) : (" << key << ", " << value << ")"<<endl; 
		if (map[key] != NULL) { 
			Node *node = map[key]; 
			node->value = value; 
			deleteNode(node); 
			addToHead(node); 
		} 
		else { 
			Node *node = new Node(key, value); 
			map[key]= node; 
			if (count < capacity) { 
				count++; 
				addToHead(node); 
			} 
			else { 
				map.erase(tail->pre->key); 
				deleteNode(tail->pre); 
				addToHead(node); 
			} 
		} 
	}
};

int main(){
    { 
		
		LRUCache cache(2); 

		// it will store a key (1) with value 
		// 10 in the cache. 
		cache.set(1, 10); 

		// it will store a key (2) with value 20 in the cache. 
		cache.set(2, 20); 
		cout<<"Value for the key: 1 is " << cache.get(1)<<endl; // returns 10 

		// removing key 2 and store a key (3) with value 30 in the cache. 
		cache.set(3, 30); 

		cout<<"Value for the key: 2 is " << 
				cache.get(2)<<endl; // returns -1 (not found) 

		// removing key 1 and store a key (4) with value 40 in the cache. 
		cache.set(4, 40); 
		cout<<"Value for the key: 1 is " << 
			cache.get(1)<<endl; // returns -1 (not found) 
		cout<<"Value for the key: 3 is " << 
						cache.get(3)<<endl; // returns 30 
		cout<<"Value for the key: 4 is " << 
						cache.get(4)<<endl; // return 40 
						
		return 0;
	} 
}