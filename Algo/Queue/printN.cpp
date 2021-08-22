#include<bits/stdc++.h>

using namespace std;

void printN(int n){
	queue<string> q; // Here we have created the queue.
	q.push("5");
	q.push("6");

	for(int i=0;i<n;i++){
		string curr = q.front();
		cout<<curr<<" ";
		q.pop();
		q.push(curr+"5");
		q.push(curr+"6");
	}
}

int main()
{
	// Here we want to print the 10 digits numbers which have 5 and 6 as the digits in it.
	int n;
	cin>>n;
	printN(n);	
}