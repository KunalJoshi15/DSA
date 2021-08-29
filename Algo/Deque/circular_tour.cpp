#include<bits/stdc++.h>

using namespace std;

// This particular solution is the naive solution therefore will take O(n^2) time period.
int firstPetrolPump(int petrol[],int dist[],int n){
	for(int start=0;start<n;start++){
		int curr_petrol = 0;
		int end = start;

		while(true){
			curr_petrol +=(petrol[end]-dist[end]);
			if(curr_petrol<0)
			{
				break;
			}
			end = (end+1)%n;
			if(end==start){
				// This will give us the petrol pump we need to start with.

				return (start+1);
			}
		}
	}
	// If there is no good petrol pump to start with then this in particular is the answer to the question.
	return -1;
}
// O(n) time and the.
// If the current_petrol is >=0 then we will simply add petrol pumps at the end of the queue.
// If the current petrol pump is <0 then we will simply pop from the front of the deque.
int optimizedPetrolPump1(int petrol[],int dest[],int n){
	deque<int> dq;

	for(int start=0;start<n;start++){
		int curr_petrol = 0;
		int end = start;
		while(true){
			curr_petrol += (petrol[end]-dist[end]);
			if(curr_petrol>=0){
				dq.push_back(end);
			}
			else{
				dq.pop_front();
			}
		}
	}
}
// Here we will be leveraging the idea that if curr petrol becomes negative at pi then none of the petrol pu,ps from p0 to pi can be the solution.
// We can consider the contrary example to back our claim.
// if pk is the particular point where the value has become negative then there couldn't be any starting point before it.

int optimizedPetrolPump2(int petrol[],int dist[],int n){
	int start = 0;
	int curr_pet=0;
	int prev_pet=0;

	for(int i=0;i<n;i++){
		curr_pet += (petrol[i]-dist[i]);

		if(curr_pet<0){
			start = i+1;
			prev_pet+=curr_pet;
			curr_pet=0;
		}	
	// IF AT ANY INSTANCE THE CURR_PET becomes less then 0 then we can simply say that none of the points which are before the current point can be answer.

	return (curr_pet+prev_pet)>=0?(start+1):-1;
}
// prev petrol is the value which we have already calculated.

int main()
{
	int petrol[] = {4,8,7,4};
	int dist[] = {6,5,3,5};

	int n = sizeof(petrol)/sizeof(int);
}