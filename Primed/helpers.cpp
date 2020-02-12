#ifndef _HELPERS_
#define _HELPERS_

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <cstdlib>
using namespace std;

vector<int> suffixRank(vector<int> perm) {
// take a perm as input and outputs suffixRank vector
// Example: < 5 1 4 2 3 > output = < 5 1 3 1 1 >, e.g., rank of 4 in suffix <4 2 3> is 3 etc.
    vector<int> srank; 
    for (int j = 0; j < perm.size(); j++) {
       int max = perm[j]; int count = 1;
       for (int k = j+1; k < perm.size(); k++)
         if (abs(perm[j]) > abs(perm[k]))
             count++;
       srank.push_back(count);
       // cout << srank[j] << endl;
   }
  return srank;
}

int fact(int j) {
  // computes j!
  int out = 1;
  if ((j == 0) || (j == 1))
   return out;
  for (int k = 2; k <= j; k++)
    out *= k;
  return out;
}

pair<int, vector<bool>> permToInt( vector<int> perm) {
  // maps a given perm to its index in lexicographic order
  vector<int> srank = suffixRank(perm);
  int out = 0; int n = perm.size();
  for (int j = 0; j < n; j++)
    out += (srank[j]-1)*fact(n-j-1);
  vector<bool> bits;
  for (int i = 0; i < n; i++){
    if(perm[i] < 0)
      bits.push_back(true);
    else
      bits.push_back(false); 
  }
  pair<int, vector<bool>> result (out, bits);
  return result;
}

vector<int> update(vector<int> perm, int j) {
 // updates a vector by incrementing all entries that are >= j
 // e.g. update( < 5 1 2 4 3 >, 3) will return < 6 1 2 5 4 > 
 int n = perm.size(); vector<int> temp;
 for (int i = 0; i < n; i++)
   if (perm[i] < j)
     temp.push_back(perm[i]);
   else
     temp.push_back(perm[i]+1);
 return temp;
}

vector<int> decoder(int n, int m){
  vector<int> temp;
  if (m == 1) {
      vector<int> one{1};
      return one;
   };
  int fst = n / fact(m-1);
  temp = decoder(n - fst*fact(m-1), m-1);
  vector<int> temp1;
  temp1.push_back(fst+1);
  temp = update(temp, fst+1);
  for (int k = 0; k < temp.size(); k++)
   temp1.push_back(temp[k]);
  return temp1;
}

vector<int> intToPerm(pair<int, vector<bool>> n, int m) {
  vector<int> temp = decoder(n.first, m);
  for (int i = 0; i < temp.size(); i++){
    if(n.second[i])
      temp[i] *= -1;
  }
  return temp;
}

bool goalState(vector<int> perm){
    int temp = 0;
    for(int i = 0; i < perm.size(); i++){
        if(perm[i] < temp)
            return false;
        temp = perm[i];
    }
    return true;
}

vector<vector<int>> getNeighbors(vector<int> node, map<pair<int, vector<bool>>, pair<int, vector<bool>>> &parent){
    vector<vector<int>> neighbors;
    int size = 2;
    while(size <= node.size()){
        for(int i = 0; (i + size-1) < node.size(); i++){
            vector<int> temp(node);
            for(int j = 0, k = j + size-1; j <= k; j++, k--){
                swap(temp[i+j], temp[i+k]);
                temp[i+j] *= -1;
                if(j != k)
                  temp[i+k] *= -1;
            }
            if(permToInt(temp) != parent[permToInt(node)])
                neighbors.push_back(temp);
        }
        size++;
    }
    return neighbors;
}

#endif