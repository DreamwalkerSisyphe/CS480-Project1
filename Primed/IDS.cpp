#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
#include <map>
#include "helpers.cpp"

pair<int, vector<bool>> DFS(vector<int> start, int i, map<pair<int, vector<bool>>, bool> &visited, map<pair<int, vector<bool>>, pair<int, vector<bool>>> &parent){
    if(goalState(start)){
        return permToInt(start);
    }
    if(i <= 0){
        pair<int, vector<bool>> temp(-1, false);
        return temp;
    }
    pair<int, vector<bool>> parentIndex = permToInt(start);
    vector<vector<int>> neighbors = getNeighbors(start, parent);
    for(vector<int> n: neighbors){
        pair<int, vector<bool>> index = permToInt(n);
        /*if((index+1) > visited.size())
            visited.resize(index+1, false);
        if((index+1) > parent.size())
            parent.resize(index+1, -1);*/
        if(!visited[index]){
            visited[index] = true;
            parent[index] = parentIndex;
        }
        pair<int, vector<bool>> results = DFS(n, i-1, visited, parent);
        if(results.first != -1)
            return results;
    }
    pair<int, vector<bool>> temp(-1, false);
    return temp;
}

pair<int, vector<bool>> IDS(vector<int> start, map<pair<int, vector<bool>>, bool> &visited, map<pair<int, vector<bool>>, pair<int, vector<bool>>> &parent){
    //pair<int, vector<bool> index = permToInt(start);
    //visited.resize(index+1, false);
    //parent.resize(index+1, -1);
    if (goalState(start)){
	    return permToInt(start);
    }
    int i = 1;
    pair<int, vector<bool>> results = DFS(start, i, visited, parent);
    while (results.first == -1){
        i++;
        results = DFS(start, i, visited, parent);
    }
    return results;
}