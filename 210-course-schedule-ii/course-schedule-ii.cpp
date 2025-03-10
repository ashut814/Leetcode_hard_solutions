class Solution {
public:
    vector<int> topologicalSortCheck(unordered_map<int,vector<int>> &adj, int n, vector<int>& inDegree){
        queue<int>q;
        int count = 0;
        vector<int>results;
        for(int i = 0; i < n ; i++){
            if(inDegree[i] == 0){
                results.push_back(i);
                count++;
                q.push(i);
            }
        }

        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(int& v : adj[u]){
                inDegree[v]--;
                if(inDegree[v] == 0){
                    results.push_back(v);
                    count++;
                    q.push(v);
                }
            }
        }

        if(count != n) 
             return {};
        return results;     
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>>adj;
        vector<int> inDegree(numCourses,0);

        for(auto& vec : prerequisites){
            int a = vec[0];
            int b = vec[1];
            adj[b].push_back(a);
            inDegree[a]++;
        }

        return topologicalSortCheck(adj,numCourses,inDegree);
    }
};