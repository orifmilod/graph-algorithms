#include <iostream>
#include <set>
#include <unordered_map>

using namespace std;

class Graph {
  bool isDirectredGraph;

public:
  unordered_map<int, set<int>> adjList;
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
  for (auto &it : adjList) {
    cout << it.first << ": ";

    for (auto &node : adjList[it.first]) {
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

Graph::Graph(bool _isDirectredGraph) { isDirectredGraph = _isDirectredGraph; }
