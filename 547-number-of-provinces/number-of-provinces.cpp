class Solution {
public:
    void dfs(vector<vector<int>>& adj, int node, vector<bool>& visited) {
        visited[node] = true;
        for(int neighbor = 0; neighbor < adj.size(); neighbor++) {
            if(adj[node][neighbor] == 1 && !visited[neighbor]) {
                dfs(adj, neighbor, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<bool> visited(V, false);
        int count = 0;

        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                dfs(adj, i, visited);
                count++;  // Count new provinces
            }
        }
        return count;
    }
};
