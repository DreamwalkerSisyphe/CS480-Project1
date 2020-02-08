#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include "helpers.cpp"

bool BFS(vector<int> permutation, int &max_size){
  if(goalState(permutation))
    return true;
  queue<vector<int>> Q;
  vector<bool> visited;
  vector<int> parent;
  fill(visited.begin(), visited.end(), false);
  fill(parent.begin(), parent.end(),-1);
  Q.push(perm);
  int index = permToInt(permutation);
  visited[index] = true;
  vector<int> current;
  while(!Q.empty()){
    current = Q.front();
    int curr_size = Q.size();
    max_size = max(max_size, curr_size);
    Q.pop();
    int parentIndex = permToInt(current);
    if(goalState(current))
      return true;
    vector<vector<int>> neighbors = getNeighbors(current, parent);
    for(vector<int> n: neighbors) {
      index = permToInt(n);
      if(!visited[index]){
        visited[index] = true;
        parent[index] = parentIndex;
        Q.push(n);
      }
    }
  }
}