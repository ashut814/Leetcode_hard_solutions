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







---------------------  USING KAHN'S ALGO ---------------------------------------------------

    vector<int> topologicalSort(vector<vector<int>>& adj) {
        int V = adj.size();
        queue<int>q;
        vector<int> inDegree(V,0);
        
        // step 1: get the indegree
        for(int u = 0; u < V; u++){
            for(auto &v : adj[u]){
                inDegree[v]++;
            }
        }
        
        for(int i = 0 ; i < V; i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }
        
        
        vector<int>result;
        // write the bfs logic
        
        while(!q.empty()){
            int u = q.front();
            result.push_back(u);
            q.pop();
            
            for(int &v : adj[u]){ 
                inDegree[v]--;
                if(inDegree[v] == 0){
                    q.push(v);
                }
            }
        }
        return result;
        
    }
