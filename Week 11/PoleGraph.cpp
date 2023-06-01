#include <iostream>
#include <vector>
#include <climits>

using namespace std;

#define V 6

// Find the vertex with the minimum key value.
int minKey(vector<int>& key, vector<bool>& mstSet) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index; // Return the minimum key.
}

//  iterates through the vertices of the MST and output about each edge, source, destination, and weight of the edges in the Minimum Spanning Tree.
void printMST(vector<int>& parent, vector<vector<int>>& graph) {
    cout << "Minimum Spanning Tree:\n";
    for (int i = 1; i < V; i++)
        cout << "Node " << parent[i] << " - Node " << i << " : " << graph[i][parent[i]] << endl;
}

void primMST(vector<vector<int>>& graph) {
    vector<int> parent(V);      // Store the constructed MST
    vector<int> key(V, INT_MAX);     // Key values used to pick minimum weight edge
    vector<bool> mstSet(V, false); // To track vertices included in MST

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph);
}

int main() {
    vector<vector<int>> graph = {
            {0, 3, 0, 0, 0, 1},
            {3, 0, 2, 1, 0, 0},
            {0, 2, 0, 3, 0, 5},
            {0, 1, 3, 0, 5, 0},
            {0, 10, 0, 5, 0, 4},
            {1, 0, 5, 0, 4, 0}
    };

    primMST(graph); // prism Algorithm.

    return 0;
}
