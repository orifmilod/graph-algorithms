#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
#define print(x) cout << x << endl

int main() {
  set<int> a = {1, 2, 3, 4};

  for (const auto &item : a) {
    cout << item << endl;
  }
  return 0;
}
