#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using std::numeric_limits;
using std::queue;
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

public:
  explicit FlowGraph(size_t n, size_t m)
      : graph(n)
  {
    edges.reserve(m * 2);
  }
};