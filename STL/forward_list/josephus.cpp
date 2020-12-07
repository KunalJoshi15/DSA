#include<bits/stdc++.h>
using namespace std;
int getSol(int n,int k)
{
    list<int> l;
    for(int i=0;i<n;i++)
    {
        l.push_back(i);
    }
    auto iterator = l.begin();
    while(l.size()>1)
    {
        for(int count=1;count<k;count++)
        {
            iterator++;
            if(iterator==l.end())
                iterator=l.begin();
        }
        l.erase(iterator);
        if(iterator==l.end())
            iterator = l.begin();
    }
    return l.front();
}
int main()
{
    cout<<getSol(7,3);
    return 0;
}