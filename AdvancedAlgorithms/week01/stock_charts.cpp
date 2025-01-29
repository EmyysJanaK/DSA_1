/*
    Stock Charts - Maximum flow and path cover
    
*/

#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using std::numeric_limits;
using std::queue;
using std::size_t;
using std::vector;

class FlowGraph {
public:
    struct Edge {
        int from, to, capacity, flow;
    };

private:
    vector<Edge> edges; 
    vector<vector<size_t>> graph; 

public:
    explicit FlowGraph(size_t n, size_t m)
        : graph(n) {
        edges.reserve(m * 2);
    }

    inline void add_edge(int from, int to, int capacity) {
        Edge forward_edge = {from, to, capacity, 0};
        Edge backward_edge = {to, from, 0, 0};
        graph[from].push_back(edges.size());
        edges.push_back(forward_edge);
        graph[to].push_back(edges.size());
        edges.push_back(backward_edge);
    }

    inline size_t size() const {
        return graph.size();
    }

    inline const vector<size_t>& get_ids(int from) const {
        return graph[from];
    }

    inline const Edge& get_edge(size_t id) const {
        return edges[id];
    }

    inline void add_flow(size_t id, int flow) {
        edges[id].flow += flow;
        edges[id ^ 1].flow -= flow; // id ^ 1 gives the backward edge
    }

    
};