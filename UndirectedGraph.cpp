#include <iostream>
#include <set>
#include <unordered_map>

using namespace std;

class UndirectedGraph {
  unordered_map<int, set<int>> adjList;

public:
  void addEdge(int nodeA, int nodeB);
  void printAllEdges();
};

void UndirectedGraph::addEdge(int nodeA, int nodeB){
  adjList[nodeA].insert(nodeB);
  adjList[nodeB].insert(nodeA);
}

void UndirectedGraph::printAllEdges() {
  for (int i = 0; i < adjList.size(); i++) {
    cout << i << ": ";
    for (auto &node : adjList[i]) {
      cout << node << ", ";
    }
    cout << "\n";
  }
}
