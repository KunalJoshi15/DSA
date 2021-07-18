#include<bits/stdc++.h>

using namespace std;

/*
Steps that will be followed are:
1) Generate all the substrings.
2) Generate their hash.
3) hash the hash values to club the anagrams into the same bucket.
4) From the frequency counts of the values we can simply find the number of anagram pairs.
*/
vector<int> hashValues(string s,int i,int j){
	vector<int> freq(26,0);

	for(int k=i;k<=j;k++){
		freq[s[k]-'a']++;
	}
	return freq;
}

int anagram_substrings(string s){
	map<vector<int>,int> m;

	for(int i=0;i<s.size();i++){
		for(int j=i;j<s.size();j++){
			vector<int> generated = hashValues(s,i,j);
			m[generated]++;
		}
	}
	// Now we are only left with the last step with the values.
	int ans = 0;
	for(auto a:m){
		int fre = a.second;
		if(fre>=2){
			ans += (fre*(fre-1))/2;
		}
	}
	return ans;
}



int main()
{
	/*
		In this particular approach we use the concept we will be precomputing the hash for two values and then will check whether it is 
		producing the anagram or not.
		The process which can be used if the encoding into a 26 indexes hashmap.
		All the anagrams which are having the same values will be placed at the same location.
		If the value of the pair is >=2 then we will be simply adding fC2 over the answer.
	*/
	string s;
	cin>>s;
	cout<<anagram_substrings(s);
}