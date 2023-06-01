#include <iostream>
#include <vector>
#include <queue>
#include <climits>

#define INF INT_MAX

using namespace std;

// Structure to represent a node in the graph
struct Node {
    int id;
    int time;

    Node(int id, int time) : id(id), time(time) {}
};

// Custom comparison function for the priority queue
struct CompareNodes {
    bool operator()(const Node& n1, const Node& n2) {
        return n1.time > n2.time;
    }
};

// Dijkstra's algorithm implementation
vector<int> dijkstra(vector<vector<int>>& graph, int start) {
    int n = graph.size();
    vector<int> times(n, INF);  // Initialize times with infinity
    vector<bool> visited(n, false);

    times[start] = 0;
    priority_queue<Node, vector<Node>, CompareNodes> pq;
    pq.push(Node(start, 0));

    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();
        int u = current.id;

        if (visited[u]) continue;
        visited[u] = true;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] != 0 && times[u] + graph[u][v] < times[v]) {
                times[v] = times[u] + graph[u][v];
                pq.push(Node(v, times[v]));
            }
        }
    }

    return times;
}

int main() {
    vector<vector<int>> graph = {
            {0, 10, 0, 0, 15, 5},
            {10, 0, 10, 30, 0, 0},
            {0, 10, 0, 12, 5, 0},
            {0, 30, 12, 0, 0, 20},
            {0, 0, 5, 0, 0, 0},
            {5, 0, 0, 20, 0, 0}
    };

    int numCities = graph.size();
    int minTime = INF;
    int hospitalCity = -1;

    // Find the city with the shortest total time to all other cities
    for (int i = 0; i < numCities; i++) {
        vector<int> times = dijkstra(graph, i);
        int totalTime = 0;

        for (int j = 0; j < numCities; j++) {
            if (j != i) {
                totalTime += times[j];
            }
        }

        double averageTime = static_cast<double>(totalTime) / (numCities - 1);
        cout << "Average time from city " << i << " to all other cities: " << averageTime << endl;

        if (averageTime < minTime) {
            minTime = averageTime;
            hospitalCity = i;
        }
    }

    cout << "The hospital should be built in city " << hospitalCity << endl;

    return 0;
}
