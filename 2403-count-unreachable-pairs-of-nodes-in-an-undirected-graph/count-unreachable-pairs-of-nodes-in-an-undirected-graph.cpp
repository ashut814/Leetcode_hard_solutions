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

        if(rank[p_x] > rank[p_y]){
            parent[p_y] = p_x;
        } else if(rank[p_x] < rank[p_y]){
            parent[p_x] = p_y;
        } else{
            parent[p_x] = p_y;
            rank[p_y]++;
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank.resize(n,0);

        for(int i = 0 ; i < n ; i++){
            parent[i] = i;
        }

        for(auto &vec : edges){
            int u = vec[0];
            int v = vec[1];

            Union(u,v);
        }

        unordered_map<int,int>ump;
        for(int i = 0; i < n ; i++){
            int parent = find(i);
            ump[parent]++;
        }

        long long result = 0;
        long long remainingNodes = n;

        for(auto &it: ump){
            int size = it.second;
            result += (size) * (remainingNodes - size);
            remainingNodes -= size;
        }
        return result;
    }
};