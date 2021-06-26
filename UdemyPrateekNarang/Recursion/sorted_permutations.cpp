#include<bits/stdc++.h>
using namespace std;

void findPermuations(string s,vector<string> &output,int i){
    if(i==s.size()-1){
        if(find(output.begin(),output.end(),s)==output.end()){
            output.push_back(s);
        }
        return;
    }
    for(int j=i;j<s.size();j++){
        swap(s[i],s[j]);
        findPermuations(s,output,i+1);
        swap(s[i],s[j]);
    }
}

vector<string> findSortedPermutations(string s){
    //Your code goes here. Do not change the function or parameters. You can use helper functions if needed.
    vector<string> output;
    findPermuations(s,output,0);
    sort(output.begin(),output.end());
    return output;
}

int main()
{
    string s="bbca";
    vector<string> answer = findSortedPermutations(s);
    for(string s:answer){
        cout<<s<<endl;
    }
}
	/*
	The particular concept of finding the permutatios works in this way.
	abc is the given string to us
	a[b-c] b[a-c] c[a-b]
	Here we are simply fixing the first character and then asking the recursion to find the permutation of the smaller problem.
	In this particular problem the swapping will definitely be performed but we will have to do the backtracking as well otherwise the orignal array that we have will get morphed and it will give us the wrong answer.

	*/