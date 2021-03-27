#include<bits/stdc++.h>

using namespace std;

vector<int> removeDuplicates(vector<int> inputs){
    set<int> s;
    vector<int> result;

    for(int i=0;i<inputs.size();i++){
        if(s.find(inputs[i])==s.end()){
            result.push_back(inputs[i]);
        }
    }
}