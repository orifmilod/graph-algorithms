#include <gtest/gtest.h>
#include <iostream>

#include "include/Graph.h"
#include "include/GraphColoring.h"

using namespace std;

TEST(GraphColoring, ColorCardinality) {
  Graph graph(false);
  graph.addEdge(1, 2);
  graph.addEdge(3, 2);
  graph.addEdge(3, 4);
  graph.addEdge(1, 4);
  GraphColoring graphColoring;
  EXPECT_EQ(0, 0);
  // int minColorNeeded = graphColoring.
}

int main() {
  ::testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}
