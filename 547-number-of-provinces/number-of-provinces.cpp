class Solution {
public:
    void dfs(unordered_map<int,vector<int>> &adj, int node, vector<bool>&visited){
        visited[node] = true;
        for(int &neighbour : adj[node]){
            if(!visited[neighbour]) {
                dfs(adj,neighbour,visited);
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
                dfs(adj,i,visited);
                count++;
            }
        }
        return count;
    }
};