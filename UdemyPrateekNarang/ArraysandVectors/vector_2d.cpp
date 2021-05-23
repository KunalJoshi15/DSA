#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<vector<int>> arr = {
        {1,2,3},
        {4,5,6},
        {7,8,9,10},
        {11,12}
    };
    // sort(arr,arr+n) this is used for sorting the n elements which are present in the array itself.
    // The difference between the 2-D array and a 2D vector is that each row in case of the 2D vector can have different number of elements.
    // The looping in case of the arrays can be done through the 2d vector
    // The elements of the vectors ccan be accessed similar to the array.
    for(int i=0;i<arr.size();i++){
        for(int number: arr[i]){
            cout<<number;
        }
        cout<<endl;
    }
    // each and every array itself is a vector.
}