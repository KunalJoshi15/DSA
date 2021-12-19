class Solution {
private:
    unordered_map<Node*, Node*> visited;
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL)
            return node;
        if(visited[node])
            return visited[node];
        // current node is created here. that we will be storing in the visited array.
        Node* cloned = new Node(node->val);
        visited[node] = cloned;
        
        for(auto nei: node->neighbors){
            cloned->neighbors.push_back(cloneGraph(nei));
        }
        return cloned;      
    }
};

class Solution1{
public:
    Node *cloneGraph(Node *node){
        if(node==NULL) return node;
        unordered_map<Node*,Node*> visited;
        queue<*Node> q;
        q.push(node);
        visited[node] = new Node(node->val);
        while(q.empty()==false){
            Node *f = q.front()
            q.pop();

            for(auto nbrs:f->neighbors){
                if(!visited[node]){
                    visited[nbrs] = new Node(nbrs->val);
                    q.push(nbrs);
                }
                // here we are pushing the neighbours into the new node in which the clone is being performed.
                visited[f]->neighbors.push_back(visited[nbrs]);
            }
        }
        return visited[node];
    }
};