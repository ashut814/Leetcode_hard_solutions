class Solution
{
    public:
    vector<int>rank;
    vector<int> parent;
    int find(int x){
        if(x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }
    
    void Union(int x, int y){
        int x_parent = find(x);
        int y_parent = find(y);
        
        if(x_parent > y_parent){
            parent[y_parent] = x_parent;
        } else if(x_parent < y_parent){
            parent[x_parent] = y_parent;
        } else{
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }
    int detectCycle(int V, vector<int> adj[]) {
        rank.resize(V, 0);
        parent.resize(V);

        for (int i = 0; i < V; i++) {
            parent[i] = i;
        }

        for (int u = 0; u < V; u++) {
            for (int& v : adj[u]) {
                if (u < v) {
                    if (find(u) == find(v)) {
                        return true;
                    } else {
                        Union(u, v);
                    }
                }
            }
        }
        return false; 
    }
};
