#include <vector>
#include <iostream>
#include <algorithm>
#include "helpers.cpp"

bool DFS(vector<int> start, int i, vector<bool> &visited, vector<int> &parent){
    if(goalState(start)){
        return true;
    }
    if(i <= 0){
        return false;
    }
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
        if(DFS(n, i-1, visited, parent))
            return true;
    }
    return false;
}

bool IDS(vector<int> start, vector<bool> &visited, vector<int> &parent){
    int index = permToInt(start);
    visited.resize(index+1, false);
    parent.resize(index+1, -1);
    if (goalState(start)){
	    return true;
    }
    int i = 1;
    while (!DFS(start, i, visited, parent)){
        i++;
    }
    return true;
}