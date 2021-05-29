class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = INT_MIN;
        int i=0,j=height.size()-1;
        while(i<=j){
           int value = abs(i-j)*min(height[i],height[j]);
            if(max<value){
                max=value;
            }
            if(height[i]>height[j]){
                j--;
            }else{
                i++;
            }
        }
        return max;
    }
};