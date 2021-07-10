#include<bits/stdc++.h>

using namespace std;

int allIndexes(int *input,int n,int x,int *output){
    if(n==0){
        return 0;
    }
    int smallAns = allIndexes(input+1,n-1,x,output);
    if(input[0]==x){
        for(int i=smallAns-1;i>=0;i--){
            output[i+1] = output[i]+1;
        }
        output[0]=0;
        smallAns++;
    }
    else{
        for(int i=smallAns-1;i>=0;i--){
            output[i] = output[i]+1;
        }
    }
    return smallAns;
}

int main()
{
    int n;
    cin>>n;

    int *input = new int[n];
    for(int i=0;i<n;i++){
        cin>>input[i];
    }

    int x;
    cin>>x;
    int *output = new int[n];
    int size = allIndexes(input,n,x,output);

    for(int i=0;i<size;i++){
        cout<<output[i]<<" ";
    }
}