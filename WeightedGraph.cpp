#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_map>

using namespace std;

// This is a non-negative weighted directed graph
class Graph {
  bool isDirectredGraph;

public:
  unordered_map<int, set<pair<int, uint>>> adjList;
  Graph(bool isDirectredGraph);

  void addEdge(int sourceNode, int destinatioNode, uint weight,
               bool connectBack);
  void removeEdge(int sourceNode, int destinationNode, bool viceVersa);
  void printAllEdges();
  int numberOfNodes();
};

int Graph::numberOfNodes() { return adjList.size(); }

void Graph::addEdge(int nodeA, int nodeB, uint weight, bool viceVersa = false) {
  adjList[nodeA].insert(make_pair(nodeB, weight));

  if (viceVersa) {
    adjList[nodeB].insert(make_pair(nodeA, weight));
  }
}

void Graph::printAllEdges() {
  for (auto &it : adjList) {
    cout << it.first << ": ";

    for (auto &node : adjList[it.first]) {
      cout << node.first << ", with wight of: " << node.second;
    }
    cout << "\n";
  }
}

void Graph::removeEdge(int sourceNode, int destinationNode, bool viceVersa) {
  auto it = find_if(adjList[sourceNode].begin(), adjList[sourceNode].end(),
                    [destinationNode](pair<int, uint> const &vertex) {
                      return vertex.first == destinationNode;
                    });

  if (it != adjList[sourceNode].end()) {
    adjList[sourceNode].erase(it);
  }

  if (viceVersa) {
    auto it = find_if(adjList[destinationNode].begin(),
                      adjList[destinationNode].end(),
                      [sourceNode](pair<int, uint> const &vertex) {
                        return vertex.first == sourceNode;
                      });

    adjList[destinationNode].erase(it);
  }
}

Graph::Graph(bool _isDirectredGraph) { isDirectredGraph = _isDirectredGraph; }
