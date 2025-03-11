class Solution {
public:

    bool bfs(vector<vector<int>>& graph,int curr, vector<int>& color, int currColor){
        color[curr] = currColor;
        queue<int>q;
        q.push(curr);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (auto& v : graph[u]) {
                if (color[v] == color[u]) {
                    return false;
                } 
                if (color[v] == -1) { 
                    color[v] = 1 - color[u];
                    q.push(v);
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int>color(v,-1);
        for(int i = 0 ; i < v ; i++){
            if(color[i] == -1){
                if(bfs(graph,i,color,1) == false) return false;
            }
        }
        return true;
    }
};