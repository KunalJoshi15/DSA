// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to rearrange the characters in a string such that 
    //no two adjacent characters are same.
    string rearrangeString(string str)
    {
    	// Your code here
    	string res = "";
    	int n = str.size();
    	int hash[256] = {0};
    	
    	for(int i=0;i<n;i++){
    	    hash[str[i]]++;
    	}
    	priority_queue<pair<int,char>> pq;
    	
    	for(int i=0;i<256;i++){
    	    if(hash[i]>0){
    	        pq.push({hash[i],char(i)});
    	    }
    	}
    	int c=0;
    	pair<int,char> prev={-1,'#'};
    	while(!pq.empty())
    	{
    	    c++;
    	    char c=pq.top().second;
    	    int freq=pq.top().first;
    	    pq.pop();
    	   // cout<<c<<" ";
    	    res+=c;
    	    if(prev.first>0)
    	    pq.push(prev);
    	    
    	    freq--;
    	    prev={freq,c};
    	}
        if (res.length() != str.length())
    		return "-1";
    
    	return res;
    }
};

// { Driver Code Starts.

int checker(string str, string pat)
{
    int freq[26];
    for(int i=0;i<26;i++)
        freq[i]=0;
    if(str.length()!=pat.length())
        return 0;
    for(int i=0;i<str.length();i++)
    {
        freq[str[i]-97]--;
        if(pat[i]<97 || pat[i]>122)
            return 0;
        freq[pat[i]-97]++;
    }
    for(int i=0;i<26;i++)
        if(freq[i]!=0)
            return 0;
    for(int i=0;i<pat.length()-1;i++)
        if(pat[i]==pat[i+1])
            return 0;
    return 1;
}

int main()
{
	int t;
	cin>>t;
	cin.ignore(INT_MAX, '\n');
	while(t--)
	{
	    string str,ret;
	    cin>>str;
	    Solution ob;
	    ret = ob.rearrangeString(str);
	    cout << checker(str, ret) << endl;
	}
    return 0;
}  // } Driver Code Ends