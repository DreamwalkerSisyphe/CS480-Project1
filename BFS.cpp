#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include "helpers.cpp"

int BFS(vector<int> perm, int &max_size, vector<bool> &visited, vector<int> &parent){
  int index = permToInt(perm);
  visited.resize(index+1, false);
  parent.resize(index+1, -1);
  if(goalState(perm))
    return permToInt(perm);
  queue<vector<int>> Q;
  Q.push(perm);
  visited[index] = true;
  vector<int> current;
  while(!Q.empty()){
    current = Q.front();
    int curr_size = Q.size();
    max_size = max(max_size, curr_size);
    Q.pop();
    int parentIndex = permToInt(current);
    if(goalState(current))
      return permToInt(current);
    vector<vector<int>> neighbors = getNeighbors(current, parent);
    for(vector<int> n: neighbors) {
      index = permToInt(n);
      if((index+1) > visited.size())
        visited.resize(index+1, false);
      if((index+1) > parent.size())
        parent.resize(index+1, -1);
      if(!visited[index]){
        visited[index] = true;
        parent[index] = parentIndex;
        Q.push(n);
      }
    }
  }
}