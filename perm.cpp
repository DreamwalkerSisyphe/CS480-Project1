#include<iostream>
#include <list>

using namespace std;

struct node
{
  node* left;
  node* right;
  int height;
  struct node *next
};

bool sorted(vector<int> perm) 
{
  for (int i = 0; i < perm.size(); i++)
  {
    if (perm (i - 1) > perm[i])
    {
      return false;
    }
  }
  return true;
}
    
