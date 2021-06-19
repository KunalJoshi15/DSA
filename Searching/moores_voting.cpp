#include<bits/stdc++.h>

using namespace std;
// In case of the moore voting algorithm we find the element which is the candidate to become the majority element.
// Then we will simply find the count of that element in the array in O(n) time.

// There are other O(n) solutions as well. But they mostly require the O(n) space in case of the morre voting algorithm it is not the case.
int majorityElement(int a[], int size)
{
        
    // your code here
    int maj_index = 0;
    int count=1;
    for(int i=1;i<size;i++){
        if(a[maj_index] == a[i]){
            count++;
        }
        else{
            count--;
        }
        if(count==0){
            maj_index=i;
            count=1;
        }
    }
    count=0;
    for(int i=0;i<size;i++){
        if(a[maj_index]==a[i]) count++;
    }
    return (count>size/2)?a[maj_index]:-1;
        
}

int main(){

}