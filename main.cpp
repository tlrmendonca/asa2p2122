#include <iostream>
#include <string.h>
#include <sstream>
#include <vector>
using namespace std;

int main(int argc, char *argv[])
{
    // General problem information
    int V, E, v1, v2;

    // Data input
    if (scanf("%d %d\n%d %d", &v1, &v2, &V, &E) != 4)
        cout << "Debug: scanf failed" << endl;

    // Debug
    // cout << v1 << " "  << v2 << "\n"  << V << " " << E << endl;

    // Graph structure
    // Vector or vectors (vertices that have a "list" of edges)
    // Rule : input as v-1 and output as v+1
    vector<vector<int>> G(V);

    int v, u;
    while (scanf("%d %d", &v, &u) == 2) {
        //Rule
        v = v-1;
        u = u-1;
        cout << v << " " << u << endl;
        G[v].push_back(u);
    }

    cout << "Size 0: "<< G[0].size() << endl;
    cout << "Size 1: "<< G[1].size() << endl;
    for (int i = 0; i < 2; i++)
        cout << G[0][i] << endl;
    cout << G[0][1] << endl;
    

    // Debug
    // for (int i = 0; i < V; i++)
    // {
    //     cout <<"Vertice: " << i << "Size: " <<G[v].size() << endl;
    //     for (int j = 0; j < (int)G[v].size(); j++)
    //     {
    //         cout << i + 1 << "->" << j + 1 << endl;
    //     }
    // }

    return 0;
}