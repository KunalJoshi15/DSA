#include<bits/stdc++.h>

using namespace std;

/*
Queue data structure is the most commonly used data structure it is basically a FIFO data structure.
Which means the data which has been added to the front will be the first item to be removed.
In case of the queue data structure we push the data from one side and remove data from the other side.
rear would remain the same most of the time.
Queue data structure is used when there is a single resource and there are many consumers for that particular resource.
Sync between slow and fast devices.
OS. CN and variations:deque,priority queue.
queues are used for pushing the data.
*/

class Queue{
public:
	int front,rear,size;
	unsigned capacity;
	int *array;
};
// this in particular is the boiler plate code for implementing the arrays.
Queue* createQueue(unsigned capacity){
	Queue* queue = new Queue();
	queue->capacity = capacity;
	queue->front = queue->size = 0;

	queue->rear = capacity-1;
	queue->array = new int[(queue->capacity*sizeof(int))];
	return queue;
}

int isFull(Queue *queue){
	return (queue->size==queue->capacity);
}

int isEmpty(Queue *queue){
	return (queue->size==0);
}

void enqueue(Queue *queue,int item){
	if(isFull(queue)){
		return;
	}
	queue->rear = (queue->rear+1)%queue->capacity;
	queue->array[queue->rear] = item;
	queue->size = queue->size+1;
	cout<<item<<"enqueued to the queue\n";
}

int dequeue(Queue *queue){
	if(isEmpty(queue)){
		return INT_MIN;
	}
	int item = queue ->array[queue->front];
	queue->front = (queue->front+1)%queue->capacity;
	queue->size = queue->size-1;
	return item;
}

int front(Queue *queue){
	if(isEmpty(queue)) return INT_MIN;
	return queue->array[queue->rear];
}

int rear(Queue *queue){
	if(isEmpty(queue)) return INT_MIN;
	return queue->array[queue->rear];
}

int main() 
{ 
	Queue* queue = createQueue(1000); 

	enqueue(queue, 10); 
	enqueue(queue, 20); 
	enqueue(queue, 30); 
	enqueue(queue, 40); 

	cout << dequeue(queue) 
		<< " dequeued from queue\n"; 

	cout << "Front item is "
		<< front(queue) << endl; 
	cout << "Rear item is "
		<< rear(queue) << endl; 

	return 0; 
} 