#include<bits/stdc++.h>

using namespace std;

int main()
{
	vector<int> a1 = {-1,5,10,20,3};
	vector<int> a2 = {26,134,135,15,17};
	// Here there is always a brute force solution which has a time complexity of O(n^2)	
	// Which element will be having the minimum sum.
	// Time complexity for this particular approach will be O(M log M+N log M)
	int p1,p2;
	int diff=INT_MAX;
	sort(a2.begin(),a2.end());

	for(int x:a1){
		// This particular function can be used to find the lower bound of the elements that are present in the first array.
		auto lb = lower_bound(a2.begin(),a2.end(),x)-a2.begin();
		// Left 
		if(lb>=1 and x-a2[lb-1]<diff){
			diff = x-a2[lb-1];
			p2 = x;
			p1 = a2[lb-1];
		}
		// Greater / right
		// Here the difference which is taken is a2[lb]-x because the value of a2[lb] would be larger.
		if(lb!=a2.size() and a2[lb]-x<diff)
		{
			diff = a2[lb]-x;
			p1 = x;
			p2 = a2[lb];
		}
	}
	return 0;
}