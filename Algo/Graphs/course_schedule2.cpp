class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adj[numCourses];
        
        for(int i=0;i<prerequisites.size();i++) 
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int> indegree(numCourses,0);
        
        for(int i=0;i<numCourses;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        vector<int> topo;
        
        while(q.empty()==false){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            
            for(auto child:adj[node]){
                indegree[child]--;
                if(indegree[child]==0){
                    q.push(child);
                }
            }
        }
        if(topo.size()==numCourses){
            return topo;
        }
        return {};
    }
};