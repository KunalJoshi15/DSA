#include<bits/stdc++.h>

using namespace std;
//In the climbin ladder problem we need to find the way in which we can reach a particular position. we can take one two or three steps at each case.
int climbingLadder(int N){
	if(n<0) return -;
	if(N==0){
		return 1;
	}
	return climbingLadder(N-1)+climbingLadder(N-2)+climbingLadder(N-3);
}

int main()
{
	int N=4;
	int ways = climbingLadder(N);
}