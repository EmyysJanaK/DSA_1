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
};