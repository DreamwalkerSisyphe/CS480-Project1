#include<iostream>
#include <list>

using namespace std;
//needa change still
bool TheSwapped::BFS (std::vector<int> permutation, int &max_size);
  if(the_goal(permutation))
    return true;
    queue<vector<int>> Q;
    std::fill(visited.begin(), visited.end(),0);
    std::fill(parent.begin(), parent.end(),-1);
    Q.push(perm);
    int index = permutationtoint(permutation);
    visited[index] = true;
    std::vector<int> current;
      while(!Q.empty()){
          current = Q.front();
          int curr_size = Q.size();
          max_size = std::max(max_size, curr_size);

          Q.pop();
          int parentIndex = permutationtoint(current);
          if(the_goal(current))
          return true;
          std::vector< std:: vector<int> > neighbors = get_neighbors(current);)
          for(std::std::vector<int> n: neighbors) {
              index = permutationtoint(n);
              if(!visited[index]){
                visited[index] = true;
                parent[index] = parentIndex;
                Q.push(n);
              }

          }
      }


// Driver program to test methods of graph class
int main()
{


    return 0;

