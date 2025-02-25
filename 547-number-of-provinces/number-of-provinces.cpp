class Solution {
public:
    void bfs(unordered_map<int,vector<int>> &adj, int node, vector<bool>&visited){
        queue<int>q;
        q.push(node);
        visited[node] = true;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            // now visit the neighbour
            for(int &v : adj[front]){
                if(!visited[v]){
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<bool>visited(V,false);
        unordered_map<int,vector<int>>adj;
        for(int i =0 ; i < V; i++){
            for(int j = 0 ; j < V; j++){
                if(isConnected[i][j] == 1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int count = 0;
        for(int i = 0 ; i < V; i++){
            if(!visited[i]){
                bfs(adj,i,visited);
                count++;
            }
        }
        return count;
    }
};