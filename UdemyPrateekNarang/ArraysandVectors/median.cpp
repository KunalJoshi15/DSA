#include<bits/stdc++.h>

using namespace std;
/*
This particular solution is very elegant solution for finding the median of the two sorted arrays as it leverages the concept of the binary search as per our requirement.
*/
double findMedian(vector<int> &a1,vector<int> &a2){
	int n1 = a1.size();
	int n2 = a2.size();
	int begin1 = 0;
	int end1 = n1-1;
	while(begin1<=end1){
		int i1 = n1;
		int i2 = (n1+n2+1)/2-i1;

		int min1 = (i1==n1)?INT_MAX:a1[i1];
		int max1 = (i1==0)?INT_MIN:a1[i1-1];
		int min2 = (i2==n2)?INT_MAX:a2[i2];
		int max2 = (i2==0)?INT_MIN:a2[i2-1];

		if(max1<=min2 and max2<=min1){
			if((n1+n2)%2==0){
				return ((double)(max(max1,max2)+min(min1,min2))/2);
			}
			else{
				return max(max1,max2);
			}
		}
		else if(max1>min2){
			end1 = i1-1;
		}else{
			begin1 = i2-1;
		}
	}
}

int main(){
	vector<int> arr= {1,2,3,4,5,6};
	vector<int> arr2={2,3,4,5,7,8,9};
	// Here the size of the array first needs to be smaller than the other array.

	double median = findMedian(arr,arr2);
	cout<<median;
}