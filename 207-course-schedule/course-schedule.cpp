class Solution {
public:
    bool checkTopologicalSort(unordered_map<int,vector<int>>adj, int n, vector<int>& inDegree){
        queue<int>q;
        int count = 0;
        for(int i = 0 ; i < n; i++){
            if(inDegree[i] == 0){
                q.push(i);
                count++;
            }
        }

        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(auto &v : adj[u]){
                inDegree[v]--;
                if(inDegree[v] == 0) {
                    q.push(v);
                    count++;
                }
            }
        }

        if(count == n) 
            return true;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>>adj;
        vector<int> inDegree(numCourses,0);
        for(auto &vec : prerequisites){
            int a = vec[0];
            int b = vec[1];
            // b ---> a
            adj[b].push_back(a);
            inDegree[a]++;
        }

        return checkTopologicalSort(adj,numCourses,inDegree);
    }
};