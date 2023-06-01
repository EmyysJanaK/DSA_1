#include <iostream>
#include <limits>
using namespace std;

#define V 6

// Calculate the minimum time.
int minTime(int time[], bool sptSet[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++) {
        if (!sptSet[v] && time[v] <= min) {
            min = time[v];
            min_index = v;
        }
    }
    return min_index;
}

 // Print the city where the hospital should be built.
void printSolution(int time[]) {
    int t;
    cout << "Shortest time from the source city:\n";
    for (int i = 0; i < V; i++)
        cout << "City " << i << ": " << time[i] << endl;
}

// Dijkstra Algorithm.
void dijkstra(int graph[V][V], int src) {
    int time[V];
    bool sptSet[V];
    // Initialize time array and sptSet array
    for (int i = 0; i < V; i++) {
        time[i] = INT_MAX; // Set initial time to infinity.
        sptSet[i] = false; // Set all nodes as not visited.
    }
    time[src] = 0; // Set time of source city '0'.

    // Find the shortest time for all cities.
    for (int count = 0; count < V - 1; count++) {
        int u = minTime(time, sptSet); // Pick the city with the minimum time.
        sptSet[u] = true; // Mark the city as visited.

        // Update time value of the adjacent cities of the picked city.
        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && time[u] != INT_MAX && time[u] + graph[u][v] < time[v])
                time[v] = time[u] + graph[u][v];
        }
    }
    printSolution(time); // Print the shortest time from the source city.
}

int main() {
    int graph[V][V] = {{0, 10, 0, 0, 15, 5},
                       {10, 0, 10, 30, 0, 0},
                       {0, 10, 0, 12, 5, 0},
                       {0, 30, 12, 0, 0, 20},
                       {0, 0, 5, 0, 0, 0},
                       {5, 0, 0, 20, 0, 0}};
    for (int src = 0; src < V; src++) {
        cout << "Source City: " << src << endl;
        dijkstra(graph, src); // Run Dijkstra's algorithm for each source city.
        cout << endl;
    }
    return 0;
}
