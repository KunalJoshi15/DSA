#include<iostream>
#include<vector>

using namespace std;

int main(){
    //Demo Vector 
    //here we have simply initialized a particular vector.
    vector<int> arr={123,12,1};
    arr.push_back(16);
    // There is one more initialization using the fill constructor.
    vector<int> visited(100,0);
    //Pop Back -> This is used to remove the last element from the array.
    arr.pop_back();

    //push_back is the method that is used to add the elements in the O(1) time.
    cout<<arr.size()<<endl;
    // The underlying structure that are used under the vectors are called the  
    cout<<arr.capacity()<<endl;
    // This is used to find the size of the array
}