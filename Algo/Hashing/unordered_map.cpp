#include <bits/stdc++.h> 
using namespace std; 

int main(){
    // This is defined inside the bits/stdc++.h header file.
    unordered_map <string,int> m;
    m["gfg"]=20;
    m["ide"]=30;
    m.insert({"courses",15});
    // This lookup which is being performed has the time complexity of O(1) as hashmap is being used in this case.
    if(m.find("ide")!=m.end())
        cout<<"Found";
    else
        cout<<"Not Found ";
    
    cout<<endl;
    
    for(auto it=m.begin();it!=m.end();it++)
        cout<<(it->first)<<" "<<(it->second)<<endl;
    // This is another way of finding whether a particular value is present inside the map or not. IF the count of the particular element is >0 then it is present
    if(m.count("ide")>0)
        cout<<"Found";
    else
        cout<<"Not Found";
    cout<<endl;
    
    cout<<m.size()<<endl;
    m.erase("ide");
    // THis remove the element which is present at the first
    m.erase(m.begin());
    cout<<m.size()<<endl;
    m.erase(m.begin(),m.end());
        
    return 0;
}
    // There is only a subtle difference between the map and the unordered map in paritcular.
    // The underlying data strcuture which is used in case  of the map is a balanced binary search tree.
    // The underlying data structure which is used in case of the unordered_map is the hashing. 

