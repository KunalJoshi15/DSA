#include<iostream>
#include<queue>
using namespace std;

class Compare{
    // Here we are performing the operator overloading and this will now be passed when the particular function will be called.
    public:
        bool operator()(int a,int b){
            return a<b;
        }
};

int main()
{
    int arr[] = {10,15,20,13,6,90};
    int n = sizeof(arr)/sizeof(int);
    // By default this particular class makes a max heap if we want to create a min heap then we can parameterize it to some other extent.
    priority_queue<int> heap;
    priority_queue<int,vector<int>,Compare> p;
    // FOR CUSTOM min heap we will be using priority_queue<int,vector<int>,greater<int>>
    // We can use the custom comaprateor.
    for(int x:arr){
        heap.push(x);
    }

    while(!heap.empty()){
        cout<<heap.top()<<endl;
        heap.pop();
    }
    return 0;
}