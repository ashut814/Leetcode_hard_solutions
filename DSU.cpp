int find(int element, vector<int>&parent){
  if(element == parent[element]){
    return element;
  }

  return find(parent[element],parent);
}


void union(int x, int y, vector<int>& parent){
  int x_parent = find(x,parent);
  int y_parent = find(y,parent);

  if(x_parent != y_parent){
    parent[x_parent] = y_parent;
  }
}
