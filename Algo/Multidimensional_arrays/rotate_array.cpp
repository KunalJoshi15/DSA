#include<bits/stdc++.h>
using namespace std;

void rotate(int arr[4][4]){
    int temp[4][4];

    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            // Check one test input array and the resultant array. If they are having the similarities then this is followed.
            temp[4-j-1][i] = arr[i][j];
        }
    }

    // Here then simply copy the array to the orignal one. 
}
// There is a better solution to this particular problem in that we will simply take the current matrix and find the transpose of that matrix and then simply swaps the rows.
// We can find the transpose of the matrix using the same approach as before. Therefore this will make the entire solution inplace.

int main()
{
    int arr[4][4] = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };
    // The naive algorithm works with the idea that the first column becomes the last row and the second column becomes the second last row.
    // This similar process is followed.

}