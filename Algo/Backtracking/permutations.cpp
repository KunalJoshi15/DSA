#include<bits/stdc++.h>

using namespace std;

void permute(string str,int l,int r){
	if(l==r){
		if(str.find("AB")==string::npos){
			// here it means that the generated string does not contain AB as a substring
			cout<<str<<" ";
		}
	}
	else{
			for(int i=l;i<=r;i++){
				swap(str[i],str[l]);
				permute(str,l+1,r);
				swap(str[i],str[l]);
			}
		}
}
// in case of the optimized approach we cut recursion beforehand only so that we don't have to wait for later point in time.
bool isSafe(string str,int l,int i,int r){
	if(l!=0 and str[l-1]=='A' and str[i]=='B'){
		return false;
	}
	if(r==(l+1) and str[i]=='A' and str[l]=='B'){
		return false;
	}
	return ture;
}


void permutations(string str,int l,int r){
	if(l==r){
		cout<<str<<" ";
	}
	else{
		for(int i=l;i<=r;i++){
			if(isSafe(str,l,i,r)){
				swap(str[i],str[l]);
				permutations(str,l+1,r);
				swap(str[i],str[l]);
			}
		}
	}
}
int main() {
	
	string str="ABC";
	
    permute(str,0,str.length()-1);      
    return 0;  
	
}