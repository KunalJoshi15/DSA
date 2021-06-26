#include<bits/stdc++.h>

using namespace std;

int main(){
	int a1[] = {1,2,3,4,5,7,8};
	int a2[] = {1,3,5,6,7,8,99};
	int n1 = 7;
	int n2 = 7;
	int i=0,j=0;
	while(i<n1 and j<n2){
		if(i>0 and a1[i-1]==a1[i]){
			i++;
			continue;
		}
		if(a1[i]<a2[j]){
			i++;
		}
		else if(a2[j]<a1[i]){
			j++;
		}else{
			solution.push_back(a1[i]);
			i++;
			j++;
		}
	}
}