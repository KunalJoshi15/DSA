#include<bits/stdc++.h>

using namespace std;
//Consider the corner cases before only.
int trappedWater(vector<int> heights){
    int n=heights.size();
    if(n<=2) return 0;
    //Left Max;
    vector<int> left(n,0),right(n,0);
    left[0] = heights[0];
    right[n-1]=heights[n-1];

    for(int i=1;i<n;i++){
        left[i] = max(left[i-1],heights[i]);
        right[n-i-1] = max(right[n-i],heights[n-i-1]);
    }

    //Water
    int water=0;
    for(int i=0;i<n;i++)
        water+=min(left[i],right[i])-heights[i];
    return water;
}
/*
BRUTE FORCE
In the extreme bars the water cannot be trapped. Therefore the place wherer the water can be trapped is the middle bars.
consider each of the middle bar and find the maximum height left and max bar lengeth at right to it.
This will be computed for all the bars that we go through.
 O(n^2) will be the worst case time complexity of this particular problem. 
*/

int main(){
    // Between the bars there are some of the empty spaces there we can store the rainwater.
    // Compute the total water that can be trapped.
    // The water that will be trapped that will be on the basis of left and right side.
    //In order to find the water which is being trapped at a particular bar is the min of the length of the highest bar from Left Side and Right side. Subtracting it with the current bar height.
    // We can form a vector which will take the highest from the left and the highest from the right.

    // We can basically precompute both the left and the right side as per our need.
    vector<int> water = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<trappedWater(water)<<endl;
    return 0;
}