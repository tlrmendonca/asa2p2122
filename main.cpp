#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool hasCycle(vector<vector<int>> &G, int v, vector<bool> &visited, vector<bool> &stack)
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

bool isFamilyTree(vector<vector<int>> &G, int V, int E)
{
    // Initialize Single Source
    vector<bool> visited(V);
    vector<bool> stack(V);
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

void LCA(vector<vector<int>> &G, vector<vector<int>> &invertedGraph, int V, int E, int v1, int v2)
{
    // Yellow Paint
    vector<bool> yellow;
    for (int i = 0; i < V; i++)
        yellow.push_back(false);

    // DFS starting at v1
    // will give us every ancestor of v1
    queue<int> yellowQ;
    yellowQ.push(v1);
    while (!yellowQ.empty())
    {
        // Take first and remove it
        int current = yellowQ.front();
        yellowQ.pop();

        // Paint current
        yellow[current] = true;

        // Add parents to queue
        for (int i = 0; i < (int)invertedGraph[current].size(); i++)
            yellowQ.push(invertedGraph[current][i]);
    }

    // Blue paint -> blue + yellow = green
    vector<bool> green;
    for (int i = 0; i < V; i++)
        green.push_back(false);

    // DFS starting at v2
    // will give us every ancestor of v2
    queue<int> blueQ;
    blueQ.push(v2);
    while (!blueQ.empty())
    {
        // Take first and remove it
        int current = blueQ.front();
        blueQ.pop();

        // Paint current if yellow was painted
        if (yellow[current])
            green[current] = true;

        // Add parents to queue
        for (int i = 0; i < (int)invertedGraph[current].size(); i++)
            blueQ.push(invertedGraph[current][i]);
    }

    // If Green => Common Ancestor
    // If a Green node doesn't have Green descendants, then its the lowest possible
    bool empty = true;
    bool isLeaf = true;
    for (int i = 0; i < V; i++)
    {
        if (green[i])
        {
            // Assume its the LCA.
            // If any of its edges (direct successors) is green, then it can't be a LCA 
            isLeaf = true;
            for (int j = 0; j < (int)G[i].size(); j++)
            {
                if (green[G[i][j]])
                    isLeaf = false;
            }
            if (isLeaf)
            {
                // !
                cout << i + 1 << " ";
                empty = false;
            }
        }
    }
    if (empty)
        // !
        cout << "-";
    // !
    cout << endl;
}

int main(int argc, char *argv[])
{
    // General problem information
    int V, E, v1, v2;

    // Data input
    if (scanf("%d %d\n%d %d", &v1, &v2, &V, &E) != 4)
        cout << "Debug: scanf failed" << endl;

    // Rule (explained in Graph Structure)
    v1 = v1 - 1;
    v2 = v2 - 1;

    // Graph structure
    // Vector or vectors (vertices that have a "list" of edges)
    // Rule : input as v-1 and output as v+1
    vector<vector<int>> G(V);
    // Inverted Graph will be useful later
    vector<vector<int>> invG(V);

    int v, u;
    vector<int> ctr;
    for (int i = 0; i < V; i++)
        ctr.push_back(0);

    while (scanf("%d %d", &v, &u) == 2)
    {
        // Rule
        v = v - 1;
        u = u - 1;

        ctr[u] += 1;
        G[v].push_back(u);
        invG[u].push_back(v);
    }

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

    // ?
    // ? LCA - Lowest Common Ancestor
    // ?

    LCA(G, invG, V, E, v1, v2);

    return 0;
}