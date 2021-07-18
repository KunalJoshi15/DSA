#include<bits/stdc++.h>

using namespace std;

int hashValue()

void patternMatching(string &st,string &pat){
	int h=1;
	for(int i=1;i<=m-1;i++){
		h=(h*d)%q;
	}
	int p=0,t=0;
	for(int i=0;i<m;i++){
		p = (p*d+pat[i])%q;
		t = (t*d+st[i])%q;
	}
	for(int i=0;i<=st.size()-pat.size();i++){
		if(p==t){
			bool flag = true;
			// Here this particular condition means that the hash has been matched.
			for(int j=0;j<m;j++){
				if(st[i+j]!=pat[j]){
					flag=false;
					break;
				}
			}
			if(flag==true){cout<<i<<" ";}
		}
		if(i<st.size()-pat.size()){
			t = ((d*(t-st[i]*h))+st[i+m])%q;
			if(t<0) t=t+q;
		}
	}
}

int main()
{
	// In case of the rabin karp string searching algorithm.
	// Here in case of the rabin karp algorithm we use the idea of hashing we don't directly compare the elements which are present.
	// The elements are only compared when the hash is matched.
	// Here the hash value of the current window of elements is consdered.
	// There can be some spurious hits.
	string s;
	string p;
	cin>>s;
	cout<<end;
	cin>>p;
	cout<<endl;
	// The computation of the hashvalue for the current window can be reduced.
	//Weighted sum can reduce the problem of spurious hit.
	patternMatching(s,p);
}