#include<bits/stdc++.h>

using namespace std;

void occur(int arr[])
{
    for(int i=0;i<sizeof(arr)/sizeof(int);i++)
    {
        int count=0;
        for(int j=0;j<sizeof(arr)/sizeof(int);j++){
            if(arr[i]==arr[j])
            {
                count++;
            }
        }
        if(count%2!=0)
            cout<<arr[i];
    }
}
void occur2(int arr[])
{
    for(int i=0;i<sizeof(arr)/sizeof(int);i++)
    {
        //Find the XOR of all the numbers then the number which is remaining is the one having the odd value.
    }
}
// We can find the O(n^2) solution.
int main()
{
    int arr[]={4,3,4,4,4,5,5};
    occur(arr);
}