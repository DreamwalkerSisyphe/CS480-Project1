#include <iostream>
#include <vector>
#include <ctime>
#include <utility>
#include <map>
#include "IDS.cpp"
#include "BFS.cpp"
#include "helpers.cpp"

struct Compare {
    bool visit;
    Compare(const bool &visit) : visit(visit) {}
};
bool operator==(const std::pair<pair<int, vector<bool>>, bool>&p, const Compare& c) {
    return c.visit == p.second;
}
bool operator==(const Compare& c, const std::pair<pair<int, vector<bool>>, bool>&p) {
    return c.visit == p.second;
}

int main()
{
    vector<int> perm;
    int num;
    cout << "Enter a permutation of < 1 2 ... n > for some n withspaces in between them.\n Enter Primed orientation values as negative numbers." << endl;
    cout << " Once done enter a 0 to signal the end of array.\n"
         << "Enter input here: ";
    while(cin >> num && num != 0)
        perm.push_back(num);
    clock_t buildTime = clock();
    cout << "Performing BST:" << endl;
    map<pair<int, vector<bool>>, bool> visitedBST;
    map<pair<int, vector<bool>>, pair<int, vector<bool>>> parentBST;
    int max_size = 0;
    pair<int, vector<bool>> nodeBST = BFS(perm, max_size, visitedBST, parentBST);
    cout << "Number of Nodes Expanded: " << count(visitedBST.begin(), visitedBST.end(), Compare(true)) << endl;
    vector<pair<int, vector<bool>>> routeBST;
    while(parentBST.find(nodeBST) != parentBST.end()){
        routeBST.insert(routeBST.begin(), nodeBST);
        nodeBST = parentBST[nodeBST];
    }
    cout << "Number of Moves to Sort: " << routeBST.size()-1 << endl;
    for(pair<int, vector<bool>> n: routeBST){
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
    map<pair<int, vector<bool>>, bool> visitedIDS;
    map<pair<int, vector<bool>>, pair<int, vector<bool>>> parentIDS;
    pair<int, vector<bool>> nodeIDS = IDS(perm, visitedIDS, parentIDS);
    cout << "Number of Nodes Expanded: " << count(visitedIDS.begin(), visitedIDS.end(), Compare(true)) << endl;
    vector<pair<int, vector<bool>>> routeIDS;
    while(parentIDS.find(nodeIDS) != parentIDS.end()){
        routeIDS.insert(routeIDS.begin(), nodeIDS);
        nodeIDS = parentIDS[nodeIDS];
    }
    cout << "Number of Moves to Sort: " << routeIDS.size()-1 << endl;
    for(pair<int, vector<bool>> n: routeIDS){
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
