    void dfs(vector<vector<int>>& adj, int node, vector<bool>&visited, stack<int>&s){
        visited[node] = true;
        for(int &neighbour : adj[node]){
            if(!visited[neighbour]) {
                dfs(adj,neighbour,visited,s);
            }
        }
        s.push(node);
    }
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        // Your code here
        int V = adj.size();
        stack<int>s;
        vector<bool>visited(V,false);
        
        for(int i = 0 ; i < V; i++){
            if(!visited[i]){
                dfs(adj,i,visited,s);
            }
        }
        
        vector<int>ans;
        
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
