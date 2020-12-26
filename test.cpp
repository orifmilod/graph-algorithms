#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
#define print(x) cout << x << endl

int main() {
  set<string> a = {"a", "b"};
  set<string> b = a;
  a.erase("a");

  for (auto &item : b) {
    cout << item << endl;
  }

  for (auto &item : a) {
    cout << item << endl;
  }

  return 0;
}
