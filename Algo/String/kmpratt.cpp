// We need to find a prefix that is the suffix as well.
// The longest one is considered.

// Naive code for finding the strongest prefix array is 
// KMP algorithm is very effiecient algorithm for finding the string matching index.
// This algorithm basically leverages the idea of computation of the hash for the matrix.

#include <bits/stdc++.h> 
using namespace std; 
// THe overall complexity of this particular naive approach is O(n^3)
int longPropPreSuff(string str, int n){
    for(int len=n-1;len>0;len--){
        bool flag=true;
        for(int i=0;i<len;i++)
            if(str[i]!=str[n-len+i])
                flag=false;
                
        if(flag==true)
            return len;
    }
    return 0;
}

void fillLPS(string str, int *lps){
    for(int i=0;i<str.length();i++){
    	// For all the indices the prefix and the suffix are calculated.

        lps[i]=longPropPreSuff(str,i+1);
    }
}
// This particular algorithm is an effiecient algorithm to create an array of O(n) 
// The prefix which is associated with the first element is always 0.
void fillLPS2(string str,int *lps){
	int n= str.length();
	// Initially set the len as 0 and we will be starting with the first index which is present.
	int len=0;
	int i=1;
	while(i<n){
		// If the character has matched then we will be simply incrementing the len variable.
		if(str[i]==str[len]){
			len++;
			lps[i]=len;
			i++;
		}else{
			if(len==0) {
				lps[i] = 0;
				i++;
			}
			else{
				len = lps[len-1];
			}
		}
	}
}

// Whenever there is a match then we will directly match the next character.
void KMP(string pat,string txt){
	int N = txt.length();
	int M = pat.length();
	// Here we will be creating the prefix array for the pattern which is present with us.
	fillLPS(pat,lps);
	int i=0,j=0;

	while(i<N){
		if(pat[i]==txt[j]){
			i++;
			j++;
		}
		// This means that the pattern has been matched.
		if(j==m){
			cout<<(i-j);
			j = lps[j-1];
		}
		else if(i<N and pat[i]!=txt[i]){
			if(j==0) {
				i++;
			}
			else{
				j = lps[j-1];
			}
		}
	}
	int lps[M];
}

 
int main() 
{ 
    string txt = "abacabad";int lps[txt.length()];
    fillLPS(txt,lps);
    for(int i=0;i<txt.length();i++){
        cout<<lps[i]<<" ";
    }
    // We can fill the pattern as per our requirement. This is the only case that is needed in case of the longest prefix array.
    return 0; 
} 