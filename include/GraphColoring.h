#pragma once

#include "Graph.h"
#include <unordered_map>
#include <vector>

class GraphColoring {

  void backtrack(Graph &graph, std::unordered_map<int, int> &currentlyColored,
                 int currentNode);

public:
  std::unordered_map<int, int> color(Graph graph);

  std::unordered_map<int, std::set<int>> kPartite(Graph &graph);

  int getAvailableColor(std::unordered_map<int, int> &currentlyColored,
                        Graph &graph, int &currentNode);

  int minColor(Graph &graph);
};
