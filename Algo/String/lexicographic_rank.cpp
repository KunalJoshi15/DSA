#include<bits/stdc++.h>

using namespace std;
/*
There is a better approach to find the lexicographic rank of all the characters which are present in the array itself.
STRING.
Initial step will be we will be checking all the characters which are to the right side of the current char which is being considered.
Now fix the first character in the array and the repeat the same process.
*/
const int CH=256;
int fact(int n){
	if(n<=1) return 1;
	return n*fact(n-1);
}

int lexRank(string &str){
	int res=1;
	int n = str.length();
	int mul = fact(n);
	int count[CH] = {0};

	for(int i=0;i<n;i++){
		count[str[i]]++;
	}
	// This basically counts the cumulative sum. We can now easily find all the characters which are smaller than some particular value.
	for(int i=1;i<CH;i++){
		count[i] += count[i-1];
	}

	for(int i=0;i<n-1;i++){
		// This particular process is used to find the factorial at O(1) time.
		// Here while considering the first element. We will be checking the values which are less than the current element.
		// The count of those will be multiplied.
		mul = mul/(n-i);
		res = res+(count[str[i]-1]*mul);
		// The current element is considered. Therefore the elements which are to the right side count will be decreased by 1.
		for(int j=str[i];j<CH;j++){
			count[j]--;
		}
	}
	return res;
}

int main()
{
	string s1;
	cin>>s1;
	cout<<lexRank(s1);
}