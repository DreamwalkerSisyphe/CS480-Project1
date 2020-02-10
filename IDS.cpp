#include <vector>
#include <algorithm>
#include "helpers.cpp"

int DFS(vector<int> start, int i, vector<bool> &visited, vector<int> &parent){
    if(goalState(start))
	    return permToInt(start);
    if(i == 0)
        return -1;
    int parentIndex = permToInt(start);
    vector<vector<int>> neighbors = getNeighbors(start, parent);
    for(vector<int> n: neighbors){
        int index = permToInt(n);
        if((index+1) > visited.size())
            visited.resize(index+1, false);
        if((index+1) > parent.size())
            parent.resize(index+1, -1);
        if(!visited[index]){
            visited[index] = true;
            parent[index] = parentIndex;
        }
        return DFS(n, i-1, visited, parent);
    }
}

int IDS(vector<int> start, vector<bool> &visited, vector<int> &parent){
  if (goalState(start))
	return permToInt(start);
  int i = 1;
  while (DFS(start, i, visited, parent) == -1)
    i++;
}