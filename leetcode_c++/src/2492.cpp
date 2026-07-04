#include <algorithm>
#include <climits>
#include <iostream>
#include <iterator>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  int minScore(int n, vector<vector<int>> &roads) {
    unordered_map<int, vector<pair<int, int>>> map;
    for (auto &road : roads) {
      int start = road[0];
      int end = road[1];
      int value = road[2];
      map[start].push_back({end, value});
      map[end].push_back({start, value});
    }
    int min_v = INT_MAX;
    vector<int> vis(n + 1);
    auto dfs = [&](this auto &&dfs, int i) -> void {
      vis[i] = 1;
      for (auto &val : map[i]) {
        min_v = min(val.second, min_v);
        if (vis[val.first] == 0) {
          dfs(val.first);
        }
      }
    };
    dfs(1);
    return min_v;
  }
};
int main() {
  Solution s;
  cout << "" << "\n";
  return 0;
}
