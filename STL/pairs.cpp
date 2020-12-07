#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<pair<int,char>> mp;
    mp.push_back(make_pair(2,'a'));
    mp.push_back(make_pair(3,'b'));
    mp.push_back(make_pair(1,'o'));
    sort(mp.begin(),mp.end());
    for(int i=0;i<mp.size();i++)
    {
        cout<<mp[i].second<<endl;
    }
}