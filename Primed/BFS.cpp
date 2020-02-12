#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <map>
#include "helpers.cpp"

pair<int, vector<bool>> BFS(vector<int> perm, int &max_size, map<pair<int, vector<bool>>, bool> &visited, map<pair<int, vector<bool>>, pair<int, vector<bool>>> &parent){
  pair<int, vector<bool>> index = permToInt(perm);
  //visited.resize(index+1, false);
  //parent.resize(index+1, -1);
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
    pair<int, vector<bool>> parentIndex = permToInt(current);
    if(goalState(current))
      return permToInt(current);
    vector<vector<int>> neighbors = getNeighbors(current, parent);
    for(vector<int> n: neighbors) {
      index = permToInt(n);
      /*if((index+1) > visited.size())
        visited.resize(index+1, false);
      if((index+1) > parent.size())
        parent.resize(index+1, -1);*/
      if(!visited[index]){
        visited[index] = true;
        parent[index] = parentIndex;
        Q.push(n);
      }
    }
  }
}