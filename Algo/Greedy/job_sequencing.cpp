#include<iostream>
#include<algorithm>

using namespace std;

struct Job{
	char id;
	int dead;
	int profit;
};

bool comparison(Job a,Job b){
	return a.profit>b.profit;
}

void printJobScheduling(Job arr[],int n){
	// Sort all jobs according to decreasing order of profit.
	sort(arr,arr+n,comparison);

	int result[n]; // to store result of jobs.
	bool slot[n]; // to keep track of free time slots.

	for(int i=0;i<n;i++){
		slot[i] = false;
		// all the slots are free currently.
	}

	for(int i=0;i<n;i++){
		for(int j=min(n,arr[i].dead)-1;j>=0;j--){
			if(slot[j]==false){
				result[j] = i; // add the current job to result.
				slot[j] = true;
				break;
			}
		}
	}
	// print the result
	for(int i=0;i<n;i++){
		if(slot[i]){
			cout<<arr[result[i]].id<<" ";
		}
	}
}

int main()
{
	Job arr[] = {
		{'a',2,100},
		{'b',1,19},
		{'c',2,27},
		{'d',1,25},
		{'e',3,15}
	};

	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<"Following is maximum profit sequence of jobs \n";

	printJobScheduling(arr,n);
}