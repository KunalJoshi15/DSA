#include<bits/stdc++.g>

using namespace std;

const int CHAR = 256;
int nonRep(string &str){
	int fI[char];
	fill(fI,fI+CHAR,-1);
	// Here we are initializing all the values which are present in the map as per our requirement.
	// The initial pass takes the time complexity equivalent to the current case.
	// iF the particular element is found and to its index the value of -1 is stored then we make the changes accordingly.
	for(int i=0;i<str.length();i++){
		if(fI[str[i]]==-1){
			fI[str[i]]=i;
		}
		else{
			// OTHERWISE THE NUMBER IS REPEATING THEREFORE CHANGE THE VALLUE TO SOME OTHER VALUE.
			fI[str[i]]=-2;
		}
	}
	int res = INT_MAX;
	for(int i=0;i<CHAR;i++){
		if(fI[i]>=0){
			// This basically leads to the first index that is the closest.
			res = min(res,fI[i]);

		}
	}
	return (res==INT_MAX)?-1:res;
}

int main()
{
	// Here in this particular problem we check the repeated characters which are present in the array.
	// According to the repeated characters. If there are no such elements then return -1.
	// Here we can use the same approach in which we will be maintaining the hash map and the first value from the left side which has the value as 1 will be considered.
}