#include<bits/stdc++.h>

using namespace std;

int main(){
    vector<int> v;

    for(int i=0;i<5;i++){
        v.push_back(i+1);
    }
    vector<int>::iterator it;

    for(it=v.begin();it!=v.end();it++){
        cou<<*it<<endl;
    }

    string s = "KUNAK";
    string s1(s,2,3);
    cout<<s<<endl;
    cout<<s1<<endl;

    string s2 = s.substr(2,4);
    cout<<s2<<endl;

    if(s1.compare(s2)==0){
        cout<<"is equal to"<<s2>>endl;

    }else{
        cout<<"is not equal to"<<s2<<endl;
    }
    pair<int,char> p;
    pair<int,char> p2(1,'2');
    // make_pair function can also be used to create the pair of the values.
    set<int> s;
    s.insert(1);
    // ELEMENTS WILL BE PUSHED ACCORDING TO IT.
    set<int>::iterator it;
    // Iterator will be this
    if(s.find(6)==s.end()){
        cout<<"Element not found";
    } 
    else{
        cout<<"Element found";
    }
    int arr[] = {1,2,3,4,5,67};
    map<int,int> m;

    for(int i=0;i<7;i++){
        m[arr[i]]=m[arr[i]]+1;
    }
    map<int,int>::iterator it;


    for(it=map.begin();it!=map.end();it++)
    {
        cout<<it->first<<" :"<<it->second;
    }
    m.erase(1);
}