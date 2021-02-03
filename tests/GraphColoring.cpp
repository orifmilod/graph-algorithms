#include <gtest/gtest.h>
#include <iostream>

#include "Graph.h"
#include "GraphColoring.h"

using namespace std;

TEST(GraphColoring, color_cardinality) {
  Graph graph(false);
  graph.addEdge(1, 2);
  graph.addEdge(3, 2);
  graph.addEdge(3, 4);
  graph.addEdge(1, 4);
  GraphColoring graphColoring;
  int minColorNeeded = graphColoring.
}

int main() {
  testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}
