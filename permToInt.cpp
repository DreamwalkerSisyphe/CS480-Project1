
#include <iostream>
#include <vector>
using namespace std;

vector<int> suffixRank(vector<int> perm) {
// take a perm as input and outputs suffixRank vector
// Example: < 5 1 4 2 3 > output = < 5 1 3 1 1 >, e.g., rank of 4 in suffix <4 2 3> is 3 etc.
    vector<int> srank; 
    for (int j = 0; j < perm.size(); j++) {
       int max = perm[j]; int count = 1;
       for (int k = j+1; k < perm.size(); k++)
         if (perm[j] > perm[k])
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

int permToInt( vector<int> perm) {
  // maps a given perm to its index in lexicographic order
   vector<int> srank = suffixRank(perm);
   int out = 0; int n = perm.size();
   for (int j = 0; j < n; j++)
     out += (srank[j]-1)*fact(n-j-1);
   return out;
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

vector<int> intToPerm(int n, int m) {
  // inverse of permToInt function. This function takes the lexical index n as well as the size of the permutation m
  vector<int> temp;
  if (m == 1) {
      vector<int> one{1};
      return one;
   };
  int fst = n / fact(m-1);
  temp = intToPerm(n - fst*fact(m-1), m-1);
  vector<int> temp1;
  temp1.push_back(fst+1);
  temp = update(temp, fst+1);
  for (int k = 0; k < temp.size(); k++)
   temp1.push_back(temp[k]);
  return temp1;
}

int main() {
   vector<int> perm;
    int num;
    cout << "Testing permToInt function " << endl;
    cout << "Enter a permutation of < 1 2 ... n > for some n withspaces in between them." << endl;
    cout << " Once done enter a 0 to signal the end of array.\n"
         << "Enter input here: ";
    while(cin >> num && num != 0)
        perm.push_back(num);
  int out = permToInt(perm);
  cout << "The  permutation maps to integer  " << out << endl;
  cout << "--------------------------------------------------------" << endl;
  cout << "Testing intToPerm function " << endl;
  cout << "Enter a positive integer, the lexical rank of the permutation " << endl;
  int temp; cin >> temp;
  cout << "Enter the size of the permutation " << endl;
  int m; cin >> m;
  cout << "The permutation map of " << temp << " is : " << endl;
  vector<int> temp1 = intToPerm(temp, m);
  int siz = temp1.size(); cout <<  "< " ;
  for (int j = 0; j < siz-1; j++)
     cout << temp1[j] << "," ;
  cout << temp1[siz-1] << " > " << endl;
  return 0;
}




  
