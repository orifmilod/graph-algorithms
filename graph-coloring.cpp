#include "./Graph.cpp"
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// Get minimum number of colors to color the graph

// Get all the possible graph coloring

void backtrack(vector<unordered_map<int, string>> &allPossibilities,
               unordered_map<int, string> current, set<string> &allColors,
               Graph &graph, int currentNode,
               unordered_map<int, bool> &visited) {

  if (visited.find(currentNode) != visited.end()) {
    // Already visited this node
    return;
  }

  if (current.size() == graph.numberOfNodes()) {
    allPossibilities.push_back(current);
    return;
  }

  // Get all possible colors for this node.
    // Check if any color is left, maybe not enough colors
  }
}

vector<unordered_map<int, string>> possibleGraphColors(set<string> &allColors,
                                                       Graph graph) {

  vector<unordered_map<int, string>> allPossibilities;
  unordered_map<int, string> currentColors;
  unordered_map<int, bool> visited;

  for (auto &it : graph.adjList) {
    if (visited.find(it.first) == visited.end()) {
      backtrack(allPossibilities, currentColors, allColors, graph, it.first);
    }
  }

  cout << allPossibilities.size() << endl;
  for (int i = 0; i < allPossibilities.size(); i++) {
    for (auto &item : allPossibilities[i]) {
      cout << item.first << ":" << item.second << ", ";
    }
    cout << "\n";
  }

  return allPossibilities;
}

int main() {
  Graph graph(false);
  // graph.addEdge(1, 2);
  // set<string> colors = {"R", "B", "G"};

  graph.addEdge(1, 2);
  graph.addEdge(3, 2);
  graph.addEdge(3, 4);
  graph.addEdge(1, 4);
  // graph.printAllEdges();

  set<string> colors = {"B", "R", "G"};

  possibleGraphColors(colors, graph);

  return 0;
}
