#include<bits/stdc++.h>

using namespace std;

int main()
{
    // Vectors are basically used for the creation of the dynamically allocated memory.
    vector<vector<int>> arr;
    int m=3,n=3;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            arr[i].push_back(10);
        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
    }
}

//To pass a 2D array we can use the already defined array structure or the pointer of pointers can be used.
// The other thing which is being represent
// In case of C++ we can even create the jagged arrays in these types of arrays the rows aren't of the same size. each row can have different sizes.
// IN CASE OF THE VECTOR OF VECTORS WE CAN DYNAMICALLY ALLOCATE THE ROWS AS WELL AS THE COLUMNS.