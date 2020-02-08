#include <vector>
#include <algorithm>
#include "helpers.cpp"

vector<bool> visited;
vector<int> parent;


bool DFS(vector<int> start, int i){
    if goalState(start)
	    return true;
    if(i == 0)
    return false;
    vector<vector<int>> neighbors = getNeighbors(start, parent);
    for(vector<int> n: neighbors){
        index = permToInt(n);
        if(!visited[index]){
            visited[index] = true;
            parent[index] = parentIndex;
        }
        DFS(n, i-1);
    }
}

IDS(start){
  if goalState(start)
	   return true;
  int i = 1;
  while !(DFS(start,i))
    i++;
}