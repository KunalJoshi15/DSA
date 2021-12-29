class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        vector<int> ans;
        deque<int> dq;
        
        for(int i=0;i<k;i++){
            while(!dq.empty() and arr[dq.back()]<=arr[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        
        for(int i=k;i<arr.size();i++){
            ans.push_back(arr[dq.front()]);
            while(!dq.empty() and dq.front()<=i-k){
                dq.pop_front();
            }
            while(!dq.empty() and arr[dq.back()]<=arr[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        ans.push_back(arr[dq.front()]);
        return ans;
    }
};