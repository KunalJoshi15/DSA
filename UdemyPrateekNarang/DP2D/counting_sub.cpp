#include<bits/stdc++.h>

using namespace std;

int countSub(string a,string b,int n,int n){
	if((m==-1 and n==-1) or n==-1) return 1;

	if(m==-1){
		return 0;
	}

	if(a[m]==b[n]){
		return countSub(a,b,m-1,n-1)+countSub(a,b,m-1,n);
	}
	return countSub(a,b,m-1,n);
}

int main()
{
	string a = "ABCECDG";
	string b = "ABC";

	cout<<count(a,b,a.size()-1,b.size()-1)<<endl;
}