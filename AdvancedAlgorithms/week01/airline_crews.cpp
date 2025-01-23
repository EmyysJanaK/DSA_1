#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <stdio.h>

using std::numeric_limits;
using std::queue;
using std::size_t;
using std::vector;

/* This class implements a bit unusual scheme for storing edges of the graph,
 * in order to retrieve the backward edge for a given edge quickly. */
class FlowGraph
{
public:
  struct Edge
  {
    int from, to, capacity, flow;
  };

private:
  /* List of all - forward and backward - edges */
  vector<Edge> edges;

  /* These adjacency lists store only indices of edges in the edges list */
  vector<vector<size_t>> graph;

  const size_t flights;

public:
  explicit FlowGraph(size_t n, size_t m, size_t f)
      : graph(n), flights(f)
  {
    edges.reserve(m * 2);
  }
  inline void add_edge(int from, int to, int capacity)
  {
    /* Note that we first append a forward edge and then a backward edge,
         * so all forward edges are stored at even indices (starting from 0),
         * whereas backward edges are stored at odd indices in the list edges */
    Edge forward_edge = {from, to, capacity, 0};
    Edge backward_edge = {to, from, 0, 0};
    graph[from].push_back(edges.size());
    edges.push_back(forward_edge);
    graph[to].push_back(edges.size());
    edges.push_back(backward_edge);
  }

  inline size_t size() const
  {
    return graph.size();
  }
};