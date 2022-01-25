#include <iostream>
#include <string.h>
#include <sstream>
#include <vector>
using namespace std;

bool hasCycle(vector<vector<int>> G, int v, bool visited[], bool stack[])
{
    if (visited[v] == false)
    {
        // Mark as visited and add to stack
        visited[v] = true;
        stack[v] = true;

        // Edges
        // Edge v->u, accessed as G[v][i] returns u
        int num = (int)G[v].size();
        for (int i = 0; i < num; i++)
        {
            // Not visited => Recursive call
            if (!visited[G[v][i]] && hasCycle(G, G[v][i], visited, stack))
                // hasCycle returned true
                return true;
            else if (stack[G[v][i]])
                // Was in stack
                return true;
        }
    }
    // Remove from stack
    stack[v] = false;
    return false;
}

bool isFamilyTree(vector<vector<int>> G, int V, int E)
{
    // Initialize Single Source
    bool visited[V], stack[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
        stack[i] = false;
    }

    // Apply DFS to check for loops
    for (int i = 0; i < V; i++)
        if (hasCycle(G, i, visited, stack))
            return false;
    
    // Reaches here if there no loops are detected
    return true;
}

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
    int ctr[V] = {0};
    while (scanf("%d %d", &v, &u) == 2)
    {
        // Rule
        v = v - 1;
        u = u - 1;

        ctr[u] += 1;
        G[v].push_back(u);
    }

    // Debug
    // for (int i = 0; i < V; i++)
    // {
    //     cout << i + 1 << ":";
    //     for (int j = 0; j < (int)G[i].size(); j++)
    //     {
    //         cout << " ->" << G[i][j] + 1;
    //     }
    //     cout << endl;
    // }

    // ?? 
    // ?? Is this a valid family tree ?
    // ??

    // Condition 1: A node can't have more than two "parents",
    // meaning no node can be the destination of more than 2 edges
    for (int i = 0; i < V; i++)
        if (ctr[i] > 2)
        {
            // !
            cout << 0 << endl;
            return 0;
        }

    // Condition 2: No cycles
    if (!isFamilyTree(G, V, E))
    {
        // !
        cout << 0 << endl;
        return 0;
    }

    // Debug
    // cout << "Was a family tree!" << endl;

    // ?
    // ? LCA - Lowest Common Ancestor
    // ?

    LCA(V, E, G, v1, v2);

    return 0;
}