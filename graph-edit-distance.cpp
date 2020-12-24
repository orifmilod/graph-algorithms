#include "./UndirectedGraph.cpp"
#include <iostream>

using namespace std;

int main() {
  UndirectedGraph graph;

  graph.addEdge(0, 1);
  graph.addEdge(0, 4);

  graph.addEdge(1, 2);
  graph.addEdge(1, 3);
  graph.addEdge(1, 4);

  graph.addEdge(3, 4);
  graph.addEdge(2, 3);

  graph.printAllEdges();
  return 0;
}
