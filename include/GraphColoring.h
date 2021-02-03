#include "Graph.h"
#include <unordered_map>
#include <vector>

class GraphColoring {
  int getAvailableColor(std::unordered_map<int, int> &currentlyColored,
                        Graph &graph, int &currentNode);

  void backtrack(Graph &graph, std::unordered_map<int, int> &currentlyColored,
                 int currentNode);

public:
  std::unordered_map<int, int> color(Graph graph);

  std::unordered_map<int, std::set<int>> kPartite(Graph &graph);

  int minColor(Graph &graph);
};
