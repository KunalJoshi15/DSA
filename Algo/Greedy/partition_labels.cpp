class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> solution;
        int *arr = new int[26];
        // this will carry the last indices of the values;
        for(int i=0;i<s.length();i++){
            arr[s[i]-'a'] = i;
        }
        int i=0;
        while(i<s.length()){
            int end = arr[s[i]-'a'];
            int j=i;
            while(j!=end){
                end = max(end,arr[s[j++]-'a']);
            }
            solution.push_back(j-i+1);
            i=j+1;
        }
        return solution;
    }
};