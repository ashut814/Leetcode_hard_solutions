class Solution {
public:
    vector<int> rank;
    vector<int> parent;

    int find(int x){
        if(x == parent[x]){
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y){
        int p_x = find(x);
        int p_y = find(y);

        if(p_x != p_y){
            if(rank[p_x] > rank[p_y]){
                parent[p_y] = p_x;
            } else if(rank[p_x] < rank[p_y]){
                parent[p_x] = p_y;
            } else {
                parent[p_x] = p_y;
                rank[p_y]++;
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        rank.resize(n,0);
        parent.resize(n);

        if(connections.size() < n-1) return -1;

        for(int i = 0 ; i < n; i++){
            parent[i] = i;
        }

        int components = n;

        for(auto &vec : connections){
            if(find(vec[0]) != find(vec[1])){
                components--;
                Union(vec[0],vec[1]);
            }
        }
        return components-1;
    }
};