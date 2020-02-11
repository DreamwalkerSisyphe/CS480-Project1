#include <iostream>
#include <vector>
#include <ctime>
#include "IDS.cpp"
#include "BFS.cpp"
#include "helpers.cpp"

int main()
{
    vector<int> perm;
    int num;
    cout << "Enter a permutation of < 1 2 ... n > for some n withspaces in between them." << endl;
    cout << " Once done enter a 0 to signal the end of array.\n"
         << "Enter input here: ";
    while(cin >> num && num != 0)
        perm.push_back(num);
    clock_t buildTime = clock();
    cout << "Performing BST:" << endl;
    vector<bool> visitedBST;
    vector<int> parentBST;
    int max_size = 0;
    int node = BFS(perm, max_size, visitedBST, parentBST);
    cout << "Number of Nodes Expanded: " << count(visitedBST.begin(), visitedBST.end(), true) << endl;
    vector<int> routeBST;
    while(node != -1){
        routeBST.insert(routeBST.begin(), node);
        node = parentBST[node];
    }
    cout << "Number of Moves to Sort: " << routeBST.size()-1 << endl;
    for(int n: routeBST){
        vector<int> temp = intToPerm(n, perm.size());
        for(int i: temp)
            cout << i << " ";
        cout << endl;
    }
    buildTime = clock() - buildTime;
    float time = (float) buildTime / CLOCKS_PER_SEC;
    cout << "Total CPU Time: " << time << " seconds." << endl;
    cout << "Max Size of Queue: " << max_size << endl;

    buildTime = clock();
    cout << "Performing IDS:" << endl;
    vector<bool> visitedIDS;
    vector<int> parentIDS;
    node = 0;
    IDS(perm, visitedIDS, parentIDS);
    cout << "Number of Nodes Expanded: " << count(visitedIDS.begin(), visitedIDS.end(), true) << endl;
    vector<int> routeIDS;
    while(node != -1){
        routeIDS.insert(routeIDS.begin(), node);
        node = parentIDS[node];
    }
    cout << "Number of Moves to Sort: " << routeIDS.size()-1 << endl;
    for(int n: routeIDS){
        vector<int> temp = intToPerm(n, perm.size());
        for(int i: temp)
            cout << i << " ";
        cout << endl;
    }
    buildTime = clock() - buildTime;
    time = (float) buildTime / CLOCKS_PER_SEC;
    cout << "Total CPU Time: " << time << " seconds." << endl;
    return 0;
}
