#include <iostream>
#include <set>
#include <unordered_map>

class Graph {
  bool isDirectredGraph;

public:
  std::unordered_map<int, std::set<int>> adjList;
  Graph(bool isDirectredGraph);

  void addEdge(int nodeA, int nodeB);
  void removeEdge(int nodeA, int nodeB);
  void printAllEdges();
  int numberOfNodes();
};
