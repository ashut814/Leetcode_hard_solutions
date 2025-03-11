class Solution {
public:
    bool dfs(vector<vector<int>>& adj, int curr, vector<int>& color, int currColor) {
        color[curr] = currColor; // Color the current node

        // Check adjacent nodes
        for (int& v : adj[curr]) {
            if (color[v] == color[curr]) { // If adjacent node has same color, not bipartite
                return false;
            }

            if (color[v] == -1) { // If not colored, assign opposite color and DFS
                int colorOfV = 1 - currColor;
                if (!dfs(adj, v, color, colorOfV)) {
                    return false;
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int> color(v, -1); // Initialize all nodes as uncolored

        for (int i = 0; i < v; i++) {
            if (color[i] == -1) { // If the node is not colored
                if (!dfs(graph, i, color, 1)) { // Start DFS with color 1
                    return false;
                }
            }
        }
        return true;
    }
};
