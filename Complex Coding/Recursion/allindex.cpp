#include<bits/stdc++.h>

using namespace std;

int allIndices(int *arr,int size,int x,int i,vector<int> &output){
    if(size==0) return -1;
    if(arr[0]==x){
        output.push_back(i);
    }
    int smallAns = allIndices(arr+1,size-1,x,i+1,output);
    return smallAns; 
}

vector<int> allIndices2(int *arr,int size,int x,int i){
    vector<int> sol;
    if(i==size) return sol;
    vector<int> smallAns = allIndices2(arr+1,size,x,i+1);
    if(arr[0]==x){
        smallAns.push_back(i);
    }
    return smallAns;
}

vector<int> allIndices3(int *arr,int size,int x,int i){
    vector<int> sol;
    if(i==size) return sol;
    vector<int> smallAns=allIndices3(arr,size,x,i+1);
    if(arr[i]==x){
        smallAns.push_back(i);
    }   
    return smallAns;
}

int main(){
    int n;
    cin>>n;

    int *arr = new int[n];
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        arr[i]=temp;
    }
    int x;
    cin>>x;
    vector<int> output;
    int index = allIndices(arr,n,x,0,output);
    for(int i=0;i<output.size();i++){
        cout<<output[i]<<" ";
    }
    vector<int> output2=allIndices2(arr,n,x,0);
    for(int i=0;i<output2.size();i++){
        cout<<output2[i]<<" ";
    }
    vector<int> output3=allIndices3(arr,n,x,0);
    for(int i=0;i<output3.size();i++){
        cout<<output3[i]<<" ";
    }
}