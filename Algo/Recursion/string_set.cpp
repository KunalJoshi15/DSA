#include<bits/stdc++.h>

using namespace std;

vector<string> powerSet(string s){
    vector<string> sol;
    if(s.size()==0){
        sol.push_back("");
        return sol;
    }
    vector<string> smallAns = powerSet(s.substr(1));
    sol = smallAns;
    for(int i=0;i<smallAns.size();i++){
        sol.push_back(s[0]+smallAns[i]);
    }
    // There is the smallAns which is used in the particular category.
    return sol;
    // One particular way of finding all the subsequences of string is to consider the first character of the string once and 
    // other time we don't have to consider that.
}

int main(){
    string s;
    cin>>s;
    vector<string> solution = powerSet(s);

    for(int i=0;i<solution.size();i++){
        cout<<solution[i]<<endl;
    }
    return 0;
}