class Solution {
public:
    vector<vector<int>> result;
    
    void DFS(string &beginWord,string &endWord,unordered_map<string,unordered_set<string>> &adj,vector<string> &path){
        path.push_back(beginWord);
        if(beginWord==endWord){
            ans.push_back(path);
            path.pop_back();
        }
        
        for(auto x:adj[beginWord]){
            DFS(x,endWord,adj,path);
        }
        path.pop_back();
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,unordered_set<string>> adj;
        unordered_set<string> dict(wordList.begin(),wordList.end());
        queue<string> q;
        q.push(beginWord);
        unordered_map<string,int> visited;
        while(q.empty()){
            string curr = q.front();
            q.pop();
            string temp = curr;
            for(int i=0;i<curr.size();i++){
                for(char ch='a';ch<='z';ch++){
                    if(temp[i]==ch) continue;
                    temp[i] = ch;
                    if(dict.count(temp)>0){
                        if(visited.count(temp)==0){
                            visited[temp] = 1+visited[curr];
                            q.push(temp);
                            adj[curr].insert(temp);
                        }
                        else if(visited[temp]==1+visited[curr]){
                            adj[curr].insert(temp);
                        }
                    }
                }
                temp[i] = curr[i];
            }
        }
        vector<string> path;
        DFS(beginWord,endWord,adj,path);
        return ans;
    }
};