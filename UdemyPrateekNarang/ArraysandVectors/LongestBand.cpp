#include<bits/stdc++.h>

using namespace std;

int largestBand(vector<int> arr){
    int n = arr.size();
    unordered_set<int> s;

    for(int x:arr){
        s.insert(x);
    }
    int largestLen=1;
    for(auto element:s){
        int parent=element-1;
        // We will be checking whether the element-1 exists if it exists
        if(s.find(parent)==s.end()){
            //Find the entire band
            int next_no = element+1;
            int cnt=1;
            while(s.find(next_no)!=s.end()){
                next_no++;
                cnt++;
            }
            if(cnt>largestLen){
                largestLen=cnt;
            }
        }
    }
}

int main(){
    /*
    Sorting can be used for this purpose. Find all the bands which are possible find the length of the maximum band. 
    We need to find the starting of a particular band and according to it other things are also taken care of.
    For the lookup the best datastructure which we can use is the unordered_set.
    We will consider the elements which can possibly form a band.
    The overall complexity is O(n)-> THis is better than the sorting technique as the time complexity in that case is O(n log n) as there isn't any algorithm that has time complexity better than this.
    The traversal in this particular case is usually done twice therefore the loo
    Therefore the loop which is running is O(n)
    */
   vector<int> arr{1,8,3,0,18,5,2,4,10,7,12,6};
   cout<<largestBand(arr);
}