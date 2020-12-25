#include <iostream>
#include <set>
#include <unordered_map>

using namespace std;

class Graph {
  unordered_map<int, set<int>> adjList;
  bool isDirectredGraph;

public:
  Graph(bool isDirectredGraph);

  void addEdge(int nodeA, int nodeB);
  void removeEdge(int nodeA, int nodeB);
  void printAllEdges();
  int numberOfNodes();
};

int Graph::numberOfNodes() { return adjList.size(); }

void Graph::addEdge(int nodeA, int nodeB) {
  adjList[nodeA].insert(nodeB);
  if (!isDirectredGraph) {
    adjList[nodeB].insert(nodeA);
  }
}

void Graph::printAllEdges() {
  for (int i = 0; i < adjList.size(); i++) {
    cout << i << ": ";
    for (auto &node : adjList[i]) {
      cout << node << ", ";
    }
    cout << "\n";
  }
}

void Graph::removeEdge(int nodeA, int nodeB) {
  adjList[nodeA].erase(nodeB);
  if (!isDirectredGraph) {
    adjList[nodeB].erase(nodeA);
  }
}

void Graph::Graph(bool _isDirectredGraph) {
  isDirectredGraph = _isDirectredGraph;
}
