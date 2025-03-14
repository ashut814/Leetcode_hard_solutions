vector<int>rank;
vector<int>parent;

int find(int x){
 if(x == parent[x]) return x;

 return parent[x] = find(parent[x]);
}

void union(int x, int y){
 int parent_x = parent[x];
 int parent_y = parent[y];

 if(rank[parent_x] > rank[parent_y]){
parent[y_parent] = x_parent;
} else if(rank[parent_y] < rank[parent_x]){
parent[x_parent] = y_parent;
} else{
parent[x_parent] = y_parent;
rank[y_parent]++;
}
}


int detectCycle(int V, vector<int>adj[]){
parent.size(V);
rank.resize(V,0);

for(int u = 0; u < V; u++){
for(int& v : adj[u]){
if(u < v){
if(find(u) == find(v){
return true;
} else{
union(u,v);
}
}
}
}
return false;
}

