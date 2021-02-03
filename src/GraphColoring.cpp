#include "../include/GraphColoring.h"
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int GraphColoring::getAvailableColor(unordered_map<int, int> &currentlyColored,
                                     Graph &graph, int &currentNode) {

  set<int> neighbours = graph.adjList[currentNode];

  set<int> neighboursColor;
  unordered_map<int, int>::const_iterator it;

  for (const int &neighbour : neighbours) {
    it = currentlyColored.find(neighbour);
    if (it != currentlyColored.end()) {
      neighboursColor.insert(it->second);
    }
  }

  int colorCode = 0;
  set<int>::const_iterator setIterator;

  // Increase the color code until we find a color which the neighbours does not
  // use
  while (true) {
    setIterator = neighboursColor.find(colorCode);
    if (setIterator == neighboursColor.end()) {
      break;
    }
    colorCode++;
  }

  return colorCode;
}

void GraphColoring::backtrack(Graph &graph,
                              unordered_map<int, int> &currentlyColored,
                              int currentNode) {
  // Get all possible colors for this node.
  int newColor = getAvailableColor(currentlyColored, graph, currentNode);

  // assign the color to the current vertex
  currentlyColored[currentNode] = newColor;

  // If colored all the nodes, then we are done!
  if (currentlyColored.size() == graph.numberOfNodes()) {
    return;
  }

  unordered_map<int, int>::const_iterator it;
  for (const auto &neighbour : graph.adjList[currentNode]) {
    it = currentlyColored.find(neighbour);
    // If already colored the neighbouring node, dont go there
    if (it != currentlyColored.end()) {
      continue;
    }
    backtrack(graph, currentlyColored, neighbour);
  }
}

unordered_map<int, int> GraphColoring::color(Graph graph) {
  int startingNode = 1;

  unordered_map<int, int> currentlyColored;
  backtrack(graph, currentlyColored, startingNode);

  return currentlyColored;
}

unordered_map<int, set<int>> GraphColoring::kPartite(Graph &graph) {
  int startingNode = 1;
  unordered_map<int, int> currentlyColored;

  backtrack(graph, currentlyColored, startingNode);

  unordered_map<int, set<int>> kPartite;
  for (auto &it : currentlyColored) {
    kPartite[it.second].insert(it.first);
  }

  return kPartite;
}

// Get minimin number of colors needed to color the graph
int GraphColoring::minColor(Graph &graph) {
  return GraphColoring::kPartite(graph).size();
}

// int main() {
// Graph graph();
// graph.addEdge(1, 2);
// graph.addEdge(3, 2);
// graph.addEdge(3, 4);
// graph.addEdge(1, 4);
//
// Minim number need to colors this graph is 2
// cout << "Min color: " << GraphColoring:minColor(graph) << endl;
// cout << "\n \n";
//
// Split the graph into k partition
// unordered_map<int, set<int>> kPartition = kPartite(graph);
//
// for (auto &it : kPartition) {
// cout << "Partition " << it.first << ": ";
// for (const int &vertex : it.second) {
// cout << vertex << ", ";
// }
// cout << "\n";
// }
// cout << "\n \n";
//
// unordered_map<int, int> nodesColored = color(graph);
// for (auto vertex : nodesColored) {
// cout << "Vertex " << vertex.first << ":" << vertex.second << endl;
// }
//
// return 0;
// }
