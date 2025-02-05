/*
    Stock Charts - Maximum flow and path cover
    
*/

#include <cstddef>
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

    inline int get_flow(size_t id) const {
        return edges[id].flow;
    }
    inline int get_capacity(size_t id) const {
        return edges[id].capacity;
    }
   
};

vector<vector<int>> read_data(size_t num_stocks, size_t num_days) {
    vector<vector<int>> stock_prices(num_stocks, vector<int>(num_days));
    for (size_t i = 0; i < num_stocks; ++i) {
        for (size_t j = 0; j < num_days; ++j) {
            std::cin >> stock_prices[i][j];
        }
    }
    return stock_prices;
}

FlowGraph construct_graph(size_t num_stocks, size_t num_points) {
    vector<vector<int>> stock_prices = read_data(num_stocks, num_points);
    FlowGraph graph(num_stocks + num_points + 2, num_stocks * num_points + num_stocks + num_points); // Check this

    for(size_t i = 0; i < num_stocks; ++i) {
        graph.add_edge(0, i + 1, 1); 
    }
    for(size_t i = 0; i < num_points; ++i) {
        graph.add_edge(num_stocks + i + 1, num_stocks + num_points + 1, 1); 
    }
    
     /* Edges of verteces from left to right of bipartite graph */
  for (int i = 0; i < num_stocks; ++i)
  {
    int cur_stock = i;

    for (int j = 0; j < num_stocks; ++j)
    {
      if (j == cur_stock)
      {
        continue;
      }

      bool each_less{true};

      for (int k = 0; k < num_points; ++k)
      {
        if (stock_prices[i][k] >= stock_prices[j][k])
        {
          each_less = false;
          break;
        }
      }

      if (each_less)
      {
        graph.add_edge(i + 1, num_stocks + j + 1, 1);
      }
    }
    }
    /* Edges from vertices on the right of bipartite graph to the sink */
  for (int i = num_stocks + 1; i <= num_stocks * 2; ++i)
  {
    graph.add_edge(i, num_stocks * 2 + 1, 1);
  }

  return graph;

}

void BFS(const FlowGraph &graph, int s, int t, vector<int> &pred)
{
  queue<int> q;
  q.push(s);

  std::fill(pred.begin(), pred.end(), -1);

  while (!q.empty())
  {

    int cur = q.front();
    q.pop();

    for (auto id : graph.get_ids(cur))
    {

      const FlowGraph::Edge &e = graph.get_edge(id);

      if (pred[e.to] == -1 && e.capacity > e.flow && e.to != s)
      {
        pred[e.to] = id;
        q.push(e.to);
      }
    }
  }
}

void max_flow(FlowGraph &graph, int s, int t)
{
  int flow = 0;

  /* Contains predecessors of a vertex to get
   * the path and calculate minimum flow thereon. */
  vector<int> pred(graph.size());
  do
  {
    BFS(graph, s, t, pred);

    if (pred[t] != -1)
    {
