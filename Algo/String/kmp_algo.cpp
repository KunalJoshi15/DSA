#include<bits/stdc++.h>

using namespace std;
// Here in order to reduce the complexity of KMP algorithm we will be computing the lps array.
// this function will simply create the lps array and then the other part of the code can be performed then.
void lps(vector<int> &lps,string s)
{
	// a single character is always a string. 
	int i=1;
	int n = s.size();
	int j=0;
	while(i<n){
		if(s[i]==p[j]){
			j++;
			lps[i] = j;
			i++;
		}
		else{
			if(j==0){
				lps[i]=0;
				i++;
			}
			else{
				j = lps[j-1];
			}
		}
	}
}

void KMP(string pat,string txt){
	// We will be finding the lengths of the n and m 
    int N=txt.length();
    int M=pat.length();
    int lps[M];
    fillLPS(pat,lps);
    int i=0,j=0;
    while(i<N){
    	// If both the characters are matched then we will be simply moving to the next character.
    	// If the entire pattern is matched then found the pattern in i-j index.
        if(pat[j]==txt[i]){i++;j++;}

        if (j == M) { 
            printf("Found pattern at index %d ", i - j); 
            j = lps[j - 1]; 
        } 
        else if (i < N && pat[j] != txt[i]) { 
            if (j == 0) 
                i++;
            else
                j = lps[j - 1];  
        }
    }
}
int main()
{
	string s="abbaacccaa";
	string p="ab";
	vector<int> lps(p.size(),0);

	findLps(lps,s,p);
}