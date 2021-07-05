#include<bits/stdc++.h>

using namespace std;

int matMed(int mat[][5],int r,int c){
    int min=mat[0][0],max = mat[0][c-1];

    for(int i=1;i<r;i++){
        if(mat[i][0]<min) min = mat[i][0];
        if(mat[i][c-1]>max) max=mat[i][c-1];
    }
    // This will represent the position where the median will be present in the sorted array.
    // This is the exact position
    int medPos = (r*c+1)/2;

    while(min<max){
        //Here find the median of the min and the max element. The max and the min element can be found from an array in O(R) time complexity.
        // We will be finding all the elements which are smaller than the mid element. It will help us to get the position where the value is present.
        int mid = (min+max)/2;
        int midPos=0;
        for(int i=0;i<r;i++){
            // This will give us the position  of the first greater element.
            // here we will be simply changing the max to mid
            midPos += upper_bound(mat[i],mat[i]+c,mid)-mat[i];
        }
        if(midPos<medPos){
            min=mid+1;
        }
        else{
            max = mid;
        }
    }
    return min;
}

int main()
{

}