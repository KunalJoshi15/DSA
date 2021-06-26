#include<bits/stdc++.h>

using namespace std;

void twoRepeating(int *arr,int n){
	int XOR = arr[0];
	int right_most_bit,X=0,Y=0,size=n;

	for(int i=1;i<=n;i++){
		XOR ^= i;
	}

	for(int i=0;i<size;i++){
		XOR  ^= A[i];
	}
	// This will fetch us the right most bit that is present.
	right_most_bit = XOR&~(XOR-1);
	// Divide the elements into 2 groups based on the right most set bit.

	for(int i=0;i<size;i++){
		if((A[i] & right_most_bit)!=0)
			X = X^A[i];
		else
			Y = Y^A[i];
	}

	for(int i=1;i<=n;i++){
		if((i&right_most_bit)!=0){
			X = X^i;
		}
	}
}

int main()
{
	int arr[] = {1,4,5,6,3,2,5,2};
	int n=6;
	twoRepeating(A,n);
}