#include<bits/stdc++.h>

using namespace std;

int main()
{
	int a1[] = {1,4,5,6,7,8};
	int a2[] = {4,7,8,9,10};
	vector<int> solution;
	int n1=6;
	int n2=5;
	int i=0,j=0;
	while(i<n1 and j<n2){
		if(i>0 and a1[i-1]==a1[i]){
			i++;
			continue;
		}
		if(j>0 and a2[j-1]==a2[j]){
			j++;
			continue;
		}
		if(a1[i]<a2[j]){
			solution.push_back(a1[i]);
			i++;
		}
		else if(a1[i]>a2[j]){
			solution.push_back(a2[j]);
			j++;
		}else{
			solution.push_back(a1[i]);
			i++;
			j++;
		}
	}

	while(i<n1){
		if(i>0 and a1[i]!=a1[i-1]){
			solution.push_back(a1[i]);
			i++;
		}
	}
	while(j<n2){
		if(j>0 and a2[j]!=a2[j-1]){
			solution.push_back(a2[j]);
			j++;
		}
	}
}