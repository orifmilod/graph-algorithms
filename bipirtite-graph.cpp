#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
#define print(x) cout << x << endl

bool isBipartite(vector<vector<int>> &graph) {
  if (graph.empty()) {
    return true;
  }

  queue<int> q;
  vector<int> colors(graph.size(), -1);
  vector<bool> checkedNodes(graph.size(), false);

  for (int j = 0; j < checkedNodes.size(); j++) {
    if (!checkedNodes[j]) {
      colors[j] = 1;
      q.push(j);
      checkedNodes[j] = true;

      while (!q.empty()) {
        int item = q.front();
        checkedNodes[item] = true;
        q.pop();

        for (int i = 0; i < graph[item].size(); i++) {
          int a = graph[item][i];
          if (colors[a] == -1) { // never visited before
            q.push(a);
            colors[a] =
                1 - colors[item]; // change the color to the opposite color.
          } else {
            if (colors[a] == colors[item]) {
              return false;
            }
          }
        }
      }
    }
  }

  return true;
}

int main() {
  vector<vector<int>> a{{1, 3}, {0, 2}, {1, 3}, {0, 2}};
  vector<vector<int>> b{{1, 2, 3}, {0, 2}, {0, 1, 3}, {0, 2}};
  vector<vector<int>> c{{},
                        {2, 4, 6},
                        {1, 4, 8, 9},
                        {7, 8},
                        {1, 2, 8, 9},
                        {6, 9},
                        {1, 5, 7, 8, 9},
                        {3, 6, 9},
                        {2, 3, 4, 6, 9},
                        {2, 4, 5, 6, 7, 8}};

  cout << isBipartite(a) << endl; // true
  cout << isBipartite(b) << endl; // false
  cout << isBipartite(c) << endl; // multi component graph, false
  return 0;
}


