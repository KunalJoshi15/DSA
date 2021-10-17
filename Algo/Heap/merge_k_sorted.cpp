#include<bits/stdc++.h>

using namespace std;
/*
In case of the super naive solution we will be creating an array which will be having all the elements and then we will be simply sorting the array
kn log kn will be the time complexity of super naive solution.
*/
class Triplet{
public:
    int key;
    int aPos;
    int ePos;

    Triplet(int k,int ap,int vp){
        key=k;
        aPos=ap;
        ePos=vp;
    }
};

struct myComp{
    bool operator()(Triplet &t1,Triplet &t2){
        return t1.key>t2.key;
    }
};
vector<int> mergeKArrays(vector<vector<int> > arr) 
{ 
    vector<int> res; 
      
    for(vector<int> v: arr) 
    { 
        for(int x:v) 
            res.push_back(x); 
    } 
      
    
    sort(res.begin(),res.end());

    return res;
}

vector<int> mergeArraysEff(vector<int> arr1,vector<int> arr2){
    int i=0,j=0;vector<int> arr3;

    while(i<arr1.size() and j<arr2.size()){
        if(arr1[i]<arr2[j]){
            arr3.push_back(arr1[i++]);
        }
        else{
            arr3.push_back(arr2[j++]);
        }
    }

    while(i<arr1.size()){
        arr3.push_back(arr1[i++]);
    }

    while(j<arr2.size()){
        arr3.push_back(arr2[j++]);
    }
    return arr3;
}

vector<int> mergeKArraysEff(vector<vector<int>> arr){
    vector<int> res = arr[0];

    for(int i=1;i<arr.size();i++){
        res = mergeArraysEff(res,arr[i]);
    }
    return res;
}

// The most effiecient solution for this particular problem is using the heaps. 
// in this case we will be creating the heap that will be having the starting element of all the arrays and the array number and the element number.
vector<int> mergeKArraysHeap(vector<vector<int>> arr){
    vector<int> res;

    priority_queue<Triplet,vector<Triplet>,myComp> pq;

    for(int i=0;i<arr.size();i++){
        Triplet t(arr[i][0],i,0);
        pq.push(t);
    }

    while(pq.empty()==false){
        Triplet curr = pq.top();
        pq.pop();
        res.push_back(curr.key);
        int ap = curr.aPos;
        int vp = curr.ePos;

        if(vp+1<arr[ap].size()){
            Triplet t(arr[ap][vp+1],ap,vp+1);
            pq.push(t);
        }
    }
    return res;
}

int main()
{
    vector<vector<int> > arr = { { 10, 20, 30 }, 
                              { 5, 15 }, 
                              { 1, 9, 11, 18 } }; 
  
    vector<int> res = mergeKArraysHeap(arr); 
  
    cout << "Merged array is " << endl; 
    for (auto x : res) 
        cout << x << " "; 
    
    return 0; 
}