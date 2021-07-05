#include<bits/stdc++.h>

using namespace std;

struct Inverval{
	int start;
	int end;
};

bool cmp(Interval i1,Interval i2){
	return i1.start<i2.start;
}

void mergeIntervals(Interval arr[],int n)
{
	sort(arr,arr+n,cmp);
	int res=0;

	for(int i=1;i<n;i++){
		if(arr[res].end>=arr[i].start){
			arr[res].end = max(arr[res].end,arr[i].end);
			arr[res].start=min(arr[res].start,arr[i].start);
		}
		else{
			res++;
			arr[res] = arr[i];
		}
	}

	for(int i=0;i<=res;i++){
		cout<<arr[i].start<<" "<<arr[i].end<<endl;
	}
}


int main()
{
	/*
	There are two ways in which we can check whether two intervals are overlapping.
	1) the one with the larger start time should be present in the other interval range for it to overlap.
	2) the one with the smaller end time should be present within the other interval to overlap.
	From these two conditions one needs to be followed for overlapping the interval.
	
	Naive solution to this problem will be:
	In case of the naive solution we will compare current interval will all other interval and we check whether it is overlapping with some other interval.
	If the current one is overlapping with some then simply combine those intervals and remove te older interval.
	The overlapping condition is as follows.
	start = min(i1.start,i2.start);
	end = max(i1.end,i2.end);
	This particular solution is O(n^3) because deletion of a particular interval also takes O(n) time.
	
	There is an effiecient solution to this problem we either sort in the increasing order of the start time or the decreasing order of the end time.
	The idea for the particular algorithm is that we have initially sorted all the values as per the start time. Then xi will merge with mj interval which is just before.
	*/
	Interval arr[] = {{5,10},{3,15},{18,30},{2,7}};
	int n = sizeof(arr)/sizeof(Interval);
	mergeIntervals(arr,n);



	// If two of the intervals are overlapping then we will be take the start time of the first interval and the end time of other.

}