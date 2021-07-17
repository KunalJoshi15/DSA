#include<bits/stdc++.h>

using namespace std;

void generatePrefix(int n,int ones,int zeros,string output){
	// FOR ones tere is no condition. So basically create the recursion tree for these particular cases.
	// BASE CASE
	if(n==1){
		cout<<output<<endl;
		return;
	}

	generatePrefix(n-1,ones+1,zeros,output+"1");
	if(ones>zeros){
		generatePrefix(n-1,ones,zeros+1,output+"0");
	}
	return;
}

int main()
{
	int n;
	cin>>n;
	string output="";
	int ones=0;
	int zeros=0;
	generatePrefix(n,ones,zeros,output);
}