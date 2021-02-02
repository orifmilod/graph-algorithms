#include "Graph.h"
#include <iostream>
#include <set>
#include <unordered_map>

int Graph::numberOfNodes() { return adjList.size(); }

void Graph::addEdge(int nodeA, int nodeB) {
  adjList[nodeA].insert(nodeB);
  if (!isDirectredGraph) {
    adjList[nodeB].insert(nodeA);
  }
}

void Graph::printAllEdges() {
  for (auto &it : adjList) {
    std::cout << it.first << ": ";

    for (auto &node : adjList[it.first]) {
      std::cout << node << ", ";
    }
    std::cout << "\n";
  }
}

void Graph::removeEdge(int nodeA, int nodeB) {
  adjList[nodeA].erase(nodeB);
  if (!isDirectredGraph) {
    adjList[nodeB].erase(nodeA);
  }
}

Graph::Graph(bool _isDirectredGraph) { isDirectredGraph = _isDirectredGraph; }
